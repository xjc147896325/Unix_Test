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
 * stdin stdout stderr sprintf printf puts gets putschar getchar fopen
 * fdopen freopen fgetc getc fgets gets getchar ungetc tmpfile tmpnam
 * fseek ftell rewind fgetpos fsetpos fmemopen
*/
#include <stdio.h>

/* 
 * exit realloc mkdtemp mkstemp mkostemp mkstemps mkostemps

 */
#include <stdlib.h>

//#include <stddef.h>

/* 
 * strlen strcpy memset
 */
#include <string.h>

/* user own */
#include "path_alloc.h"

#define BSZ 	48

int main(void)
{
	FILE 	*fp;
	char 	buf[BSZ];
	
	memset(buf, 'a', BSZ - 2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'X';
	if((fp = fmemopen(buf, BSZ, "w")) == NULL)
	{
		fprintf(stderr, "fmemopen failed");
	}
	printf("inital buffer contents: %s\n", buf);
	fprintf(fp, "hello, world");
	printf("before flush: %s\n", buf);
	fflush(fp);
	printf("after flush: %s\n, buf);
	printf("len of string in buf = %ld\n\n", (long)strlen(buf));
	
	memset(buf, 'b', BSZ - 2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'X';
	fprintf(fp, "hello, world");
	fseek(fp, 0, SEEK_SET);
	printf("after flush: %s\n", buf);
	printf("len of string in buf = %ld\n\n", (long)strlen(buf));	
	
	memset(buf, 'c', BSZ - 2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'X';
	fprintf(fp, "hello, world");
	fclose(fp);
	printf("after flush: %s\n", buf);
	printf("len of string in buf = %ld\n\n", (long)strlen(buf));	
	
	return(0);
}

/*
root@jOKERII:/home/topeet/UNIX_test# cc memory_stream.c -o memory_stream
*/

/* 
root@jOKERII:/home/topeet/UNIX_test# ./memory_stream
inital buffer contents: 
before flush: 
after flush: hello, world
len of string in buf = 12
after flush: bbbbbbbbbbbbhello, world
len of string in buf = 24
after flush: hello, worldcccccccccccccccccccccccccccccccccc
len of string in buf = 46


*/

/* 

当注释掉fflush时：
root@jOKERII:/home/topeet/UNIX_test# ./memory_stream
inital buffer contents: 
before flush: 
after flush: 
len of string in buf = 0
after flush: hello, worldhello, world
len of string in buf = 24
after flush: hello, worldcccccccccccccccccccccccccccccccccc
len of string in buf = 46



（只有当移动或啥的处理fp时，才会把缓冲更新进流
 */
