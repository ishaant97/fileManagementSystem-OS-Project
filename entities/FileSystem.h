// Filesystem.h

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <string>
#include <vector>

const int MAX_BLOCKS = 100;
const int MAX_FILES = 100;

struct File
{
    std::string name;
    int size;
    int start_block;
};

struct Directory
{
    std::string name;
    std::vector<File> files;
    std::vector<Directory> subdirectories;
};

struct DiskBlock
{
    int used;
    int file_index;
};

struct Filesystem
{
    File files[MAX_FILES];
    Directory root;
    DiskBlock blocks[MAX_BLOCKS];
};

#endif // FILESYSTEM_H