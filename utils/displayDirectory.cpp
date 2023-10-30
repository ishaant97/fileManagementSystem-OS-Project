#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void displayDirectory(Directory &directory, Filesystem &fs)
{
    std::cout << "Contents of Directory: " << directory.name << std::endl;

    for (const File &file : directory.files)
    {
        std::cout << "File: " << file.name << " (Size: " << file.size << " KB)" << std::endl;
    }

    for (const Directory &subdirectory : directory.subdirectories)
    {
        std::cout << "Subdirectory: " << subdirectory.name << std::endl;
    }
}