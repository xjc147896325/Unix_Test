/*
umask stat(unistd) lstat(unistd) futtimens
*/
#include <sys/stat.h>
#include <sys/types.h>

//#include <sys/termios.h>
//#include <sys/wait.h>

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
 * fseek ftell rewind fgetpos fsetpos
*/
#include <stdio.h>

/* exit realloc*/
#include <stdlib.h>

//#include <stddef.h>

/* strlen strcpy */
#include <string.h>

/* user own */
#include "path_alloc.h"

#define MAXLINE 1024

int main(void)
{
	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;
	
	printf("%s\n", tmpnam(NULL));               /* first temp name */
	
	tmpnam(name);                               /* second temp name */
	printf("%s\n", name);
	
	if((fp = tmpfile()) == NULL)                /* create temp file */
	{
		fprintf(stderr, "tmpfile err");
	}
	fputs("one line of outputs\n", fp);         /* write to temp file */
	rewind(fp);                                 /* then read it back */
	if(fgets(line, sizeof(line), fp) == NULL)
	{
		fprintf(stderr, "fgets err");
	}
	fputs(line, stdout);                        /* printf the line we wrote */
	
	exit(0);
}


/*
root@jOKERII:/home/topeet/UNIX_test# gcc tmpfile.c -o tmpfile
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./tmpfile
/tmp/fileJ6SveE
/tmp/fileql2Gt0
one line of outputs

*/


