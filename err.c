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
	fprintf(stderr, ""EACCES: %s\n", strerror(EACCES));
	
	errno = ENOENT;
	
	perror(argv[0]);
	
	exit(0);
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc -o exec_1 exec_1.c 

*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./exec_1
% root@jOKERII:/home/topeet/UNIX_test# ./exec_1
% ls
a  c	   exec_1.c  get_pid.c	myls.c	puts_gets    stdin_out
b  exec_1  get_pid   myls	out	puts_gets.c  stdin_out.c
date
Mon Oct 26 20:12:40 PDT 2020
./myls
usage: ls directory_name./get_pid
process id is 2841
ls
a  c	   exec_1.c  get_pid.c	myls.c	puts_gets    stdin_out
b  exec_1  get_pid   myls	out	puts_gets.c  stdin_out.c
pwd
/home/topeet/UNIX_test
who
topeet   tty7         2020-10-26 19:50
topeet   pts/1        2020-10-26 19:58 (:0.0)
root@jOKERII:/home/topeet/UNIX_test# 


*/


