/* An insertion at the beginning of the file and change in the middle */

#define FILE_PREPEND_AND_CHANGE \
	"insert at front\n" \
	"hey!\n" \
	"this is some context!\n" \
	"around some lines\n" \
	"that will change\n" \
	"yes it is!\n" \
	"(THIS line is changed!)\n" \
	"and this\n" \
	"is additional context\n" \
	"below it!\n"

#define PATCH_ORIGINAL_TO_PREPEND_AND_CHANGE \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..f73c8bb 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -1,9 +1,10 @@\n" \
	"+insert at front\n" \
	" hey!\n" \
	" this is some context!\n" \
	" around some lines\n" \
	" that will change\n" \
	" yes it is!\n" \
	"-(this line is changed)\n" \
	"+(THIS line is changed!)\n" \
	" and this\n" \
	" is additional context\n" \
	" below it!\n"

#define PATCH_ORIGINAL_TO_PREPEND_AND_CHANGE_NOCONTEXT \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..f73c8bb 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -0,0 +1 @@\n" \
	"+insert at front\n" \
	"@@ -6 +7 @@ yes it is!\n" \
	"-(this line is changed)\n" \
	"+(THIS line is changed!)\n"

/* A change in the middle and a deletion of the newline at the end of the file */

#define FILE_CHANGE_MIDDLE_AND_LASTLINE \
	"hey!\n" \
	"this is some context!\n" \
	"around some lines\n" \
	"that will change\n" \
	"yes it is!\n" \
	"(THIS line is changed!)\n" \
	"and this\n" \
	"is additional context\n" \
	"BELOW it! - (THIS line is changed!)"

#define PATCH_ORIGINAL_TO_CHANGE_MIDDLE_AND_LASTLINE_NOCONTEXT \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..e05d36c 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -6 +6 @@ yes it is!\n" \
	"-(this line is changed)\n" \
	"+(THIS line is changed!)\n" \
	"@@ -9 +9 @@ is additional context\n" \
	"-below it!\n" \
	"+BELOW it! - (THIS line is changed!)\n" \
	"\\ No newline at end of file\n"

/* A deletion at the beginning of the file and a change in the middle */

#define FILE_DELETE_AND_CHANGE \
	"this is some context!\n" \
	"around some lines\n" \
	"that will change\n" \
	"yes it is!\n" \
	"(THIS line is changed!)\n" \
	"and this\n" \
	"is additional context\n" \
	"below it!\n"

#define PATCH_ORIGINAL_TO_DELETE_AND_CHANGE \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..1e2dfa6 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -1,9 +1,8 @@\n" \
	"-hey!\n" \
	" this is some context!\n" \
	" around some lines\n" \
	" that will change\n" \
	" yes it is!\n" \
	"-(this line is changed)\n" \
	"+(THIS line is changed!)\n" \
	" and this\n" \
	" is additional context\n" \
	" below it!\n"

#define PATCH_ORIGINAL_TO_DELETE_AND_CHANGE_NOCONTEXT \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..1e2dfa6 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -1 +0,0 @@\n" \
	"-hey!\n" \
	"@@ -6 +5 @@ yes it is!\n" \
	"-(this line is changed)\n" \
	"+(THIS line is changed!)\n"

/* A deletion at the beginning of the file */

#define FILE_DELETE_FIRSTLINE \
	"this is some context!\n" \
	"around some lines\n" \
	"that will change\n" \
	"yes it is!\n" \
	"(this line is changed)\n" \
	"and this\n" \
	"is additional context\n" \
	"below it!\n"

#define PATCH_ORIGINAL_TO_DELETE_FIRSTLINE \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..f31fa13 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -1,4 +1,3 @@\n" \
	"-hey!\n" \
	" this is some context!\n" \
	" around some lines\n" \
	" that will change\n"

#define PATCH_DELETED_FILE_2_HUNKS \
	"diff --git a/a b/a\n" \
	"index 7f129fd..af431f2 100644\n" \
	"--- a/a\n" \
	"+++ b/a\n" \
	"@@ -1 +1 @@\n" \
	"-a contents 2\n" \
	"+a contents\n" \
	"diff --git a/c/d b/c/d\n" \
	"deleted file mode 100644\n" \
	"index 297efb8..0000000\n" \
	"--- a/c/d\n" \
	"+++ /dev/null\n" \
	"@@ -1 +0,0 @@\n" \
	"-c/d contents\n"

