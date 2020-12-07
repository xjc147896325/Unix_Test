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
#include <setimp.h>
 
/* user own */
#include "path_alloc.h"
#include "getpwnam.h"

#define TOK_ADD 		5
#define MAXLINE 		20


static void 	f1(int, int, int, int);
static void 	f2(void);


static jmp_buf 	jmpbuffer;
static int		globval;


int main(void)
{
	int 			autoval;
	register int	regival;
	volatie	 int 	volaval;
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
		
	}
	
	
	exit(0);
}

char *tok_ptr;  			/* global pointer for get_token() */

void do_line(char *ptr)		/* process one line of input */
{
	int 	cmd;
	
	tok_ptr = ptr;
	while((cmd = get_token()) > 0)
	{
		switch(cmd)			/* one case for each command */
		{
			case(TOK_ADD):
			{
				cmd_add();
				break;
			}
		}
	}
}


void cmd_add(void)
{
	int 	token;
	
	token = get_token();
	if(token < 0)			/* an err has occurred */
	{
		longjmp(jmpbuffer, 1);
	}
	/* rest of processing for this command */
}

int get_token(void)
{
	/* fetch next token from line pointed to by tok_ptr */
}

/*
未完成
*/


