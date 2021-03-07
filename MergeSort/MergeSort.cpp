#include "MergeSort.h"
#include <iostream>


MergeSort::SData MergeSort::ReadInt(const int& f_index) {

	SData result;
	inputFiles[f_index] >> result.iVal;
	result.isValid = !inputFiles[f_index].fail() ;
		
;
	if (inputFiles[f_index].eof() && inputFiles[f_index].is_open())
	{
		inputFiles[f_index].close();
		std::cout << "Close file " << Args.InputFilesVector[f_index] + '\n'; 
	}

	// if fail
	if (!result.isValid && inputFiles[f_index].is_open())
	{
		std::cout << "Sort Error : faild to read int value in " + Args.InputFilesVector[f_index] + '\n';		
		//stop();

		useData[f_index] = false; 
		inputFiles[f_index].close();
		std::cout << "Close file " << Args.InputFilesVector[f_index] + '\n';
	}
	
	return result;
}

MergeSort::SMinMax MergeSort::GetMin()
{
	SMinMax result;
	bool res_init = false;

	switch (Args.TypeFile_ID)
	{
	case ETypeFile::Integer:
	{

		for (int i = 0; i < intData.size(); i++)
		{
			if (!res_init && useData[i])
			{
				result.f_index = i;
				result.iVal = intData[i];
				res_init = true;
				continue;
			}
			if (result.iVal > intData[i] && useData[i])
			{
				result.f_index = i;
				result.iVal = intData[i];

			}
		}

		break;
	}

	case ETypeFile::String:
		for (int i = 0; i < strData.size(); i++)
		{
			if (!res_init && useData[i])
			{
				result.f_index = i;
				result.sVal = strData[i];
				res_init = true;
				continue;
			}
			if (result.sVal > strData[i] && useData[i])
			{
				result.f_index = i;
				result.sVal = strData[i];
			}

		}
		break;
	default:
		break;
	}

	return result;
}


MergeSort::SMinMax MergeSort::GetMax()
{
	SMinMax result;
	bool res_init = false;

	switch (Args.TypeFile_ID)
	{
	case ETypeFile::Integer:
	{

		for (int i = 0; i < intData.size(); i++)
		{
			if (!res_init && useData[i])
			{
				result.f_index = i;
				result.iVal = intData[i];
				res_init = true;
				continue;
			}
			if (result.iVal < intData[i] && useData[i])
			{
				result.f_index = i;
				result.iVal = intData[i];

			}
		}

		break;
	}

	case ETypeFile::String:
		for (int i = 0; i < strData.size(); i++)
		{
			if (!res_init && useData[i])
			{
				result.f_index = i;
				result.sVal = strData[i];
				res_init = true;
				continue;
			}
			if (result.sVal < strData[i] && useData[i])
			{
				result.f_index = i;
				result.sVal = strData[i];
			}

		}
		break;
	default:
		break;
	}

	return result;
}

void MergeSort::Write(const int& val)
{
	if (!(outputFile << val << '\n'))
	{
		std::cout << "Sort Error : faild to write int file " + Args.OutputFile + '\n';
		stop();
	}
	else
		std::cout << "Write " << val << '\n'; 
}
void MergeSort::Write(const std::string& val)
{
	if (!(outputFile << val << '\n'))
	{
		std::cout << "Sort Error : faild to write str file " + Args.OutputFile + '\n';
		stop();
	}
	else
		std::cout << "Write " << val << '\n';
}

void MergeSort::Write(const SMinMax& val)
{
	if (!outputFile.is_open())
	{
		outputFile.open(Args.OutputFile);

		if (outputFile.fail())
		{
			std::cout << "Sort Error : faild to open file " + Args.OutputFile + '\n';
			stop();
			return;
		}
		
	}

	switch (Args.TypeFile_ID)
	{
	case ETypeFile::Integer: Write(val.iVal); break;
	case ETypeFile::String: Write(val.sVal); break;
	default:
		break;
	}

}

bool MergeSort::existingInput()
{
	for (int i=0; i<inputFiles.size(); i++)
		if (inputFiles[i].is_open() || useData[i])
			return true;
	return false;
}

void MergeSort::init()
{
	inputFiles.reserve(Args.InputFilesVector.size()); 
	useData.reserve(Args.InputFilesVector.size()); 
	for (const std::string filePath : Args.InputFilesVector)
	{
		inputFiles.push_back(std::fstream(filePath, std::ios::in));

		if (inputFiles.back().fail())
		{
			std::cout << "Sort Error : faild to open file " + filePath + '\n';
			stop();
			return;
		}	
		useData.push_back(true); 

	}

	switch (Args.TypeFile_ID)
	{
		case ETypeFile::Integer: intData.resize(inputFiles.size()); break; 
		case ETypeFile::String:	 strData.resize(inputFiles.size()); break; 
	default:
		break;
	}
	
}

