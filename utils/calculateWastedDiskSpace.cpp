#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

int calculateWastedDiskSpace(Filesystem &fs)
{
    int wasted_blocks = 0;
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (fs.blocks[i].used == 0)
        {
            wasted_blocks++;
        }
    }
    return wasted_blocks;
}