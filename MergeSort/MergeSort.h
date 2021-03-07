#pragma once
#include "InputArgsStruct.h"
#include <fstream>
#include <iostream>





class MergeSort
{
	InputArgsStruct Args; 

	std::vector<std::fstream> inputFiles; 
	std::ofstream outputFile; 
	std::vector<int> intData;
	std::vector<std::string> strData; 
	std::vector<bool> useData; 
	

	struct SMinMax {
		int f_index = -1;
		std::string sVal;
		int iVal; 
	};	

	struct SData {
		std::string sVal = "";
		int iVal = -1; 
		bool isValid = false; 
	};	 

	SData ReadInt(const int& f_index);
	
	SData ReadStr(const int& f_index);

	SData ReadData(const int& f_index);
	
	SMinMax GetMin();

	SMinMax GetMax();

	
	void Write(const int& val);	

	void Write(const std::string& val);

	void Write(const SMinMax& val);

	bool existingInput();

	void init();

	void  stop();	

	void SortInt(); 

	void SortStr(); 

public:

	MergeSort(const InputArgsStruct& argsStruct);
	~MergeSort(); 

	void Sort(); 
};

