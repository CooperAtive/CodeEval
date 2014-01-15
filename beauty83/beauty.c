#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024

int compare_int(const void *, const void *);
int compare_int (const void *cur, const void *next)
{
    int c = *((int*)cur);
    int n = *((int*)next);
    if (c >= n) return -1;
    if (c < n) return 1;
    return 0;
}
int main(int argc, char **argv)
{
        FILE *f;
        char line[LINE_SIZE], *p;
        int i, j, k, beauty = 0;

        if (argc < 2 || !(f = fopen(argv[1], "r"))) {
            fprintf(stderr, "Unable to open file argument\n");
            return 1;
        }
        while (fgets(line, LINE_SIZE, f)) {
            if ((p = strchr(line, '\n'))) { *p = '\0'; }
            if (line[0] == '\0') { 
                continue; 
            }
            i = 0;
            int counts[26] = {0};  
            while (line[i]) {
                j = (int) line[i];
                if (j > 64 && j < 91 || j > 96 &&  j < 123){
                    if (j < 91)
                        j = j - 'A';
                    else
                        j = j - 'a';
                    //printf("%c - %d ", line[i], j);
                    counts[j] += 1;
                }
                i++;
            }
            qsort(counts, 26, sizeof (int), compare_int);
            //printf("\n");
            for (k = 0; k < 26; k++) {
                //printf("%d,", counts[k]);
                if (counts[k])
                    beauty += counts[k] * (26 - k); 
            }
            printf("%d\n", beauty);
            beauty = 0;
        }
        return 0;
}
