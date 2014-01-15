#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024
int main(int argc, char **argv)
{
        FILE *f;
        char line[LINE_SIZE], *p;
        char *arg;
        int i, j, a, b, n;
        int args[3];

        if (argc < 2 || !(f = fopen(argv[1], "r"))) {
            fprintf(stderr, "Unable to open file argument\n");
            return 1;
        }
        while (fgets(line, LINE_SIZE, f)) {
            if ((p = strchr(line, '\n'))) { *p = '\0'; }
            if (line[0] == '\0') { 
                continue; }
            arg = strtok(line, " ");
            i = 0;            
            while (arg != NULL) {
                int data = atoi(arg);
                args[i] = data; 
                arg = strtok (NULL, " ");
                i++;
            }
            a = args[0], b = args[1], n = args[2];
            for (j = 1; j < n+1; j++) {
                if ( j % a == 0 && j % b == 0){
                    printf("%s", "FB");
                }
                else if (j % a == 0) {
                    printf("%c", 'F');
                }
                else if (j % b == 0) {
                    printf("%c", 'B');
                }
                else printf("%d", j);
                if ( j != n){
                    printf(" ");
                }
            }
            printf("\n");
        }
        
        if (ferror(f)) {
            perror("I/O Error");
        }
        return 0;
}
