#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("usage: [dir]\n");
        return 1; 
    }
    DIR *dir;
    
    if((dir = opendir(argv[1])) == NULL){
        perror("opendir");
        return 1;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..")){
            printf("%s\n", entry->d_name);
        }
    }
}
