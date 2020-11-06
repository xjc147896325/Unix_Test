/*
umask stat(unistd) lstat(unistd) futtimens
*/
#include <sys/stat.h>
#include <sys/types.h>

//#include <sys/termios.h>
//#include <sys/wait.h>

/*
sleep chdir getcwd getwd get_current_dir_name
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

/* user own */
#include "path_alloc.h"


#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

int main (int argc, char *argv[])
{
	int 		i;
	struct stat	buf;
	
	for(i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		if(stat(argv[i], &buf) < 0)
		{
			fprintf(stderr, "stat err");
			continue;
		}
		printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
		if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		{
			printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block", major(buf.st_rdev)\
					, minor(buf.st_rdev), minor(buf.st_rdev));
		}
		printf("\n");
	}
	
	exit(0);
}


			

/*
root@jOKERII:/home/topeet/UNIX_test# cc get_dev.c -o get_dev
*/

/* 

root@jOKERII:/home/topeet/UNIX_test# ./get_dev / /home/topeet /dev/tty[01]
/: dev = 8/1
/home/topeet: dev = 8/1
/dev/tty0: dev = 0/5 (character) rdev = 4/0
/dev/tty1: dev = 0/5 (character) rdev = 4/1



root@jOKERII:/home/topeet/UNIX_test# mount
/dev/sda1 on / type ext4 (rw,errors=remount-ro)
proc on /proc type proc (rw,noexec,nosuid,nodev)
sysfs on /sys type sysfs (rw,noexec,nosuid,nodev)
none on /sys/fs/fuse/connections type fusectl (rw)
none on /sys/kernel/debug type debugfs (rw)
none on /sys/kernel/security type securityfs (rw)
udev on /dev type devtmpfs (rw,mode=0755)
devpts on /dev/pts type devpts (rw,noexec,nosuid,gid=5,mode=0620)
tmpfs on /run type tmpfs (rw,noexec,nosuid,size=10%,mode=0755)
none on /run/lock type tmpfs (rw,noexec,nosuid,nodev,size=5242880)
none on /run/shm type tmpfs (rw,nosuid,nodev)
.host:/ on /mnt/hgfs type vmhgfs (rw,ttl=1)
vmware-vmblock on /run/vmblock-fuse type fuse.vmware-vmblock (rw,nosuid,nodev,default_permissions,allow_other)
gvfs-fuse-daemon on /home/topeet/.gvfs type fuse.gvfs-fuse-daemon (rw,nosuid,nodev,user=topeet)


root@jOKERII:/home/topeet/UNIX_test# ls -l /dev/tty[01] /dev/sda[34]
ls: cannot access /dev/sda[34]: No such file or directory
crw--w---- 1 root tty 4, 0 Nov  6 01:16 /dev/tty0
crw-rw---- 1 root tty 4, 1 Nov  6 01:16 /dev/tty1

*/


