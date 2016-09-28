#include <string>
#include <unordered_map>

#pragma once
class Parser
{
public:


	Parser(int argc, char** argv) :argc(argc), argv(argv), hasoptions(true){};
	~Parser() = default;

	void parse();
	bool hasOptions(){ return hasoptions; }

	std::string getOpt(std::string shortCommand, std::string longCommand);

private:
	int argc;
	char** argv;
	bool hasoptions;
	std::unordered_map<std::string, std::string> options;


};

