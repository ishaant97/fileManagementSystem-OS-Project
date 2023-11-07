#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

// int calculateDiskFragmentation(const Filesystem &fs)
// {
//     int fragmentedBlocks = 0;

//     // Track if we are currently in an unused space
//     bool inUnusedSpace = false;

//     for (int i = 0; i < MAX_BLOCKS - 1; i++)
//     {
//         if (fs.blocks[i].used == 0)
//         {
//             if (!inUnusedSpace)
//             {
//                 // Start of an unused space, count it as fragmented
//                 fragmentedBlocks++;
//                 inUnusedSpace = true;
//             }
//         }
//         else
//         {
//             inUnusedSpace = false;
//         }
//     }

//     return fragmentedBlocks;
// }

int calculateDiskFragmentation(const Filesystem &fs)
{
    int fragmentedBlocks = 0;
    for (int i = 0; i < MAX_BLOCKS - 1; i++)
    {
        if (fs.blocks[i].used == 0)
        {
            fragmentedBlocks++;
        }
    }
    return fragmentedBlocks;
}