#ifndef __GETPWNAM_H
#define __GETPWNAM_H

#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/termios.h>
//#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pwd.h>

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
#include <string.h>

struct passwd* getpwnam(const char *name);

#endif
