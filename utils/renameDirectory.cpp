#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void renameDirectory(Directory &directory, const std::string &oldName, const std::string &newName)
{
    for (Directory &subdirectory : directory.subdirectories)
    {
        if (subdirectory.name == oldName)
        {
            subdirectory.name = newName;
            std::cout << "Directory renamed successfully to: " << newName << std::endl;
            return;
        }
    }
    std::cout << "Directory not found: " << oldName << std::endl;
}