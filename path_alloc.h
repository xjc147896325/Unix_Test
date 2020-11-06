#ifndef __PATH_ALLOC_H
#define __PATH_ALLOC_H

#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
#include <string.h>

char * path_alloc(size_t *sizep);

#endif
