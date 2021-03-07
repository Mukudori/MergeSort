
//#include "FileGenerator.h"
#include "MergeSort.h"
#include "ArgsParser.h"
#include <iostream>




int main(int argc, char * argv[])
{
	// for VS debug
	//std::vector<std::string> args = { "sort", "-i", "-d", "result.txt", "in1.txt", "in2.txt", "in3.txt" };
	//ArgsParser parser(args);
	ArgsParser parser(argc, argv); 

	InputArgsStruct aSruct = parser.GetArgsStruct(); 

	
	if (aSruct.IsValide())
	{
		switch (aSruct.Command_ID)
		{
			case ECommand::Sort: {MergeSort ms(aSruct); ms.Sort(); break; }
			default:
				break;
		}
	}
	else
	{
		std::cout << aSruct.ToString(); 
	}


	
	return 0;
}
