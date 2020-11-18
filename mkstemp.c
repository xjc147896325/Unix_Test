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

/* 
 * exit realloc mkdtemp mkstemp mkostemp mkstemps mkostemps

 */
#include <stdlib.h>

//#include <stddef.h>

/* strlen strcpy */
#include <string.h>

/* user own */
#include "path_alloc.h"

void make_temp(char *template);

int main(void)
{
	char 	good_template[] = "/temp/dirXXXXXX";  /* right way */
	char 	*bad_template   = "temp/dirXXXXXX";   /* wrong way */
	
	printf("trying to create first temp file...\n");
	make_temp(good_template);
	printf("trying to create second temp file...\n");
	make_temp(bad_template);
	
	exit(0);
}

void make_temp(char *template)
{
	int 			fd;
	struct stat 	sbuf;
	
	if((fd = mkstemp(template)) < 0)
	{
		fprintf(stderr, "can't create temp file");
	}
	printf("temp name = %s\n", template);
	close(fd);
	if(stat(template, &sbuf) < 0)
	{
		if(errno == ENOENT)
		{
			printf("file doesn't exits\n");
		}
		else 
		{
			fprintf(stderr, "stat failed");
		}
	}
	else
	{
		printf("file exits\n");
		unlink(template);
	}
	
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc mkstemp.c -o mkstemp
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./mkstemp
trying to create first temp file...
can't create temp filetemp name = /temp/dirF4tjFs
file doesn't exits
trying to create second temp file...
Segmentation fault (core dumped)


*/


