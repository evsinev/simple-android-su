
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include <unistd.h>
#include <time.h>

#include <pwd.h>


int main(int argc, char **argv) {

   if(argc < 2) {
     printf("usage: su PASSWORD\n");
     return 1;
   }

   if(strncmp("123password123", argv[1], 15)) {
     printf("Wrong password\n");
     return 1;
   }

	char *exec_args[argc];
	exec_args[argc] = NULL;
	exec_args[0] = "sh";
	int i;
	for (i = 1; i < argc; i++) {
		exec_args[i] = argv[i+1];
	}
   execv("/system/bin/sh", exec_args);
   return 0;
}

