#include <stdio.h>
#include <ctype.h>


int ischar(char ch){
    if(isspace(ch) || ch == '#' || ch == '*'
          ||  (ch >= '0' && ch <= '9')){
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]){
    int wc = 0;
    if (argc != 2) {
        printf("usage: [dir]\n");
        return 1; 
    }
    FILE* file = fopen(argv[1], "r");
    // TODO: some nicer error messages
    if(file == NULL) return 1;
    char cur_char;
    while((cur_char = fgetc(file)) != EOF){
        if(!ischar(cur_char)){
            continue;
        }
        while ((cur_char = fgetc(file)) != EOF && ischar(cur_char)) {}
        wc++;
    }
    fclose(file);
    printf("word count: %d\n", wc);
}
