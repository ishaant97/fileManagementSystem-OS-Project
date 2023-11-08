#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

int calculateWastedDiskSpace(Filesystem &fs)
{
    int wastedDiskSpace = 0;
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (fs.blocks[i].used == 0)
        {
            wastedDiskSpace++;
        }
    }
    return wastedDiskSpace;
}