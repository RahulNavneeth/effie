#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/torrent.h"

Torrent *init_torrent (char *filePath) {
    FILE *file = fopen (filePath, "rb");
    if (!file) {
        printf("Err :: Can't read file: %s\n", filePath);
        return NULL;
    }

    fseek (file, 0, SEEK_END);
    long file_size = ftell (file);
    fseek (file, 0, SEEK_SET);

    if (file_size <= 0) {
        printf ("Err :: Empty file or could not determine file size\n");
        fclose (file);
        return NULL;
    }

    char *content = malloc (file_size + 1);
    if (!content) {
        printf ("Err :: Memory allocation failed (Content) [torrent.c]\n");
        fclose (file);
        return NULL;
    }

    size_t bytes_read = fread (content, 1, file_size, file);
    fclose (file);

    if (bytes_read != (size_t)file_size) {
        printf("Err :: Could not read entire file\n");
        free (content);
        return NULL;
    }

    content[file_size] = '\0';

    Torrent *torrent = malloc (sizeof (Torrent));
    if (!torrent) {
        printf ("Err :: Memory allocation failed (Torrent) [torrent.c]\n");
        free (content);
        return NULL;
    }


    torrent->fileSize = file_size;
    torrent->filePath = strdup (filePath);
    torrent->contents = bec_decode (&content);

    printf("\e[32mOk :: Initialised torrent file successfully\e[0m\n");

    return torrent;
}
