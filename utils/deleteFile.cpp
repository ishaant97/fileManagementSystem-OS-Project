#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void deleteFile(Directory &directory, const std::string &fileName, Filesystem &fs)
{
    for (size_t i = 0; i < directory.files.size(); ++i)
    {
        if (directory.files[i].name == fileName)
        {
            // Clear the blocks used by the file
            for (int j = directory.files[i].start_block; j < directory.files[i].start_block + directory.files[i].size; ++j)
            {
                fs.blocks[j].used = 0;
                fs.blocks[j].file_index = -1;
            }

            // Remove the file from the directory
            directory.files.erase(directory.files.begin() + i);
            std::cout << "File '" << fileName << "' deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "File not found: " << fileName << std::endl;
}