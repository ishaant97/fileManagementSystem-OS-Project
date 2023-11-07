#ifndef FILESYSTEM_H
#define FILESYSTEM_H
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stack>

const int MAX_BLOCKS = 1000;
const int MAX_FILES = 100;

struct File
{
    std::string name;
    int size;
    int start_block;
};

struct Directory
{
    string name;
    vector<File> files;
    vector<Directory> subdirectories;
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

stack<Directory> directoryHistory;

#endif