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
root@jOKERII:/home/topeet/UNIX_test# cc strftime.c -o strftime
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./strftime
buffer length 16 is too smalltime and date: 06:19:33 PM, Sat Nov 28, 2020


*/

