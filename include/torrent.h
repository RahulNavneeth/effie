#ifndef TORRENT_H
#define TORRENT_H

#include "bec.h"

typedef struct  {
	long fileSize;
	char *filePath;
	Bec *contents;
} Torrent;

Torrent *init_torrent (char *fileName);

#endif /* TORRENT_H */
