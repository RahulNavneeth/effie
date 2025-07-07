#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "effie.h"

int32_t main (int32_t argc, char **argv) {
    if (argc == 1) {
        printf ("Err :: args <filename>\n");
        return 1;
    }

	Eff *effie = init_effie (argv[1]);
	printf ("FileSize -> %ld\n", effie->torrent->fileSize);
	printf ("FilePath -> %s\n", effie->torrent->filePath);
	bec_print(effie->torrent->contents, 0);
	
    return 0;
}
