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
stdin stdout stderr sprintf printf puts gets putschar getchar fopen fdopen freopen fgetc getc fgets gets getchar ungetc
*/
#include <stdio.h>

/* exit realloc*/
#include <stdlib.h>

//#include <stddef.h>

/* strlen strcpy */
#include <string.h>

/* user own */
#include "path_alloc.h"


void 	pr_stdio(const char *, FILE *);
int 	is_unbuffered(FILE *);
int		is_linebuffered(FILE *);
int 	buffer_size(FILE *);

int main(void)
{
	FILE *fp;
	
	fputs("enter any character\n",stdout);
	if(getchar() == EOF)
	{
		fprintf(stderr, "getchar err");
	}
	
	pt_stdio("stdin", stdin);
	pt_stdio("stdout", stdout);
	pt_stdio("stderr", stderr);
	
	if((fp = fopen("/etc/passwd", "r")) == NULL)
	{
		fprintf(stderr, "fopen err");
	}
	if(getc(fp) == EOF)
	{
		fprintf(stderr, "getc err");
	}
	pr_stdio("/etc/passwd", fp);
	exit(0);
}

void pr_stdio(const char *name, FILE *fp)
{
	printf("stram = %s, ", name);
	if(is_unbuffered(fp))
	{
		printf("unbuffered");
	}
	else
	{
		if(is_linebuffered(fp))
		{
			printf("line buffered");
		}
		else
		{
			printf("fully buffered");
		}
	}
	printf(", buffer size = %d \n", buffer_size(fp));
}

/* 
 * The following is nonportable.
 */
 
 #if defined(_IO_UNBUFFERED)
 
 int is_unbuffered(FILE *fp)
 {
	 return(fp->_flags & _IO_UNBUFFERED);
 }

 int is_linebuffered(FILE *fp)
 {
	 return(fp->_flags & _IO_LINE_BUF);
 }

 int buffer_size(FILE *fp)
 {
	 return(fp->_IO_buf_end - fp->_IO_buf_base);
 }

#elif defined(__SNBF)

 int is_unbuffered(FILE *fp)
 {
	 return(fp->_flags & __SNBF);
 }

 int is_linebuffered(FILE *fp)
 {
	 return(fp->_flags & __SLBF);
 }

 int buffer_size(FILE *fp)
 {
	 return(fp->_fp._size);
 }

#elif defined(_IONBF)

#ifdef _LP64
#define _flag __pad[4]
#define _ptr  __pad[1]
#define _base __pad[2]
#endif

 int is_unbuffered(FILE *fp)
 {
	 return(fp->_flags & _IONBF);
 }

 int is_linebuffered(FILE *fp)
 {
	 return(fp->_flags & _IOLBF);
 }

 int buffer_size(FILE *fp)
 {
 #ifdef _LP64
	 return(fp->_base - fp->ptr);
 #else
	 return(BUFSIZ); /* just a guess */
 #endif
 }

#else
	
#error unknown stdio implementation!

#endif


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


