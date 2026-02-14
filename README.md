goddamn, this was TLTR, but i did.

so, makefile explained:

Makefile syntax:
VAR_NAME = filename1 filename 2 (...)
TARGET = PREREQUISITES
[tab] Recipe

$< 
refers to first prerequisite
$@
refers to target/rule/phony

cc (https://www.unix.com/man_page/v7/1/cc/)
-c 
Suppress the loading phase of the compilation, and force an object file to be produced even if only one program is compiled.

-o
Name the final output file output.  If this option is used the file `a.out' will be left undisturbed.

-I (-Idir)
'#include' files whose names do not begin with `/' are always sought first in the directory of the file argument, 
then in directories named in -I options, then in directories on a standard list.


ar [--options] mylib.a member_files
-r
Write an object-file index into the archive, or update an existing one, even if no other change is made to the archive.
You may use this modifier flag either with any operation, or alone.  
Running ar s on an archive is equivalent to running ranlib on it.

-c
Create the archive.  The specified archive is always created if it did not exist, when you request an update.
But a warning is issued unless you specify in advance that you expect to create it, by using this modifier.

-s
Add an index to the archive, or update it if it already exists.  
Note this command is an exception to the rule that there can only be one command letter, 
as it is possible to use it as either a command or a modifier.  
In either case it does the same thing.


.PHONY: all clean fclean re
In this example, the clean target will not work properly if a file named clean is ever
created in this directory. Since it has no prerequisites, clean would always be considered
up to date and its recipe would not be executed. To avoid this problem you can explicitly
declare the target to be phony by making it a prerequisite of the special target

after our library is created, and to create a program including it, we use the following cmd to compile it
cc filename.c -L. libft.a -o prog_name

of course, on the filename.c you must make sure to include the header file that contains refence for all ft prototypes in our library

some helpful sources to investigate:
https://www.geeksforgeeks.org/c/how-do-i-create-a-library-in-c/
https://makefiletutorial.com/
https://opensource.com/article/18/8/what-how-makefile
https://www.gnu.org/software/make/manual/make.pdf
https://swarnakar-ani24.medium.com/a-noobs-guide-to-using-make-and-writing-makefile-f718135d816b
https://www.geeksforgeeks.org/c/multiple-source-files-in-c/
https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
https://www.unix.com/man_page/v7/1/cc/
https://www.geeksforgeeks.org/linux-unix/ar-command-in-linux-with-examples/
