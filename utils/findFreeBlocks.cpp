#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

int findFreeBlocks(Filesystem &fs, int size)
{
    int start_block = -1;
    int consecutive_free_blocks = 0;

    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (fs.blocks[i].used == 0)
        {
            if (start_block == -1)
            {
                start_block = i;
            }
            consecutive_free_blocks++;

            if (consecutive_free_blocks == size)
            {
                return start_block;
            }
        }
    }
    return -1;
}