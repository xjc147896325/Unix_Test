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

#define MAXLINE 1024

int main (void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;
	
	fprintf(stdout, "%% \n");
	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) - 1] = 0;
		}
		if((pid = fork()) < 0)
		{
			fprintf(stderr,"fork err\n");
		}
		else
		{
			if(pid == 0)
			{
				execlp(buf, buf, (char *)0);
				fprintf(stderr,"couldn't execute: %s\n", buf);
				exit(127);
			}
		}
		
		if((pid = waitpid(pid, &status, 0)) < 0)
		{
			fprintf(stderr,"waitpid err\n");
			fprintf(stdout, "%% \n");
		}
	}
	
	
	
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


