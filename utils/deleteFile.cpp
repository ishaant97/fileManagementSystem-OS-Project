#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void deleteFile(Directory &directory, string &fileName, Filesystem &fs)
{
    for (size_t i = 0; i < directory.files.size(); ++i)
    {
        if (directory.files[i].name == fileName)
        {
            for (int j = directory.files[i].start_block; j < directory.files[i].start_block + directory.files[i].size; ++j)
            {
                fs.blocks[j].used = 0;
                fs.blocks[j].file_index = -1;
            }
            directory.files.erase(directory.files.begin() + i);
            cout << "File '" << fileName << "' deleted successfully." << endl;
            return;
        }
    }
    cout << "File not found: " << fileName << endl;
}