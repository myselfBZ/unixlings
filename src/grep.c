#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

void grep(const char *pattern, FILE *stream) {
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stream)) {
        if (strstr(line, pattern)) {
            printf("%s", line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pattern> [file]\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        grep(argv[1], stdin);  
    } else {
        FILE *file = fopen(argv[2], "r");
        if (!file) {
            perror("fopen");
            return 1;
        }
        grep(argv[1], file);
        fclose(file);
    }
    return 0;
}

