#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("We are about to fork()")
    __pid_t n = getppid();      //get the pid of parent process.
    __pid_t p = getpid();       //get pid of current process
    printf("%ld\n",(long)n);
    printf("%ld\n",(long)p);

    //list all environment variables
    // extern char **__environ;
    // for (char **ep = __environ; *ep != NULL; ep++){
    //     puts(*ep);
    // }

    //get particular env variable by name
    char* e = getenv("USER");
    puts(e);
    //env(1);
    exit(EXIT_SUCCESS);
}