#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

int calculateSizeOfLastUnusedBlock(const Filesystem &fs)
{
    int lastUnusedBlockSize = 0;
    int index = MAX_BLOCKS - 1;

    // Starting from the last block, find the last unused block and calculate its size
    while (index >= 0 && fs.blocks[index].used == 0)
    {
        lastUnusedBlockSize++;
        index--;
    }

    // cout << "Last block : " << lastUnusedBlockSize << endl;

    return lastUnusedBlockSize;
}

int calculateDiskFragmentation(const Filesystem &fs)
{
    int fragmentedBlocks = 0;
    int lastUnusedBlockSize = calculateSizeOfLastUnusedBlock(fs);
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (fs.blocks[i].used == 0)
        {
            fragmentedBlocks++;
        }
    }
    return fragmentedBlocks - lastUnusedBlockSize;
}