#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "RenameFiles.h"
#include "dirent.h"

#ifndef _WINDOWS
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
#endif

void RenameFiles::renameAllDiretoryFiles()
{
	std::string tmpDirectory("tmp");
    
    #ifdef _WINDOWS
    CreateDirectory(std::string(directory + separator + tmpDirectory).c_str(), nullptr);
    #else
    mkdir(std::string(directory + separator + tmpDirectory).c_str(), 0777);
    #endif
	
	int filesOfDirectory = howManyFiles();
	renameFilesAndMoveToAnotherDirectory(tmpDirectory, filesOfDirectory);

	DIR *dir;
	dir = opendir(std::string(directory + separator + tmpDirectory).c_str());

	if (dir != NULL) {
		struct dirent *ent;

		while ((ent = readdir(dir)) != NULL) {
			switch (ent->d_type)
			{
			case DT_REG:

				// Get extension
				std::string name(ent->d_name);
				int j = name.length() - 1;
				while (name[j]  != '.')
				{
					--j;
				}
                std::string extension(name.substr(j, name.length()));
                
                
                // We don't want to rename the DS_Store
				if (extension == ".DS_Store")
				{
					--filesOfDirectory; 
					break;
				}
                    
				std::string tmpName(directory + separator + tmpDirectory + separator + name);
				std::string newName(directory + separator + name);
				
				const char * tmpNamecstr = tmpName.c_str();
				const char * newNamecstr = newName.c_str();
				
				std::rename(tmpNamecstr, newNamecstr);
                    
                //std::cout << tmpName << "->" << newName << std::endl;

				break;
			}

		}

		closedir(dir);
        std::cout << "Done!" << std::endl;
	}
	else {
		
		std::cout << "Cannot open directory. RenameFiles::renameAllDiretoryFiles " << directory.c_str() << std::endl;
	}
    
    #ifdef _WINDOWS
    RemoveDirectory(std::string(directory + separator + tmpDirectory).c_str());
    #else
    rmdir(std::string(directory + separator + tmpDirectory).c_str());
    #endif
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
		std::cout << "Cannot open directory. RenameFiles::howManyFiles" << directory.c_str() << std::endl;
	}

	return numberOfFiles;
}

void RenameFiles::renameFilesAndMoveToAnotherDirectory(std::string tmpDirectory, int filesOfDirectory)
{
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

		while ((ent = readdir(dir)) != NULL && currentNumber <= filesOfDirectory) {
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
				int j = name.length() - 1;
				while (name[j]  != '.')
				{
					--j;
				}
                std::string extension(name.substr(j, name.length()));
                
                
                // We don't want to rename the DS_Store
				if (extension == ".DS_Store")
				{
					--filesOfDirectory; 
					break;
				}
                
				// Rename
				std::string stringToRename(nameFiles + number + extension);
                    
				std::string oldName(directory + separator + name);
				std::string newName(directory + separator + tmpDirectory + separator + stringToRename);
				
				const char * oldNamecstr = oldName.c_str();
				const char * newNamecstr = newName.c_str();
				
				std::rename(oldNamecstr, newNamecstr);
                    
                //std::cout << oldName << "->" << newName << std::endl;

				++currentNumber;
				break;
			}

		}

		closedir(dir);
	}
	else {
		/* Could not open directory */
		std::cout << "Cannot open directory. RenameFiles::renameFilesAndMoveToAnotherDirectory " << directory.c_str() << std::endl;
	}
}
