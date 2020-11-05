/*
umask stat(unistd) lstat(unistd) futtimens
*/
#include <sys/stat.h>
#include <sys/types.h>


//#include <sys/termios.h>
//#include <sys/wait.h>

/*
sleep
*/
#include <unistd.h>

//#include <dirent.h>
#include <errno.h>

/*
open write read unlink
*/
#include <fcntl.h>
//#include <signal.h>

/* 
stdin stdout stderr sprintf printf
*/
#include <stdio.h>

/* exit */
#include <stdlib.h>

//#include <stddef.h>
//#include <string.h>



int main (int argc, char *argv[])
{
	int				i, fd;
	struct stat 	statbuf;
	struct timespec	times[2];
	
	for(i = 1; i < argc; i++)
	{
		if(stat(argv[i], &statbuf) < 0)
		{
			/* fetch current times */
			fprintf(stderr, "%s: stat err", argv[i]);
			continue;
		}
		
		if((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
		{
			/* truncate - 截断*/
			fprintf(stderr, "%s: open err", argv[i]);
			continue;
		}
		
		times[0] = statbuf.st_atim;
		times[1] = statbuf.st_mtim;
		
		if(futimens(fd, times) < 0)
		{
			/* resrt times */
			fprintf(stderr, "%s: futimens error", argv[i]);
		}
		close(fd);
	}
	
	exit(0);
}




/*
root@jOKERII:/home/topeet/UNIX_test# cc futimens.c -o futimens
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# ls -l changemod times
-rw-r--r-- 1 root root 0 Nov  5 00:48 changemod
-rw-r--r-- 1 root root 0 Nov  5 00:49 times
root@jOKERII:/home/topeet/UNIX_test# ls -lu changemod times
-rw-r--r-- 1 root root 0 Nov  5 00:48 changemod
-rw-r--r-- 1 root root 0 Nov  5 00:49 times
root@jOKERII:/home/topeet/UNIX_test# date
Thu Nov  5 00:54:20 PST 2020
root@jOKERII:/home/topeet/UNIX_test# ./futimens changemod  times 
root@jOKERII:/home/topeet/UNIX_test# ls -l changemod times
-rw-r--r-- 1 root root 0 Nov  5 00:48 changemod
-rw-r--r-- 1 root root 0 Nov  5 00:49 times
root@jOKERII:/home/topeet/UNIX_test# ls -lu changemod times
-rw-r--r-- 1 root root 0 Nov  5 00:48 changemod
-rw-r--r-- 1 root root 0 Nov  5 00:49 times
root@jOKERII:/home/topeet/UNIX_test# ls -lc changemod times
-rw-r--r-- 1 root root 0 Nov  5 00:54 changemod
-rw-r--r-- 1 root root 0 Nov  5 00:54 times



*/


