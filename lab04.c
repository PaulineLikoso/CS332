#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define	BUFFSIZE 1024

int main(int argc, char *argv[])
{  
    int fd, wfd, n;
    char s[BUFFSIZE];
    fd = open(argv[1], O_RDWR);
    wfd = open(argv[2], O_RDWR|O_CREAT);

    if (argc != 3){ 
		printf("Usage: %s <filename>\n", argv[0]); /*in case of incorrect inputs*/
		exit (-1);
	}

    if (fd==-1|| wfd==-1){
		printf("Error with file open\n"); /*in case of issues with opening the files*/
		exit (-1);
	}

    lseek(wfd,0,SEEK_END); /*go to the end to the end of file*/
    while((n=read(fd, &s, BUFFSIZE))>0){ /*read BUFFSIZE characters at a time from fd  and store into s*/
        write(wfd, &s, n); /*write content of s into wfd*/
    }

    close(wfd);
    close(fd);
}