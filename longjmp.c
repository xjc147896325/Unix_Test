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

/* 
 * setjmp 
 */
#include <setjmp.h>
 
/* user own */
#include "path_alloc.h"
#include "getpwnam.h"


static void 	f1(int, int, int, int);
static void 	f2(void);


static jmp_buf 	jmpbuffer;
static int		globval;


int main(void)
{
	int 			autoval;
	register int	regival;
	volatile int 	volaval;
	static 	 int 	statval;
	
	globval = 1;
	autoval = 2;
	regival = 3;
	volaval = 4;
	statval = 5;
	
	if(setjmp(jmpbuffer) != 0)
	{
		printf("after longjmp:\n");
		printf("globval = %d, autoval = %d, regival = %d, volaval = %d, statval = %d\n", globval, autoval, regival, volaval, statval);
		exit(0);
	}
	/* 
	 * Change variables after setjmp, but before longjmp.
	 */
	globval = 95;
	autoval = 96;
	regival = 97;
	volaval = 98;
	statval = 99;
	
	f1(autoval, regival, volaval, statval); /* never returns  */
	exit(0);
}

static void f1(int i, int j, int k, int l)
{
	printf("in f1():\n");
	printf("globval = %d, autoval = %d, regival = %d, volaval = %d, statval = %d\n", globval, i, j, k, l);
	f2();
	
}

static void f2(void)
{
	longjmp(jmpbuffer, 1);
}



/*
root@jOKERII:/home/topeet/UNIX_test# gcc longjmp.c -o longjmp
root@jOKERII:/home/topeet/UNIX_test# ./longjmp
in f1():
globval = 95, autoval = 96, regival = 97, volaval = 98, statval = 99
after longjmp:
globval = 95, autoval = 96, regival = 97, volaval = 98, statval = 99
root@jOKERII:/home/topeet/UNIX_test# gcc longjmp.c -o longjmp -O
root@jOKERII:/home/topeet/UNIX_test# ./longjmp
in f1():
globval = 95, autoval = 96, regival = 97, volaval = 98, statval = 99
after longjmp:
globval = 95, autoval = 2, regival = 3, volaval = 98, statval = 99

*/


