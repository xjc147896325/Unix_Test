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


static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	if(atexit(my_exit2) != 0)
	{
		fprintf(stderr, "can't register my_exit2");
	}
	if(atexit(my_exit1) != 0)
	{
		fprintf(stderr, "can't register my_exit1");
	}
	if(atexit(my_exit1) != 0)
	{
		fprintf(stderr, "can't register my_exit1");
	}
	
	printf("main is done\n");
	return(0);
}


static void my_exit1(void)
{
	printf("first exit handler\n");
}
	
static void my_exit2(void)
{
	printf("second exit handler\n");
}

/*
root@jOKERII:/home/topeet/UNIX_test# gcc atexit.c -o atexit
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./atexit
main is done
first exit handler
first exit handler
second exit handler

*/

