#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void renameFile(Directory &currentdirectory, string &oldName, string &newName)
{
    // First, search for the file in the current directory
    for (File &file : currentdirectory.files)
    {
        if (file.name == oldName)
        {
            file.name = newName;
            return;
        }
    }
    // If the file is not in the current directory, search in subdirectories
    for (Directory &subdirectory : currentdirectory.subdirectories)
    {
        renameFile(subdirectory, oldName, newName); // Recursively search in subdirectories
    }
    cout << "File not found: " << oldName << endl;
}