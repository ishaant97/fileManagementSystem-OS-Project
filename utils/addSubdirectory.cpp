#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

bool addSubdirectory(Directory &currentDirectory, string &subDirName, Directory &newdirectory)
{
    newdirectory.name = subDirName;
    currentDirectory.subdirectories.push_back(newdirectory);
}