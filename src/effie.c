#include <stdio.h>
#include <stdlib.h>
#include "effie.h"

Eff *init_effie (char *filePath) {
	Torrent *torrent = init_torrent (filePath);
	if (torrent == NULL) {
        printf("Err :: Memory allocation failed (Torrent) [effie.c]\n");
		return NULL;
	}

	Eff *eff = (Eff*)malloc (sizeof (Eff));
	if (eff == NULL) {
        printf("Err :: Memory allocation failed (Eff) [effie.c]\n");
		return NULL;
	}
	eff->torrent = torrent;
	printf("\e[32mOk :: Initialised Effie successfully\e[0m\n");
	return eff; 
}
