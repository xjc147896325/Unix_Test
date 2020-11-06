/*
umask stat(unistd) lstat(unistd) futtimens
*/
#include <sys/stat.h>
#include <sys/types.h>

//#include <sys/termios.h>
//#include <sys/wait.h>

/*
sleep chdir
*/
#include <unistd.h>

/*

*/
#include <dirent.h>

#include <errno.h>

/*

*/
#include <limits.h>

/*
open write read unlink
*/
#include <fcntl.h>
//#include <signal.h>

/* 
stdin stdout stderr sprintf printf
*/
#include <stdio.h>

/* exit realloc*/
#include <stdlib.h>

//#include <stddef.h>

/* strlen strcpy */
#include <string.h>



int main (void)
{
	if(chdir("/tmp") < 0)
	{
		fprintf(stderr, "chdir failed\n");
	}
	printf("chdir to /tmp succeeded\n");
	exit(0);
}


			

/*
root@jOKERII:/home/topeet/UNIX_test# cc mycd.c -o mycdi'e'shi
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# pwd
/home/topeet/UNIX_test
root@jOKERII:/home/topeet/UNIX_test# ./mycd
chdir to /tmp succeeded
root@jOKERII:/home/topeet/UNIX_test# pwd
/home/topeet/UNIX_test

写是写完了 也没有报错 也能正常运行 但是不是很理解为什么，不太懂其目的

*/


