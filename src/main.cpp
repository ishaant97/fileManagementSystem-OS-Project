#include <iostream>

using namespace std;
#include "../entities/FileSystem.h"
#include "../utils/addFileToDirectory.cpp"
#include "../utils/addSubdirectory.cpp"
#include "../utils/calculateWastedDiskSpace.cpp"
#include "../utils/calculateDiskFragmentation.cpp"
#include "../utils/displayDirectory.cpp"
#include "../utils/findFreeBlocks.cpp"
#include "../utils/renameDirectory.cpp"
#include "../utils/renameFile.cpp"
#include "../utils/deleteDirectory.cpp"
#include "../utils/deleteFile.cpp"

int main()
{
    Filesystem fs;
    string name;
    string subDirName;
    string targetDir;
    Directory newDirectory;
    string oldName;
    string newName;
    string oldDirName;
    string newDirName;
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
        cout << "\nFile System Simulation Menu:" << endl;
        cout << "1. Store a file" << endl;
        cout << "2. List contents of the current directory" << endl;
        cout << "3. Create a subdirectory" << endl;
        cout << "4. Navigate to different directory" << endl;
        cout << "5. Rename a file" << endl;
        cout << "6. Rename a directory" << endl;
        cout << "7. Defragment the disk" << endl;
        cout << "8. Calculate Wasted Disk Space" << endl;
        cout << "9. Delete a file" << endl;
        cout << "10. Delete a directory" << endl;
        cout << "11. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        // std::cout << "------------------------------------------------------";
        int fragmentedBlocks = 0;
        int totalBlocks = 0;

        switch (choice)
        {
        case 1:
            cout << "Enter file name: ";
            cin >> name;
            cout << "Enter file size (in KB): ";
            cin >> size;

            start_block = findFreeBlocks(fs, size); // Initialize start_block here

            if (start_block == -1)
            {
                cout << "Disk is full. Cannot store the file: " << name << endl;
                cout << "------------------------------------------------------" << endl;
                break;
            }

            addFileToDirectory(currentDirectory, name, size, start_block);

            for (int i = start_block; i < start_block + size; i++)
            {
                fs.blocks[i].used = 1;
                fs.blocks[i].file_index = currentDirectory.files.size() - 1;
            }

            cout << "File stored successfully: " << name << endl;
            cout << "------------------------------------------------------" << endl;
            break;

        case 2:
            displayDirectory(currentDirectory, fs);
            std::cout << "------------------------------------------------------" << endl;
            break;

        case 3:
            std::cout << "Enter subdirectory name: ";
            std::cin >> subDirName;
            if (addSubdirectory(currentDirectory, subDirName, newDirectory))
            {
                std::cout << "Subdirectory Created successfully: " << subDirName << std::endl;
                std::cout << "------------------------------------------------------";
                break;
            }
            else
            {
                std::cout << "Error Creating Subdirectory" << std::endl;
                std::cout << "------------------------------------------------------";
                break;
            }
        case 4:
            std::cout << "Enter directory name to navigate to (or use '..' to go up): ";
            std::cin >> targetDir;

            if (targetDir == "..")
            {
                if (!directoryHistory.empty())
                {
                    currentDirectory = directoryHistory.top(); // Go up one level
                    directoryHistory.pop();
                    std::cout << "You are successfully navigated to on level up" << std::endl;
                    std::cout << "------------------------------------------------------";
                }
                else
                {
                    std::cout << "You are already at the root directory." << std::endl;
                    std::cout << "------------------------------------------------------";
                }
            }
            else
            {
                // Search for the desired subdirectory
                for (auto &subdirectory : currentDirectory.subdirectories)
                {
                    if (subdirectory.name == targetDir)
                    {
                        // Push the current directory to the history
                        directoryHistory.push(currentDirectory);
                        currentDirectory = subdirectory;
                        std::cout << "You are successfully navigated to: " << targetDir << std::endl;
                        std::cout << "------------------------------------------------------";
                        break;
                    }
                }
            }
            // std::cout << targetDir << "Not Found" << std::endl;
            break;

        case 5:
            std::cout << "Enter the name of the file to rename: ";
            std::cin >> oldName;
            std::cout << "Enter the new name for the file: ";
            std::cin >> newName;
            renameFile(currentDirectory, oldName, newName);
            std::cout << oldName << "was successfully renamed to " << newName << std::endl;
            std::cout << "------------------------------------------------------";
            break;

        case 6:
            std::cout << "Enter the name of the directory to rename: ";
            std::cin >> oldDirName;
            std::cout << "Enter the new name for the directory: ";
            std::cin >> newDirName;
            renameDirectory(currentDirectory, oldDirName, newDirName);
            std::cout << oldDirName << "was successfully renamed to " << newDirName << std::endl;
            std::cout << "------------------------------------------------------";
            break;

        case 7:
            fragmentedBlocks = calculateDiskFragmentation(fs);
            for (int i = 0; i < MAX_BLOCKS; i++)
            {
                if (fs.blocks[i].used == 1)
                {
                    totalBlocks++;
                }
            }
            std::cout << "Disk Fragmentation: " << fragmentedBlocks << " out of " << totalBlocks << " blocks." << std::endl;
            std::cout << "------------------------------------------------------";
            break;

        case 8:
            std::cout << "Wasted Disk Space: " << calculateWastedDiskSpace(fs) << "KB" << std::endl;
            std::cout << "------------------------------------------------------";
            break;

        case 9:
            std::cout << "Enter the name of the file to delete: ";
            std::cin >> name;
            deleteFile(currentDirectory, name, fs);
            std::cout << name << "was successfully deleted" << std::endl;
            std::cout << "------------------------------------------------------";
            break;

        case 10:
            std::cout << "Enter the name of the directory to delete: ";
            std::cin >> subDirName;
            deleteDirectory(currentDirectory, subDirName);
            std::cout << subDirName << "was successfully deleted" << std::endl;
            std::cout << "------------------------------------------------------";
            break;

        case 11:
            std::cout << "Exiting the program." << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cout << "------------------------------------------------------";
        }
    }

    return 0;
}