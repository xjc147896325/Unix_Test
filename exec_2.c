//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
#include <string.h>

#define MAXLINE 1024

static void sig_int(int);

int main (void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;
	
	if(signal(SIGINT, sig_int) == SIG_ERR)
	{
		fprintf(stderr,"signal err");
	}
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

void sig_int(int signo)
{
	printf("interrupt\n%%");
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc -o exec_2 exec_2.c 
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./exec_2
% 
ds
couldn't execute: ds
^Cinterrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^C%interrupt
^Z
[1]+  Stopped                 ./exec_2



*/


