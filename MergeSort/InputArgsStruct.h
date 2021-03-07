#pragma once
#include "ECommand.h"
#include "ETypeFile.h"
#include "ETypeSort.h"
#include <string>
#include <vector>

struct InputArgsStruct {
	ECommand Command_ID = ECommand::None; 
	ETypeFile TypeFile_ID = ETypeFile::None; 
	ETypeSort Mode_ID = ETypeSort::Increase; 
	std::string OutputFile = "None"; 
	std::vector<std::string> InputFilesVector; 

	void Clear() {
		Command_ID = ECommand::None;
		TypeFile_ID = ETypeFile::None;
		Mode_ID = ETypeSort::Increase;
		OutputFile = "None";
		InputFilesVector.clear();
	}

	bool IsValide() const {
		if (Command_ID == ECommand::None)
			return false;
		if (TypeFile_ID == ETypeFile::None)
			return false; 
		if (OutputFile.compare("None") == 0)
			return false;
		if (InputFilesVector.size() == 0)
			return false;

		return true; 
	}

	std::string ToString() const
	{
		std::string out; 
		out.append("\nInputArgsStruct { \n"); 
		out.append("Command_ID : " + std::to_string((int)Command_ID) + '\n');
		out.append("TypeFile_ID : " + std::to_string((int)TypeFile_ID) + '\n');
		out.append("Mode_ID : " + std::to_string((int)Mode_ID) + '\n');
		out.append("OutputFile : " + OutputFile + '\n');
		out.append("InputFilesVector : [ ");
		
		if (InputFilesVector.size() > 0)
		{
			int i;
			for (i = 0; i < (int)(InputFilesVector.size() - 1); i++)
				out.append(InputFilesVector[i] + ", ");
			out.append(InputFilesVector[i] + " ]\n");
		}
		else out.append(" ]\n");
		

		out.append("\nIs Valide : "); 
		if (IsValide())
			out.append("true\n");
		else 
			out.append("false\n");
		out.append("}\n");

		return out; 

	}
};