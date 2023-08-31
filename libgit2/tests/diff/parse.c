	git_buf_dispose(&buf);
void test_diff_parse__empty_file(void)
{
	const char *content =
	    "---\n"
	    " file | 0\n"
	    " 1 file changed, 0 insertions(+), 0 deletions(-)\n"
	    " created mode 100644 file\n"
	    "\n"
	    "diff --git a/file b/file\n"
	    "new file mode 100644\n"
	    "index 0000000..e69de29\n"
	    "-- \n"
	    "2.20.1\n";
	git_diff *diff;

	cl_git_pass(git_diff_from_buffer(
		&diff, content, strlen(content)));
	git_diff_free(diff);
}

void test_diff_parse__no_extended_headers(void)
{
	const char *content = PATCH_NO_EXTENDED_HEADERS;
	git_diff *diff;

	cl_git_pass(git_diff_from_buffer(
		&diff, content, strlen(content)));
	git_diff_free(diff);
}

void test_diff_parse__add_delete_no_index(void)
{
	const char *content =
	    "diff --git a/file.txt b/file.txt\n"
	    "new file mode 100644\n"
	    "--- /dev/null\n"
	    "+++ b/file.txt\n"
	    "@@ -0,0 +1,2 @@\n"
	    "+one\n"
	    "+two\n"
	    "diff --git a/otherfile.txt b/otherfile.txt\n"
	    "deleted file mode 100644\n"
	    "--- a/otherfile.txt\n"
	    "+++ /dev/null\n"
	    "@@ -1,1 +0,0 @@\n"
	    "-three\n";
	git_diff *diff;

	cl_git_pass(git_diff_from_buffer(
		&diff, content, strlen(content)));
	git_diff_free(diff);
}

	git_buf_dispose(&computed_buf);
	git_buf_dispose(&computed_buf);
	git_buf_dispose(&buf);
	git_buf_dispose(&patchbuf);
	git_buf_dispose(&diffbuf);
#define cl_assert_equal_i_src(i1,i2,file,func,line) clar__assert_equal(file,func,line,#i1 " != " #i2, 1, "%d", (int)(i1), (int)(i2))
static void cl_git_assert_lineinfo_(int old_lineno, int new_lineno, int num_lines, git_patch *patch, size_t hunk_idx, size_t line_idx, const char *file, const char *func, int lineno)
	cl_git_expect(git_patch_get_line_in_hunk(&line, patch, hunk_idx, line_idx), 0, file, func, lineno);
	cl_assert_equal_i_src(old_lineno, line->old_lineno, file, func, lineno);
	cl_assert_equal_i_src(new_lineno, line->new_lineno, file, func, lineno);
	cl_assert_equal_i_src(num_lines, line->num_lines, file, func, lineno);
	cl_git_assert_lineinfo_(old,new,num,p,h,l,__FILE__,__func__,__LINE__)


void test_diff_parse__new_file_with_space(void)
{
	const char *content = PATCH_ORIGINAL_NEW_FILE_WITH_SPACE;
	git_patch *patch;
	git_diff *diff;

	cl_git_pass(git_diff_from_buffer(&diff, content, strlen(content)));
	cl_git_pass(git_patch_from_diff((git_patch **) &patch, diff, 0));

	cl_assert_equal_p(patch->diff_opts.old_prefix, NULL);
	cl_assert_equal_p(patch->delta->old_file.path, NULL);
	cl_assert_equal_s(patch->diff_opts.new_prefix, "b/");
	cl_assert_equal_s(patch->delta->new_file.path, "sp ace.txt");

	git_patch_free(patch);
	git_diff_free(diff);
}

void test_diff_parse__crlf(void)
{
	const char *text = PATCH_CRLF;
	git_diff *diff;
	git_patch *patch;
	const git_diff_delta *delta;

	cl_git_pass(git_diff_from_buffer(&diff, text, strlen(text)));
	cl_git_pass(git_patch_from_diff(&patch, diff, 0));
	delta = git_patch_get_delta(patch);

	cl_assert_equal_s(delta->old_file.path, "test-file");
	cl_assert_equal_s(delta->new_file.path, "test-file");

	git_patch_free(patch);
	git_diff_free(diff);
}