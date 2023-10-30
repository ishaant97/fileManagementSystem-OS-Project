#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void renameFile(Filesystem &fs, const std::string &oldName, const std::string &newName)
{
    for (File &file : fs.root.files)
    {
        if (file.name == oldName)
        {
            file.name = newName;
            std::cout << "File renamed successfully to: " << newName << std::endl;
            return;
        }
    }
    std::cout << "File not found: " << oldName << std::endl;
}