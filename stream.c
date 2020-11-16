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
	
	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);
	
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
root@jOKERII:/home/topeet/UNIX_test# cc -o stream stream.c 
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./stream
enter any character

stram = stdin, line buffered, buffer size = 1024 
stram = stdout, line buffered, buffer size = 1024 
stram = stderr, unbuffered, buffer size = 0 
stram = /etc/passwd, fully buffered, buffer size = 4096 
root@jOKERII:/home/topeet/UNIX_test# ./stream < /etc/group >out 2>std.err
root@jOKERII:/home/topeet/UNIX_test# cat std.err 
root@jOKERII:/home/topeet/UNIX_test# cat out 
enter any character
stram = stdin, fully buffered, buffer size = 4096 
stram = stdout, fully buffered, buffer size = 4096 
stram = stderr, unbuffered, buffer size = 0 
stram = /etc/passwd, fully buffered, buffer size = 4096 
root@jOKERII:/home/topeet/UNIX_test# 

*/


