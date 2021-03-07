#pragma once

#include "ETypeFile.h"
#include <string>

class FileGenerator
{
	static void GenInteger(std::string fileName, int rows);

	static void GenWords(std::string fileName, int rows);


public:
	static void GenFile(std::string fileName, ETypeFile type, int rows); 

};

