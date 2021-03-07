#include "FileGenerator.h"
#include <fstream>
#include <iostream>
#include  <cstdlib>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <direct.h>

void FileGenerator::GenInteger(std::string fileName, int rows)
{
	std::cout << "Generate Integer file started. \n";
	struct stat info;
	const char* inputPath = "gen_files/";

	_mkdir(inputPath);


	std::ofstream file(inputPath + fileName + std::to_string(1) + ".txt");

	for (int i = 0; i < rows; i++)
	{
		int val = rand() % rows;
		file << val << "\n";
		std::cout << i <<" "<< val << "\n";
	}	
	file.close(); 
	std::cout << "GENERATE INT FILE FINISHED "; 
	
}

void FileGenerator::GenWords(std::string fileName, int rows)
{
}

void FileGenerator::GenFile(std::string fileName, ETypeFile type, int rows)
{
	switch (type)
	{
	case ETypeFile::Integer: GenInteger(fileName, rows);
			break; 
	case ETypeFile::String : GenWords(fileName, rows);
	}
}
