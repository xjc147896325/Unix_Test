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



int main (int argc, char *argv[])
{
	int val;
	
	if(argc != 2)
	{
		fprintf(stderr,"usage: fcntl <descriptor#>");
	}
	
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	{
		fprintf(stderr,"fcntl error for fd %d", atoi(argv[1]));
	/*offset = 15*/
	}
	
	switch(val & O_ACCMODE)
	{
		case(O_RDONLY):
		{
			fprintf(stdout,"read only");
			break;
		}
		case(O_WRONLY):
		{
			fprintf(stdout,"write only");
			break;
		}
		case(O_RDWR):
		{
			fprintf(stdout,"read write");
			break;
		}
		default:
		{
			fprintf(stderr,"unknown access mode");
		}
	}
	
	if(val & O_APPEND)
	{
		fprintf(stdout,",append");
	}
	if(val & O_NONBLOCK)
	{
		fprintf(stdout,",nonblocking");
	}
	if(val & O_SYNC)
	{
		fprintf(stdout,",synchronous writes");
	}
	
	#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
		if(val & O_FSYNC)
			fprintf(stdout,", synchronous writes");
	#endif
	
	putchar('\n');
	
	exit(0);
}


void set_f1(int fd, int flags) /*flags are file status flags to turn on */
{
	int 	val;
	
	if((val = fcntl(fd, F_GETFL, 0)) < 0)
	{
		fprintf(stderr,"fcntl F_GETFL err");
	}
	
	val |= flags; /*turn on flags */
	
	if(fcntl(fd, F_SETFL, val) < 0)
	{
		fprintf(stderr,"fcntl F_SETFL err");
	}
}


/*
root@jOKERII:/home/topeet/UNIX_test# cc fcntl.c -o fcntl
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# ./fcntl
usage: fcntl <descriptor#>Segmentation fault (core dumped)
root@jOKERII:/home/topeet/UNIX_test# ./fcntl a
read write
root@jOKERII:/home/topeet/UNIX_test# ./fcntl err.c 
read write
root@jOKERII:/home/topeet/UNIX_test# ./fcntl 0 < /dev/tty
read only
root@jOKERII:/home/topeet/UNIX_test# ./fcntl 1 > temp.foo
root@jOKERII:/home/topeet/UNIX_test# cat temp.foo
write only
root@jOKERII:/home/topeet/UNIX_test# ls
a                          err.c     file_hole    lseek        stdin_out
b                          exec_1    file.hole    lseek.c      stdin_out.c
c                          exec_1.c  file_hole.c  myls         temp.foo
copy_only_by_write_read    exec_2    get_pid      myls.c
copy_only_by_write_read.c  exec_2.c  get_pid.c    out
e                          fcntl     group        puts_gets
err                        fcntl.c   group.c      puts_gets.c
root@jOKERII:/home/topeet/UNIX_test# ./fcntl 2 2>>temp.foo 
write only,append
root@jOKERII:/home/topeet/UNIX_test# ./fcntl 5 5<>temp.foo 
read write




*/


