/*FileManager.hpp
* Contains classes used
*Author: Jason Goldenberg
*/
#pragma once
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
#include <direct.h>
#include <locale>
#include <sstream>

using namespace std;
using namespace std::experimental::filesystem;

//Create the class for FileManager
class FileManager
{
private:
	path source, destination;
public:
	//Default Constructor
	FileManager();

	//1-Arg Constructor
	FileManager(path source);

	//2-Arg Constructor
	FileManager(path source, path destination);

	//Copy constructor
	FileManager(const FileManager &f);

	//Copy Assignment Operator
	FileManager& operator = (const FileManager &t);

	//Backup method
	void Backup();
	
	//Report method lists the backup state of the file
	void report();
};

struct threes : std::numpunct<char>
{
	std::string do_grouping() const { return "\3"; }
};