void MergeSort::stop()
{
	for (std::fstream& stream : inputFiles)
		stream.close();
}

MergeSort::~MergeSort()
{
	stop(); 	
}

MergeSort::MergeSort(const InputArgsStruct& argsStruct)
{
	if (argsStruct.InputFilesVector.size() > 1)
	{
		Args = argsStruct;
		init();
	}
	else
	{
		std::cout << "Sort Error : Too few input files. Need to not less 2\n"; 
	}
	
}

void MergeSort::Sort()
{
	if (!existingInput())
	{
		std::cout << "Sort Error : Can't start sort. \n";
	}
	else
	{
		switch (Args.TypeFile_ID)
		{
		case ETypeFile::Integer: SortInt(); break; 
		case ETypeFile::String: SortStr(); break;
		default:
			break;
		}

		outputFile.close(); 
	}

}




MergeSort::SData MergeSort::ReadStr(const int& f_index)
{
	SData result;
	inputFiles[f_index] >> result.sVal;
	result.isValid = !inputFiles[f_index].fail();

	
	if (inputFiles[f_index].eof() && inputFiles[f_index].is_open())
	{
		inputFiles[f_index].close();
		std::cout << "Close file " << Args.InputFilesVector[f_index] + '\n';
	}

	// if fail
	if (!result.isValid && inputFiles[f_index].is_open())
	{
		std::cout << "Sort Error : faild to read int value in " + Args.InputFilesVector[f_index] + '\n';
		//stop();

		useData[f_index] = false;
		inputFiles[f_index].close();
		std::cout << "Close file " << Args.InputFilesVector[f_index] + '\n';
	}

	return result;
}

MergeSort::SData MergeSort::ReadData(const int& f_index)
{
	SData data; 
	if (inputFiles[f_index].is_open())
	{
		switch (Args.TypeFile_ID)
		{
		case ETypeFile::Integer:
		{
			data = ReadInt(f_index);
			if (data.isValid) {
				intData[f_index] = data.iVal;
				std::cout << "Read " << data.iVal << " from " + Args.InputFilesVector[f_index] + '\n';
			}
			else
				std::cout << "Read failed from " + Args.InputFilesVector[f_index] + '\n';		
			break;
		}

		case ETypeFile::String:
		{
			data = ReadStr(f_index);			
			if (data.isValid) {
				strData[f_index] = data.sVal;
				std::cout << "Read " << data.sVal << " from " + Args.InputFilesVector[f_index] + '\n';
			}
			else
				std::cout << "Read failed from " + Args.InputFilesVector[f_index] + '\n';
			break; 
		
		}
		default:
			break;
		}
	}
	else
		std::cout << "File " << Args.InputFilesVector[f_index] << " closed already\n";
	return data;
}

void MergeSort::SortInt() {
	for (int i = 0; i < inputFiles.size(); i++)
	{
		SData sv = ReadData(i);
		if (sv.isValid)
			intData[i] = sv.iVal;
		else
		{
			std::cout << "Sort Integers Error : Initialization first value is faild. File " + Args.InputFilesVector[i] + " is corrupted.\n";
			return;
		}
	}

	SMinMax last_value;
	SData r_val;

	while (existingInput()) {

		if (Args.Mode_ID == ETypeSort::Increase)
			last_value = GetMin();
		else
			last_value = GetMax();

		if (last_value.f_index != -1)
			Write(last_value);
		else
		{
			std::cout << "Sort Error : Failed to get min/max \n";
			break;
		}
	
		r_val = ReadData(last_value.f_index);
		if (!r_val.isValid)	useData[last_value.f_index] = false;		

	}
	std::cout << "Merging complite. File " + Args.OutputFile + " is saved."; 
}

void MergeSort::SortStr() {
	// Copy-paste, but generics do pretty much the same thing.
	// In the case of C++, I had to do this.

	for (int i = 0; i < inputFiles.size(); i++)
	{
		SData sv = ReadData(i);
		if (sv.isValid)
			strData[i] = sv.sVal;
		else
		{
			std::cout << "Sort String Error : Initialization first value is faild. File " + Args.InputFilesVector[i] + " is corrupted.\n";
			return;
		}
	}

	SMinMax last_value;
	SData r_val;

	while (existingInput()) {

		if (Args.Mode_ID == ETypeSort::Increase)
			last_value = GetMin();
		else
			last_value = GetMax();

		if (last_value.f_index != -1)
			Write(last_value);
		else
		{
			std::cout << "Sort Error : Failed to get min/max \n";
			break;
		}

		r_val = ReadData(last_value.f_index);
		if (!r_val.isValid)	useData[last_value.f_index] = false; 				
		
	}
	std::cout << "MERGING COMPLITE. File " + Args.OutputFile + " is saved.";
}