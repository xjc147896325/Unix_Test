//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
#include <errno.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>

#define BUFFSIZE 4096

int main (void)
{
	int 	n;
	char 	buf[BUFFSIZE];
	
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if(write(STDOUT_FILENO, buf, n) != n)
		{
			fprintf(stderr,"write err\n");
		}
	}
	
	if(n < 0)
	{
		fprintf(stderr,"read err\n");
	}
	exit(0);
}

/*
cc -o stdin_out stdin_out.c
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./stdin_out
ls
ls
ccc
ccc
^C

*/



/* 
root@jOKERII:/home/topeet/UNIX_test# ./stdin_out > a
sss
aaa
ddd
gun
^C

root@jOKERII:/home/topeet/UNIX_test# ./stdin_out < a
sss
aaa
ddd
gun

*/

/*
root@jOKERII:/home/topeet/UNIX_test# ./stdin_out < a > out




*/