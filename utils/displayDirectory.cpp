#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void displayDirectory(Directory &directory, Filesystem &fs)
{
    std::cout << "Contents of " << directory.name << " directory: " << std::endl;

    for (const File &file : directory.files)
    {
        std::cout << "\t File: " << file.name << " (Size: " << file.size << " KB)" << std::endl;
    }

    for (const Directory &subdirectory : directory.subdirectories)
    {
        std::cout << "\t Subdirectory: " << subdirectory.name << std::endl;
    }
}