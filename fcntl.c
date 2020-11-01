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



int main (void)
{
	int val;
	
	if(argv != 2)
	{
		fprintf(stderr,"usage: fcntl <descriptor#>");
	}
	
	if((val = fcntl(atoi(argv[1]), F_CETFL, 0)) < 0)
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


/*
未测试 仅供提交使用
*/

/* 




*/


