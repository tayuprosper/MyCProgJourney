#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024
char buf[BUFFER_SIZE];
int main(int argc,char* argv[])
{
    int stream;
    char *line = NULL;
    size_t len =0;
    ssize_t nread;
    if (argc <= 1){
        printf("File path not given\n");
        exit(EXIT_FAILURE);
    }

    stream = open(argv[1],O_RDONLY);
    if (stream == -1){
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    int fdout = open("copie.txt",O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);
    nread = read(stream,buf,BUFFER_SIZE);
    write(fdout,buf,BUFFER_SIZE);
    printf("%s\n",buf);
    free(line);
    close(fdout);
    close(stream);
    exit(EXIT_SUCCESS);

    exit(EXIT_SUCCESS);
}