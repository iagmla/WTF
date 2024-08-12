#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "formatter.c"

/* War Time Formatter */
/* by KryptoMagick (Karl Zander) */
/* v0.0.3 */

void usage() {
    printf("War Time Formatter usage:\n");
    printf("wtf -l <group length> -g <groups per line> <infile> <outfile>\n");
}

int main(int argc, char *argv[]) {
    int grouplen = 5;
    int groups_per_line = 10;
    if (argc != 7) {
        usage();
        exit(0);
    }
    if (strcmp(argv[1], "-l") == 0) {
        grouplen = atoi(argv[2]);
    }
    else {
        usage();
        exit(0);
    }
    if (strcmp(argv[3], "-g") == 0) {
        groups_per_line = atoi(argv[4]);
    }
    else {
        usage();
        exit(0);
    }
    if (access(argv[5], F_OK) == -1 ) {
        printf("%s not found\n", argv[5]);
        exit(1);
    }
    format_text(argv[5], argv[6], grouplen, groups_per_line);
}
