#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "bec.h"

int32_t main (int32_t argc, char **argv) {
    FILE *file; 
    if (argc == 1) {
        printf ("Err :: args <filename>\n");
        return 1;
    }
    
    file = fopen (argv[1], "rb");
    if (file == NULL) {
        printf ("Err :: Can't read file : %s\n", argv[1]);
        return 1;
    }

    fseek (file, 0, SEEK_END);
    long file_size = ftell (file);
    fseek (file, 0, SEEK_SET);
    
    if (file_size <= 0) {
        printf ("Err :: Empty file or could not determine file size\n");
        fclose (file);
        return 1;
    }

    char *content = malloc (file_size + 1);
    if (content == NULL) {
        printf ("Err :: Memory allocation failed\n");
        fclose (file);
        return 1;
    }

    size_t bytes_read = fread (content, 1, file_size, file);
    if (bytes_read != file_size) {
        printf ("Err :: Could not read entire file\n");
        free (content);
        fclose (file);
        return 1;
    }

    content[file_size] = '\0';
    
    printf ("File size: %ld bytes\n", file_size);
    printf ("First 100 bytes (hex): ");
    for (int i = 0; i < (file_size < 100 ? file_size : 100); i++) {
        printf ("%02x ", (unsigned char)content[i]);
    }
    printf ("\n\n");

	printf ("%s\n", content);

    char *ptr = content;
	// char * sa = "d5:he loli343eee";
	// char * saptr = sa;
    // bec_print (bec_decode (&saptr), 0);
    bec_print (bec_decode (&ptr), 0);
    // bec_decode (&ptr);
    
    free (content);
    fclose (file);
    return 0;
}
