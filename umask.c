/*
umask stat lstat
*/
#include <sys/types.h>
#include <sys/stat.h>

//#include <sys/termios.h>
//#include <sys/wait.h>
#include <unistd.h>

//#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
//#include <signal.h>

/* stdin stdout stderr sprintf */
#include <stdio.h>

/* exit */
#include <stdlib.h>

//#include <stddef.h>
//#include <string.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)


int main (void)
{
	umask(0);
	if (creat("foo", RWRWRW) < 0)
	{
		fprintf(stderr, "creat err for foo");
	}
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(creat("bar", RWRWRW) < 0)
	{
		fprintf(stderr, "creat errr for bar");
	}
	
	
	exit(0);
}




/*
root@jOKERII:/home/topeet/UNIX_test# cc umask.c -o umask
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# umask
0022
root@jOKERII:/home/topeet/UNIX_test# ./umask
root@jOKERII:/home/topeet/UNIX_test# ls -l foo bar
-rw------- 1 root root 0 Nov  3 03:18 bar
-rw-rw-rw- 1 root root 0 Nov  3 03:18 foo
root@jOKERII:/home/topeet/UNIX_test# umask
0022


*/


