#include <iostream>
#include <string>
#include "Parser.h"
#include "RenameFiles.h"

int main(int argc, char **argv)
{
	
	
	Parser parser(argc, argv);
	parser.parse();

	RenameFiles renameFiles = RenameFiles();

	std::string option = parser.getOpt("h", "help");
	if (!option.empty() || !parser.hasOptions())
	{
		std::cout << "Usage: " << std::endl
			<< "-d/--directory : The directory that you want to rename the files" << std::endl
			<< "-n/--name      : The name to rename the files" << std::endl
			<< "-h/--help      : Show the options of the program" << std::endl;
		return 0;
	}

	option = parser.getOpt("d", "directory");
	if (!option.empty())
	{
		renameFiles.setDirectory(option);
	}

	option = parser.getOpt("n", "name");
	if (!option.empty())
	{
		renameFiles.setNameFiles(option);
	}

	renameFiles.renameAllDiretoryFiles();
	
	return 0;
}