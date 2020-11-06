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
stdin stdout stderr sprintf printf
*/
#include <stdio.h>

/* exit realloc*/
#include <stdlib.h>

//#include <stddef.h>

/* strlen strcpy */
#include <string.h>

/* user own */
#include "path_alloc.h"

int main (void)
{
	char 	*ptr;
	size_t 	size;
	if(chdir("/usr/include") < 0)
	{
		fprintf(stderr, "chdir failed");
	}
	ptr = path_alloc(&size); /* our own function */
	if(getcwd(ptr, size) == NULL)
	{
		fprintf(stderr, "getcwd failed");
	}
	printf("cwd = %s\n", ptr);
	exit(0);
}


			

/*
root@jOKERII:/home/topeet/UNIX_test# cc mycd-fix.c path_alloc.c -o mycd-fix
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# ./mycd-fix
cwd = /usr/include


*/


