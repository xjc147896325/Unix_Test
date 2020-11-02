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



int main (int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "usage: access <pathname>");
		exit(1);
	}
	
	if(access(argv[1], R_OK) < 0)
	{
		fprintf(stderr, "access err for %s", argv[1]);
	}
	else
	{
		fprintf(stdout, "open for reading OK\n");
	}
	
	exit(0);
}




/*
root@jOKERII:/home/topeet/UNIX_test# cc lstat.c -o lstat
*/

/* 

下面是该程序的示例会话:
$ ls -l a.out
15945 Nov 30 12:10 a.out
-rwxrwxr一x 1 sar
$ ./a.out a.out
read access OK
open for reading OK
s ls -l letc/ shadow
-r————---- 1 root
1315 Jul 172002 letc/shadow
s .fa.out /etc/shadow
access error for /etc/shadow : Permission denied
open error for letc/shadow : Permission denied
成为超级用户
 su
输入超级用户口令
Password:
将文件用户ID改为root
chown root a.out
并打开设置用户ID位
chmod u+s a.out
检查所有者和SUID位
.ls -l a .out
15945 Nov 30 12:10 a.out
-rwsrwxr一x l root
恢复为正常用户
exit
s .a.out fetc/shadow
access error for /etc/shadow: Permission denied
open for reading oK

实际测试不对
root@jOKERII:/home/topeet/UNIX_test# ls -l access
-rwxr-xr-x 1 root root 8671 Nov  2 07:32 access
root@jOKERII:/home/topeet/UNIX_test# ./access access
open for reading OK
root@jOKERII:/home/topeet/UNIX_test# ./access /etc/shadow
open for reading OK
root@jOKERII:/home/topeet/UNIX_test# ls -l /etc/shadow
-rw-r----- 1 root shadow 1225 Oct  4 02:10 /etc/shadow
root@jOKERII:/home/topeet/UNIX_test# chown root access
root@jOKERII:/home/topeet/UNIX_test# chmod u+s access
root@jOKERII:/home/topeet/UNIX_test# ls -l access
-rwsr-xr-x 1 root root 8671 Nov  2 07:32 access
root@jOKERII:/home/topeet/UNIX_test# exit
exit
root@jOKERII:/home/topeet/UNIX_test# ./access /etc/shadow
open for reading OK


待明天继续测试 2020-11-02 23：37



*/


