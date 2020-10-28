//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
#include <string.h>


int main (int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	
	errno = ENOENT;
	
	perror(argv[0]);
	
	exit(0);
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc -o err err.c 

*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./err
EACCES: Permission denied
./err: No such file or directory



*/


