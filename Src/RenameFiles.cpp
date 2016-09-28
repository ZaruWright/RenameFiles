#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "RenameFiles.h"
#include "dirent.h"

void RenameFiles::renameAllDiretoryFiles()
{
	int filesOfDirectory = howManyFiles();

	/*Calculate the number of zeros thathave the first numbers*/
	int tenMultiply = 10;
	int numberOfZeros = 0;
	while (filesOfDirectory % tenMultiply != filesOfDirectory)
	{
		tenMultiply *= 10;
		++numberOfZeros;
	}

	int currentNumber = 1;
	tenMultiply = 10;
	DIR *dir;
	/* Open directory stream */
	dir = opendir(directory.c_str());
	if (dir != NULL) {
		struct dirent *ent;

		while ((ent = readdir(dir)) != NULL && currentNumber < filesOfDirectory) {
			switch (ent->d_type)
			{
			case DT_REG:

				// Get Number of zeros 
				if (currentNumber % tenMultiply != currentNumber)
				{
					tenMultiply *= 10;
					--numberOfZeros;
				}
				std::string number("");
				for (int i = 0; i < numberOfZeros; ++i)
				{
					number += "0";
				}
				number += std::to_string(currentNumber);

				// Get extension
				std::string name(ent->d_name);
				int j = name.length();
				while (name[j]  != '.')
				{
					--j;
				}
                std::string extension(name.substr(j, name.length()));
                
                // We don't want to rename the DS_Store
                if (extension == ".DS_Store") break;
                
				// Rename
				std::string stringToRename(nameFiles + number + extension);
                    
                #ifdef _WINDOWS
                    std::string separator("\\");
                #else
                    std::string separator("/");
                #endif
                    
				std::string oldName(directory + separator + name);
				std::string newName(directory + separator + stringToRename);
				
				const char * oldNamecstr = oldName.c_str();
				const char * newNamecstr = newName.c_str();
				
				std::rename(oldNamecstr, newNamecstr);
                    
                //std::cout << oldName << "->" << newName << std::endl;

				++currentNumber;
				break;
			}

		}

		closedir(dir);
        std::cout << "Done!" << std::endl;
	}
	else {
		/* Could not open directory */
		std::cout << "Cannot open directory " << directory.c_str() << std::endl;
	}
}

int RenameFiles::howManyFiles()
{
	int numberOfFiles = 0;
	DIR *dir;
	/* Open directory stream */
	dir = opendir(directory.c_str());
	if (dir != NULL) {
		struct dirent *ent;
		while ((ent = readdir(dir)) != NULL) {
			/*Only count files*/
			switch (ent->d_type)
			{
			case DT_REG:
				++numberOfFiles;
				break;
			}
		}
		closedir(dir);
	}
	else {
		/* Could not open directory */
		std::cout << "Cannot open directory " << directory.c_str() << std::endl;
	}

	return numberOfFiles;
}
