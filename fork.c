/*
umask stat(unistd) lstat(unistd) futtimens
*/
#include <sys/stat.h>
#include <sys/types.h>

/* 
 * getrlimit setrlimit prlimt <time/resource>
 
 */
#include <sys/resource.h>

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
 * stdin stdout stderr sprintf printf puts gets putchar getchar fopen
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
#include <sys/time.h>

/* 
 * setjmp 
 */
#include <setjmp.h>
 
/* user own */
#include "path_alloc.h"
#include "getpwnam.h"

int 	globvar = 6; 		/* external variable in initialized data */
char 	buf[] = "a write to stdout\n";

int main(void)
{
	int 	var;	/* automatic variable on the stack */
	pid_t 	pid;
	
	var = 88;
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
	{
		fprintf(stderr, "write err");
	}
	
	printf("before fork\n"); 	/* we don't flush stdout */
	
	if((pid = fork()) < 0)
	{
		fprintf(stderr, "fork err");
	}
	else 
	{
		if(pid == 0)			/* child  */
		{
			globvar++;			/* modify variable */
			var++;
		}
		else
		{
			sleep(2);			/* parent */
		}
	}
	
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	exit(0);
}


/*
root@jOKERII:/home/topeet/UNIX_test# ./fork
a write to stdout
before fork
pid = 2744, glob = 7, var = 89
pid = 2743, glob = 6, var = 88
root@jOKERII:/home/topeet/UNIX_test# ./fork > temp.out
root@jOKERII:/home/topeet/UNIX_test# cat temp.out 
a write to stdout
before fork
pid = 2746, glob = 7, var = 89
before fork
pid = 2745, glob = 6, var = 88


*/


