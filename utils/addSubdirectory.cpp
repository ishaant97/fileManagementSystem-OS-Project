#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

bool addSubdirectory(Directory &parent, const std::string &name, Directory &subdirectory)
{
    subdirectory.name = name;
    parent.subdirectories.push_back(subdirectory);
}