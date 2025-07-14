#ifndef EFF_H
#define EFF_H

#include "core/torrent.h"

typedef struct {
	Torrent* torrent;
} Eff;

Eff *init_effie (char *filePath); 

#endif /* EFF_H */
