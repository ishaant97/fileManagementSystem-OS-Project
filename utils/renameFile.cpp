#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void renameFile(Directory &currentdirectory, string &oldName, string &newName)
{
    for (File &file : currentdirectory.files)
    {
        if (file.name == oldName)
        {
            file.name = newName;
            return;
        }
    }
    for (Directory &subdirectory : currentdirectory.subdirectories)
    {
        renameFile(subdirectory, oldName, newName);
    }
    cout << "File not found: " << oldName << endl;
}