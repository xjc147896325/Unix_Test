#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/termios.h>
//#include <sys/wait.h>
#include <unistd.h>

//#include <dirent.h>
#include <errno.h>
//#include <fcntl.h>
//#include <signal.h>
/* stdin stdout stderr sprintf */
#include <stdio.h>
/* exit */
#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>



int main (int argc, char *argv[])
{
	int 			i;
	struct stat 	buf;
	char 			*ptr;
	
	for(i = 1; i < argc; i++)
	{
		fprintf(stdout, "%s: ", argv[i]);
		if(lstat(argv[i], &buf) < 0)
		{
			fprintf(stderr, "lstat err\n");
			continue;
		}
		
		if(S_ISREG(buf.st_mode))
		{
			ptr = "regular\n";
		}
		else
		{
			if(S_ISDIR(buf.st_mode))
			{
				ptr = "directory\n";
			}
			else
			{
				if(S_ISCHR(buf.st_mode))
				{
					ptr = "character special\n";
				}
				else
				{
					if(S_ISBLK(buf.st_mode))
					{
						ptr = "block special\n";
					}
					else
					{
						if(S_ISFIFO(buf.st_mode))
						{
							ptr = "fifo\n";
						}
						else
						{
							if(S_ISLNK(buf.st_mode))
							{
								ptr = "symbolic link\n";
							}
							else
							{
								if(S_ISSOCK(buf.st_mode))
								{
									ptr = "socket\n";
								}
								else
								{
									ptr = "** unknown mode **\n";
								}
							}
						}
					}
				}
			}
		}
	}
	
	exit(0);
}




/*
root@jOKERII:/home/topeet/UNIX_test# cc lstat.c -o lstat
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# ./lstat /etc/passwd /etc /dev/log /dev/tty /var/lib/os-prober/ /dev/sr0 /dev/cdrom
/etc/passwd: regular
/etc: directory
/dev/log: socket
/dev/tty: character special
/var/lib/os-prober/: directory
/dev/sr0: block special
/dev/cdrom: symbolic link





*/


