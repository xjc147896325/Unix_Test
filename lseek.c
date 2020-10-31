//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
#include <errno.h>
//#include <sys/wait.h>
#include <unistd.h>

//#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>

#define MAXLINE 1024


int main (void)
{
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
	{
		fprintf(stderr, "can't seek\n"); //stderr 是FILE * STNDERR_FILENO是int
	}
	else
	{
		fprintf(stdout, "Seek OK\n");
	}
	
	
	exit(0);
}


/*
root@jOKERII:/home/topeet/UNIX_test# cc lseek.c -o lseek
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./lseek
can't seek
root@jOKERII:/home/topeet/UNIX_test# ./lseek <a
Seek OK
root@jOKERII:/home/topeet/UNIX_test# ./lseek < /var/spool/cron/atjobs/.SEQ 
Seek OK




*/


