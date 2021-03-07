#pragma once
#include "InputArgsStruct.h"
#include <map>
#include <vector>

class ArgsParser
{
	InputArgsStruct argsStruct; 

  
   std::map<std::string, ECommand> mCom = {
      //  {"generate", ECommand::Generate},
        {"sort", ECommand::Sort},    
        {"Sort", ECommand::Sort}           
    };

    std::map<std::string, ETypeFile> mTypeF = {
        {"-i", ETypeFile::Integer},
        {"-I", ETypeFile::Integer},
        {"-s", ETypeFile::String},
        {"-S", ETypeFile::String}
    };

    std::map<std::string, ETypeSort> mMode = {
        {"-a", ETypeSort::Increase},
        {"-A", ETypeSort::Increase},
        {"-d", ETypeSort::Decrease},
        {"-D", ETypeSort::Decrease},
    };	
	
	void init(const std::vector<std::string> &args);

 


public:

    ArgsParser(const std::vector<std::string> &args);

    ArgsParser(int argc, char* argv[]);

    InputArgsStruct GetArgsStruct() const;
};

