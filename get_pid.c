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
	fprintf(stdout,"process id is %ld\n",(long)getpid());
	
	exit(0);
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc -o get_pid get_pid.c 
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./get_pid
process id is 2834
root@jOKERII:/home/topeet/UNIX_test# ./get_pid > c
root@jOKERII:/home/topeet/UNIX_test# ls
a  c        get_pid.c  myls.c  puts_gets    stdin_out
b  get_pid  myls       out     puts_gets.c  stdin_out.c
root@jOKERII:/home/topeet/UNIX_test# vim c


*/


