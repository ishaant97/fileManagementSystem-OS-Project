#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void addSubdirectory(Directory &parent, const std::string &name, Directory &subdirectory)
{
    subdirectory.name = name;
    parent.subdirectories.push_back(subdirectory);
}