#define PATCH_DELETED_FILE_2_HUNKS_SHUFFLED \
	"diff --git a/c/d b/c/d\n" \
	"deleted file mode 100644\n" \
	"index 297efb8..0000000\n" \
	"--- a/c/d\n" \
	"+++ /dev/null\n" \
	"@@ -1 +0,0 @@\n" \
	"-c/d contents\n" \
	"diff --git a/a b/a\n" \
	"index 7f129fd..af431f2 100644\n" \
	"--- a/a\n" \
	"+++ b/a\n" \
	"@@ -1 +1 @@\n" \
	"-a contents 2\n" \
	"+a contents\n"

#define PATCH_RENAME_EXACT_WITH_MODE \
	"diff --git a/RENAMED.md b/README.md\n" \
	"old mode 100644\n" \
	"new mode 100755\n" \
	"similarity index 100%\n" \
	"rename from RENAMED.md\n" \
	"rename to README.md\n"

#define PATCH_APPEND_NO_NL_IN_OLD_FILE \
	"diff --git a/file.txt b/file.txt\n" \
	"index 9432026..83759c0 100644\n" \
	"--- a/file.txt\n" \
	"+++ b/file.txt\n" \
	"@@ -1,1 +1,1 @@\n" \
	"-foo\n" \
	"\\ No newline at end of file\n" \
	"+foo\n"


#define PATCH_ADD_BINARY_NOT_PRINTED \
	"diff --git a/test.bin b/test.bin\n" \
	"new file mode 100644\n" \
	"index 0000000..9e0f96a\n" \
	"Binary files /dev/null and b/test.bin differ\n"

#define PATCH_ORIGINAL_NEW_FILE_WITH_SPACE \
	"diff --git a/sp ace.txt b/sp ace.txt\n" \
	"new file mode 100644\n" \
	"index 000000000..789819226\n" \
	"--- /dev/null\n" \
	"+++ b/sp ace.txt\n" \
	"@@ -0,0 +1 @@\n" \
	"+a\n"

#define PATCH_CRLF \
	"diff --git a/test-file b/test-file\r\n" \
	"new file mode 100644\r\n" \
	"index 0000000..af431f2 100644\r\n" \
	"--- /dev/null\r\n" \
	"+++ b/test-file\r\n" \
	"@@ -0,0 +1 @@\r\n" \
	"+a contents\r\n"

#define PATCH_NO_EXTENDED_HEADERS \
	"diff --git a/file b/file\n" \
	"--- a/file\n" \
	"+++ b/file\n" \
	"@@ -1,3 +1,3 @@\n" \
	" a\n" \
	"-b\n" \
	"+bb\n" \
	" c\n"

#define PATCH_BINARY_FILE_WITH_MISSING_PATHS \
	"diff --git  \n" \
	"--- \n" \
	"+++ \n" \
	"Binary files "

#define PATCH_BINARY_FILE_WITH_WHITESPACE_PATHS \
	"diff --git a/file b/file\n" \
	"---  \n" \
	"+++  \n" \
	"Binary files "

#define PATCH_BINARY_FILE_WITH_QUOTED_EMPTY_PATHS \
	"diff --git a/file b/file\n" \
	"--- \"\"\n" \
	"+++ \"\"\n" \
	"Binary files "

#define PATCH_BINARY_FILE_PATH_WITH_SPACES \
	"diff --git a b c d e f\n" \
	"--- a b c\n" \
	"+++ d e f\n" \
	"Binary files a b c and d e f differ"

#define PATCH_BINARY_FILE_PATH_WITHOUT_BODY_PATHS \
	"diff --git a b c d e f\n" \
	"--- \n" \
	"+++ \n" \
	"Binary files a b c and d e f differ"

#define PATCH_BINARY_FILE_WITH_TRUNCATED_DELTA \
	"diff --git a/file b/file\n" \
	"index 1420..b71f\n" \
	"GIT binary patch\n" \
	"delta 7\n" \
	"d"

#define PATCH_MULTIPLE_OLD_PATHS \
	"diff --git  \n" \
	"---  \n" \
	"+++ \n" \
	"index 0000..7DDb\n" \
	"--- \n"

#define PATCH_INTMAX_NEW_LINES \
	"diff --git a/file b/file\n" \
	"--- a/file\n" \
	"+++ b/file\n" \
	"@@ -0 +2147483647 @@\n" \
	"\n" \
	"  "