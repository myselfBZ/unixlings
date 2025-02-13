#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_SIZE 4096

int main(int argc, char *argv[]) {
    if(argc != 3){
        return 1;
    }
    int rd;
    int fd = open(argv[1],  O_RDONLY); 

    if(fd < 0){
        perror("");
        return 1;
    }

    int second_file = open(argv[2],  O_WRONLY | O_CREAT, 0644);

    if(second_file < 0){
        perror("second file");
        return 1;
    }

    char buf[MAX_SIZE];
    while ((rd = read(fd, buf, MAX_SIZE)) != 0) {
        if (rd < 0) {
            perror("read");
            return 1;
        }
        int written = write(second_file, buf, rd);
        if(written < 0){
            perror("write");
            return 1;
        }
    }
}
