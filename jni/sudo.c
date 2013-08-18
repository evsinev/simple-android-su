
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


/*
 * sudo password ls -l /dev/input
 * 0    1        2  3  4            
 *               0  1  2 
 */
int main(int argc, char **argv) {

    if(argc < 3) {
        printf("usage: sudo PASSWORD PROGRAM [ARGS]\n");
        return 1;
    }

    if(strncmp("123password123", argv[1], 15)) {
        printf("Wrong password\n");
        return 1;
    }

    int SHIFT = 2;
    int exec_args_length = argc - 1 ;
    
    char *exec_args[exec_args_length];
    
    exec_args[0] = argv[SHIFT];
    int i;
    for (i = 1; i < exec_args_length-1; i++) {
        exec_args[i] = argv[i+SHIFT];
	}
    exec_args[exec_args_length-1] = NULL;

    execv(exec_args[0], exec_args);
    return 0;
}


