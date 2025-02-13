#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXSIZE 4096

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("usage: cat [file]\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY, 0644);
    if (fd < 0){
        printf("couldn't open file %s ", argv[1]);
        perror("");
        return 1;
    }
    int read_bytes = 0;
    char buf[MAXSIZE];
    while((read_bytes = read(fd, buf, MAXSIZE)) > 0){
        int write_result = write(STDOUT_FILENO, buf,  read_bytes);
        if (write_result < 0) {
            perror("error printing");
            return 1;
        }
    }
}
