void format_text(char *infilename, char *outfilename, int grouplen, int groups_per_line) {
    FILE *infile, *outfile;
    infile = fopen(infilename, "rb");
    fseek(infile, 0, SEEK_END);
    int datalen = ftell(infile);
    fseek(infile, 0, SEEK_SET);
    outfile = fopen(outfilename, "wb");
    int letters_per_line = grouplen * groups_per_line;
    int blocks = datalen / letters_per_line;
    int extra = datalen % letters_per_line;
    uint8_t block[grouplen];
    uint8_t space = 32;
    uint8_t newline = 10;
    for (int i = 0; i < blocks; i++) {
        for (int b = 0; b < groups_per_line; b++) {
            fread(block, 1, grouplen, infile);
            fwrite(block, 1, grouplen, outfile);
            if (b != (groups_per_line - 1)) {
                fwrite(&space, 1, 1, outfile);
            }
        }
        fwrite(&newline, 1, 1, outfile);
    }
    fclose(infile);
    fclose(outfile);
}
