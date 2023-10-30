#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"
#include "../utils/addFileToDirectory.cpp"
#include "../utils/addSubdirectory.cpp"
#include "../utils/calculateWastedDiskSpace.cpp"
#include "../utils/defragmentDisk.cpp"
#include "../utils/displayDirectory.cpp"
#include "../utils/findFreeBlocks.cpp"
#include "../utils/renameDirectory.cpp"
#include "../utils/renameFile.cpp"

int main()
{
    Filesystem fs;
    std::string name;
    std::string subDirName;
    std::string targetDir;
    Directory newDirectory;
    std::string oldName;
    std::string newName;
    std::string oldDirName;
    std::string newDirName;
    int start_block; // Declare start_block here
    int size;        // Declare size here

    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        fs.blocks[i].used = 0;
        fs.blocks[i].file_index = -1;
    }

    fs.root.name = "Root";

    Directory currentDirectory = fs.root;

    while (true)
    {
        std::cout << "\nFile System Simulation Menu:" << std::endl;
        std::cout << "1. Store a file" << std::endl;
        std::cout << "2. List contents of the current directory" << std::endl;
        std::cout << "3. Create a subdirectory" << std::endl;
        std::cout << "4. Change current directory" << std::endl;
        std::cout << "5. Rename a file" << std::endl;
        std::cout << "6. Rename a directory" << std::endl;
        std::cout << "7. Defragment the disk" << std::endl;
        std::cout << "8. Calculate Wasted Disk Space" << std::endl;
        std::cout << "9. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter file name: ";
            std::cin >> name;
            std::cout << "Enter file size (in KB): ";
            std::cin >> size;

            start_block = findFreeBlocks(fs, size); // Initialize start_block here

            if (start_block == -1)
            {
                std::cout << "Disk is full. Cannot store the file: " << name << std::endl;
                break;
            }

            addFileToDirectory(currentDirectory, name, size, start_block);

            for (int i = start_block; i < start_block + size; i++)
            {
                fs.blocks[i].used = 1;
                fs.blocks[i].file_index = currentDirectory.files.size() - 1;
            }

            std::cout << "File stored successfully: " << name << std::endl;
            break;

        case 2:
            displayDirectory(currentDirectory, fs);
            break;

        case 3:
            std::cout << "Enter subdirectory name: ";
            std::cin >> subDirName;
            addSubdirectory(currentDirectory, subDirName, newDirectory);
            break;

        case 4:
            std::cout << "Enter directory name to navigate to: ";
            std::cin >> targetDir;

            for (auto &subdirectory : currentDirectory.subdirectories)
            {
                if (subdirectory.name == targetDir)
                {
                    currentDirectory = subdirectory;
                    break;
                }
            }
            break;

        case 5:
            std::cout << "Enter the name of the file to rename: ";
            std::cin >> oldName;
            std::cout << "Enter the new name for the file: ";
            std::cin >> newName;
            renameFile(fs, oldName, newName);
            break;

        case 6:
            std::cout << "Enter the name of the directory to rename: ";
            std::cin >> oldDirName;
            std::cout << "Enter the new name for the directory: ";
            std::cin >> newDirName;
            renameDirectory(currentDirectory, oldDirName, newDirName);
            break;

        case 7:
            defragmentDisk(fs);
            break;

        case 8:
            std::cout << "Wasted Disk Space: " << calculateWastedDiskSpace(fs) << " blocks" << std::endl;
            break;

        case 9:
            std::cout << "Exiting the program." << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}