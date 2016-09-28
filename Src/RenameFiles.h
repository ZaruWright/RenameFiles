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

private:
	std::string directory;
	std::string nameFiles;
};

