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


void 	do_line(char *);
void 	cmd_add(void);
void 	get_token(void);


jmp_buf jmpbuffer;


int main(void)
{
	char 	line[MAXLINE];
	
	if(setjmp(jmpbuffer) != 0)
	{
		printf("error");
	}
	while(fgets(line, MAXLINE, stdin) != NULL)
	{
		do_line(line);
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
仅为调试的框架使用
*/


