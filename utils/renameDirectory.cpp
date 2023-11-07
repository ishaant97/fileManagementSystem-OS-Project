#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void renameDirectory(Directory &currentdirectory, string &oldName, string &newName)
{
    for (Directory &subdirectory : currentdirectory.subdirectories)
    {
        if (subdirectory.name == oldName)
        {
            subdirectory.name = newName;
            // std::cout << "Directory renamed successfully to: " << newName << std::endl;
            return;
        }
    }
    cout << "Directory not found: " << oldName << endl;
}