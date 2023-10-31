#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void deleteDirectory(Directory &parent, const std::string &dirName)
{
    for (size_t i = 0; i < parent.subdirectories.size(); ++i)
    {
        if (parent.subdirectories[i].name == dirName)
        {
            // Check if the directory is empty before deleting it
            if (!parent.subdirectories[i].files.empty() || !parent.subdirectories[i].subdirectories.empty())
            {
                std::cout << "Directory is not empty. Cannot delete." << std::endl;
                return;
            }

            // Remove the directory
            parent.subdirectories.erase(parent.subdirectories.begin() + i);
            std::cout << "Directory '" << dirName << "' deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Directory not found: " << dirName << std::endl;
}