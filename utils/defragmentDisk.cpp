#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void defragmentDisk(Filesystem &fs)
{
    int next_free_block = 0;

    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (fs.blocks[i].used == 1)
        {
            fs.blocks[i].file_index = next_free_block;
            next_free_block++;
        }
    }
}