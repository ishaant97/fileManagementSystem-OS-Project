#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void addFileToDirectory(Directory &directory, const string &name, int size, int start_block)
{
    File newFile;
    newFile.name = name;
    newFile.size = size;
    newFile.start_block = start_block;
    directory.files.push_back(newFile);
}