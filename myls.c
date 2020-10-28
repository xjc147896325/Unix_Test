#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>
#include <dirent.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int main ( int argc, char *argv[])
{
	DIR             *dp;
	struct dirent   *dirp;

	if( argc != 2 )
	{
		fprintf(stderr,"usage: ls directory_name\n");
	}

	if((dp = opendir(argv[1])) == NULL )
	{
		fprintf(stderr,"can't open %s\n", argv[1]);
	}
	while(( dirp = readdir(dp)) != NULL)
	{
		printf("%s\n",dirp -> d_name);
	}

	closedir(dp);
	exit(0);
}

/*
cc -o myls myls.c
*/

/* 
root@jOKERII:/home/topeet# ./a.out Modules/



module_test.mod.c
.tmp_versions
..
.module_test.ko.cmd
module_test_drivercode
module_test.mod.o
modules.order
.module_test.c.swp
driver
module_test.ko
module_test.c
Makefile
.Makefile.swp
Module.symvers
.
module_test.o
.module_test.mod.o.cmd
.module_test.o.cmd
*/



/* 
root@jOKERII:/home/topeet# ls Modules/

driver         Module.symvers          module_test.ko     module_test.o
Makefile       module_test.c           module_test.mod.c
modules.order  module_test_drivercode  module_test.mod.o



*/

/*
root@jOKERII:/home/topeet# ls -a Modules/

.              Module.symvers          module_test.mod.c
..             module_test.c           module_test.mod.o
driver         .module_test.c.swp      .module_test.mod.o.cmd
Makefile       module_test_drivercode  module_test.o
.Makefile.swp  module_test.ko          .module_test.o.cmd
modules.order  .module_test.ko.cmd     .tmp_versions



*/