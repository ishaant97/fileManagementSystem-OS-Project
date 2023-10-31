#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

int calculateDiskFragmentation(const Filesystem &fs)
{
    int fragmentedBlocks = 0;
    int currentFileIndex = -1;

    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (fs.blocks[i].used == 1)
        {
            // If we're inside a file, check if the file index matches the current one
            if (currentFileIndex != -1 && fs.blocks[i].file_index != currentFileIndex)
            {
                fragmentedBlocks = fragmentedBlocks + 10;
            }
            currentFileIndex = fs.blocks[i].file_index;
        }
    }

    return fragmentedBlocks;
}