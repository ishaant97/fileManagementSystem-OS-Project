#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void renameFile(Directory &directory, const std::string &oldName, const std::string &newName)
{
    // First, search for the file in the current directory
    for (File &file : directory.files)
    {
        if (file.name == oldName)
        {
            file.name = newName;
            std::cout << "File renamed successfully to: " << newName << std::endl;
            return;
        }
    }

    // If the file is not in the current directory, search in subdirectories
    for (Directory &subdirectory : directory.subdirectories)
    {
        renameFile(subdirectory, oldName, newName); // Recursively search in subdirectories
    }

    std::cout << "File not found: " << oldName << std::endl;
}