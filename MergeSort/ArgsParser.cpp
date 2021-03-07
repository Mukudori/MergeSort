#include "ArgsParser.h"
#include <stdexcept>  
#include <iostream>



void ArgsParser::init(const std::vector<std::string>& args)
{      
    
    if (args.size() < 4)
    {
        std::cout << "Parser Error: Few arguments. At least 4 is expected.";
        return;
    }    
    
    const unsigned command = 0; 
    const unsigned type = 1; 
    const unsigned mode = 2; 
    unsigned output = 3; 
    unsigned input = 4; 
   
    argsStruct.Clear(); 

    // arg 0 : command ID

    if (mCom.find(args[command]) != mCom.end())
        argsStruct.Command_ID = mCom.at(args[command]);
    else
        return; 

   
    // arg 1 : type {-i, -s}

    if (mTypeF.find(args[type]) != mTypeF.end())
        argsStruct.TypeFile_ID = mTypeF.at(args[type]);
    else
        return;


    // arg 2 : mode {-a, -d} || output_file

    if (mMode.find(args[mode]) != mMode.end())
    {        
        argsStruct.Mode_ID = mMode.at(args[mode]);
    }
    else 
    {
        input = output; 
        output = mode; 
    }

    // 3,4 || 4,5 : output, input files

    argsStruct.OutputFile = args[output]; 
    for (unsigned i = input; i < args.size(); i++)
        argsStruct.InputFilesVector.push_back(args[i]);    
   

}



ArgsParser::ArgsParser(const std::vector<std::string>& args)
{  
    init(args);
}

ArgsParser::ArgsParser(int argc, char* argv[])
{
    std::vector < std::string> vArgs; 
    if (argc > 1) vArgs.assign(argv + 1, argv + argc);

    init(vArgs); 
}

InputArgsStruct ArgsParser::GetArgsStruct() const
{
    if (!argsStruct.IsValide())
        std::cout << "Parser Error: args invalide";
    return argsStruct;
}

