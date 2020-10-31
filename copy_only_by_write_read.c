//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <sys/wait.h>

//#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
//#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>

#define BUFFSIZE 4096

int main (void)
{
	int  n;
	char buf[BUFFSIZE];
	
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if(write(STDOUT_FILENO, buf, n) != n)
		{
			fprintf(stderr,"write err");
		}
	}
	
	if(n < 0)
	{
		fprintf(stderr,"read err");
	}
	exit(0);
}


/*
root@jOKERII:/home/topeet/UNIX_test# cc file_hole.c -o file_hole
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./copy_only_by_write_read <asss
aaa
ddd
gun



*/

/*
root@jOKERII:/home/topeet/UNIX_test# od -c a
0000000   s   s   s  \n   a   a   a  \n   d   d   d  \n   g   u   n  \n
0000020
root@jOKERII:/home/topeet/UNIX_test# od -c e
0000000   s   s   s  \n   a   a   a  \n   d   d   d  \n   g   u   n  \n
0000020
*/

/*
root@jOKERII:/home/topeet/UNIX_test# ./copy_only_by_write_read 
dsa
dsa


dffadssdadsadasdsas
dffadssdadsadasdsas

*/

