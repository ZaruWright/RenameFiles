#include <string>

#pragma once
class RenameFiles
{
public:
	RenameFiles() = default;
	RenameFiles(std::string directory, std::string nameFiles) : directory(directory), nameFiles(nameFiles){};
	~RenameFiles() = default;

	void setDirectory(std::string sDirectory){ directory = sDirectory; };
	void setNameFiles(std::string sNameFiles){ nameFiles = sNameFiles; };

	void renameAllDiretoryFiles();


	int howManyFiles();
	void renameFilesAndMoveToAnotherDirectory(std::string Directory, int filesOfDirectory);

private:
	std::string directory;
	std::string nameFiles;
#ifdef _WINDOWS
	std::string separator = "\\";
#else
	std::string separator = "/";
#endif
};

