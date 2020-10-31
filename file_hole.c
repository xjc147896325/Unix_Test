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

char	buf0[] = "xjc ruozhi desu,hhh";
char	buf1[] = "xjc hanhan desu,hhh";

int main (void)
{
	int fd;
	
	if((fd = open("file.hole",O_RDWR|O_CREAT|O_TRUNC, 0644)) < 0)
	{
		fprintf(stderr,"creat err");
	}
	
	if(write(fd, buf0, 15) != 15)
	{
		fprintf(stderr,"write err");
	/*offset = 15*/
	}
	
	if(lseek(fd, 16345, SEEK_SET) == -1)
	{
		fprintf(stderr,"lseek err");
	/*offset = 16345*/
	}
	
	if(write(fd, buf1, 15) != 15)
	{
		fprintf(stderr,"write err");
	/*offset = 16345 + 15*/
	}
	
	exit(0);
}


/*
root@jOKERII:/home/topeet/UNIX_test# cc file_hole.c -o file_hole
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./file_hole
root@jOKERII:/home/topeet/UNIX_test# ls
a    err.c     exec_2.c     get_pid    lseek    out          stdin_out.c
b    exec_1    file_hole    get_pid.c  lseek.c  puts_gets
c    exec_1.c  file.hole    group      myls     puts_gets.c
err  exec_2    file_hole.c  group.c    myls.c   stdin_out
root@jOKERII:/home/topeet/UNIX_test# ls -l file.hole 
-rw-r--r-- 1 root root 16360 Oct 31 05:04 file.hole
root@jOKERII:/home/topeet/UNIX_test# od file.hole 
0000000 065170 020143 072562 075157 064550 062040 071545 000165
0000020 000000 000000 000000 000000 000000 000000 000000 000000
*
0037720 000000 000000 000000 000000 074000 061552 064040 067141
0037740 060550 020156 062544 072563
0037750
root@jOKERII:/home/topeet/UNIX_test# od -c file.hole 
0000000   x   j   c       r   u   o   z   h   i       d   e   s   u  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0037720  \0  \0  \0  \0  \0  \0  \0  \0  \0   x   j   c       h   a   n
0037740   h   a   n       d   e   s   u
0037750




*/


