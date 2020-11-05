/*
umask stat lstat
*/
#include <sys/stat.h>

#include <sys/types.h>


//#include <sys/termios.h>
//#include <sys/wait.h>

/*
sleep
*/
#include <unistd.h>

//#include <dirent.h>
#include <errno.h>

/*
open write read unlink
*/
#include <fcntl.h>
//#include <signal.h>

/* 
stdin stdout stderr sprintf printf
*/
#include <stdio.h>

/* exit */
#include <stdlib.h>

//#include <stddef.h>
//#include <string.h>



int main (void)
{
	if(open("tempfile", O_RDWR) < 0)
	{
		fprintf(stderr, " opem err \n");
	}
	
	if(unlink("tempfile") < 0)
	{
		fprintf(stderr, " unlink err \n");
	}
	
	printf("file umlinked\n");
	sleep(15);
	printf("done\n");
	
	exit(0);
}




/*
root@jOKERII:/home/topeet/UNIX_test# cc unlink.c -o unlink
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# vim tempfile
root@jOKERII:/home/topeet/UNIX_test# ls -l tempfile
-rw-r--r-- 1 root root 10 Nov  3 04:27 tempfile
root@jOKERII:/home/topeet/UNIX_test# df /home/
Filesystem     1K-blocks     Used Available Use% Mounted on
/dev/sda1       60894268 10177496  47623524  18% /
root@jOKERII:/home/topeet/UNIX_test# ./unlink &
[1] 3801
root@jOKERII:/home/topeet/UNIX_test# file umlinked
ls -l tempdone
file
ls: cannot access tempfile: No such file or directory
[1]+  Done                    ./unlink
root@jOKERII:/home/topeet/UNIX_test# ls -l tempfile
ls: cannot access tempfile: No such file or directory
root@jOKERII:/home/topeet/UNIX_test# df /home/
Filesystem     1K-blocks     Used Available Use% Mounted on
/dev/sda1       60894268 10177488  47623532  18% /



*/


