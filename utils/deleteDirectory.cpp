#include <iostream>
using namespace std;
#include "../entities/FileSystem.h"

void deleteDirectory(Directory &parent, const std::string &dirName)
{
    for (size_t i = 0; i < parent.subdirectories.size(); ++i)
    {
        if (parent.subdirectories[i].name == dirName)
        {
            if (!parent.subdirectories[i].files.empty() || !parent.subdirectories[i].subdirectories.empty())
            {
                std::cout << "Directory is not empty. Cannot delete." << std::endl;
                return;
            }
            parent.subdirectories.erase(parent.subdirectories.begin() + i);
            cout << "Directory '" << dirName << "' deleted successfully." << endl;
            return;
        }
    }
    cout << "Directory not found: " << dirName << endl;
}