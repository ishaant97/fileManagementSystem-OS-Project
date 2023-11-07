#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void displayDirectory(Directory directory, Filesystem fs)
{
    cout << "Contents of " << directory.name << " directory: " << endl;

    for (const File file : directory.files)
    {
        cout << "\t File: " << file.name << " (Size: " << file.size << " KB)" << endl;
    }

    for (const Directory subdirectory : directory.subdirectories)
    {
        cout << "\t Subdirectory: " << subdirectory.name << endl;
    }
}