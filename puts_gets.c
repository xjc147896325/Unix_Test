//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
//#include <errno.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>


int main (void)
{
	int 	c;
	
	while((c = getc(stdin)) != EOF)
	{
		if(putc(c, stdout) == EOF)
		{
			fprintf(stderr,"output err\n");
		}
	}
	
	if(ferror(stdin))
	{
		fprintf(stderr,"input err\n");
	}
	
	exit(0);
}

/*
cc -o puts_gets puts_gets.c
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./puts_gets < a > b

root@jOKERII:/home/topeet/UNIX_test# ./puts_gets < a
sss
aaa
ddd
gun
root@jOKERII:/home/topeet/UNIX_test# ./puts_gets < b
sss
aaa
ddd
gun

*/


