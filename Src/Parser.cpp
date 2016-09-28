#include "Parser.h"



void Parser::parse()
{
	options = std::unordered_map<std::string, std::string>();
	if (argc == 1) hasoptions = false;

	int i = 1;
	while (i < argc)
	{
		std::string string(argv[i]);
		if (string.substr(0, 2) == "--")
		{
			std::string subString = string.substr(2, string.length());
			if (subString == "help") options.insert(std::pair<std::string, std::string>(subString, "help"));
			else
			{
				options.insert(std::pair<std::string, std::string>(subString, argv[i + 1]));
				++i;
			}
		}
		else if (string.substr(0, 1) == "-")
		{
			std::string subString = string.substr(1, string.length());
			if (subString == "h") options.insert(std::pair<std::string, std::string>(subString, "h"));
			else
			{
				options.insert(std::pair<std::string, std::string>(subString, argv[i + 1]));
				++i;
			}
		}
		++i;
	}
}

std::string Parser::getOpt(std::string shortCommand, std::string longCommand)
{
	std::string string("");
	if (options.find(shortCommand) != options.end())
	{
		string = options.at(shortCommand);
	}
	else if (options.find(longCommand) != options.end())
	{
		string = options.at(longCommand);
	}

	return string;
}

