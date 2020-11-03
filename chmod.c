/*
umask stat lstat
*/
#include <sys/stat.h>

#include <sys/types.h>


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



int main (void)
{
	struct stat statbuf;
	/* turm on set-group-ID and turn off group-execute */
	
	if(stat("foo", &statbuf) < 0)
	{
		fprintf(stderr, " stat err for foo\n");
	}
	
	if(chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
	{
		fprintf(stderr, " chmod err for foo\n");
	}
	
	/* set absolute mode to "rw-r--r-- */
	
	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
	{
		fprintf(stderr, " chmod err for bar\n");
	}
	

	exit(0);
}




/*
root@jOKERII:/home/topeet/UNIX_test# cc chmod.c -o chmod
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# ls -l foo bar
-rw------- 1 root root 0 Nov  3 03:18 bar
-rw-rw-rw- 1 root root 0 Nov  3 03:18 foo
root@jOKERII:/home/topeet/UNIX_test# ./chmod
root@jOKERII:/home/topeet/UNIX_test# ls -l foo bar
-rw-r--r-- 1 root root 0 Nov  3 03:18 bar
-rw-rwSrw- 1 root root 0 Nov  3 03:18 foo


*/


