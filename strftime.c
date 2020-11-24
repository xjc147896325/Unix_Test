/*
umask stat(unistd) lstat(unistd) futtimens
*/
#include <sys/stat.h>
#include <sys/types.h>

//#include <sys/termios.h>
//#include <sys/wait.h>

/* 
 * getpwent(sys/types) setpwent(sys/types) endpwent(sys/types)
 */
#include <pwd.h>

/* 
 * 
 */
//#include <stddef.h>

/*
sleep chdir getcwd getwd get_current_dir_name
*/
#include <unistd.h>

/*

*/
#include <dirent.h>

#include <errno.h>

/*

*/
#include <limits.h>

/*
open write read unlink
*/
#include <fcntl.h>
//#include <signal.h>

/* 
 * stdin stdout stderr sprintf printf puts gets putschar getchar fopen
 * fdopen freopen fgetc getc fgets gets getchar ungetc tmpfile tmpnam
 * fseek ftell rewind fgetpos fsetpos fmemopen
*/
#include <stdio.h>

/* 
 * exit realloc mkdtemp mkstemp mkostemp mkstemps mkostemps

 */
#include <stdlib.h>

//#include <stddef.h>

/* 
 * strlen strcpy memset strcmp strncmp
 */
#include <string.h>

/* 
 * asctime asctime_r ctime ctime_r gmtime gmtime_r localtime localtime_r mktime
 */
#include <time.h>

/* user own */
#include "path_alloc.h"
#include "getpwnam.h"


int main(void)
{
	time_t t;
	struct tm *tmp;
	char buf1[16];
	char buf2[64];
	
	time(&t);
	tmp = localtime(&t);
	if(strftime(buf1, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0)
	{
		printf("buffer length 16 is too small\n");
	}
	else
	{
		printf("%s\n", buf1);
	}
	if(strftime(buf2, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0)
	{
		printf("buffer length 64 is too small\n");
	}
	else
	{
		printf("%s\n", buf2);
	}
	
	return(0);
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc memory_stream.c -o memory_stream
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./memory_stream
inital buffer contents: 
before flush: 
after flush: hello, world
len of string in buf = 12
after flush: bbbbbbbbbbbbhello, world
len of string in buf = 24
after flush: hello, worldcccccccccccccccccccccccccccccccccc
len of string in buf = 46


*/

/* 

当注释掉fflush时：
root@jOKERII:/home/topeet/UNIX_test# ./memory_stream
inital buffer contents: 
before flush: 
after flush: 
len of string in buf = 0
after flush: hello, worldhello, world
len of string in buf = 24
after flush: hello, worldcccccccccccccccccccccccccccccccccc
len of string in buf = 46



（只有当移动或啥的处理fp时，才会把缓冲更新进流
 */
