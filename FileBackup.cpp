/*Program: Filebackup.exe
*Author: Jason Goldenberg
*Version: 1.01
*Date: February 14, 2019
*Purpose: to create a program that backups specific files from a location to a destination
*File: Filebackup.cpp
*/
#include "FileManager.hpp"

int main(int argc, char * argv[])
{
	//Parse command line
	if (argc == 3)
	{
		//Creates file manager object with 2-arg c'tor
		FileManager w(argv[1], argv[2]);
		w.Backup();
		w.report();
		
	}
	else if (argc == 2)
	{
		//Create file manager object with 1-arg c'tor
		FileManager x(argv[1]);
		x.Backup();
		x.report();
	}
	else if (argc == 1)
	{
		//Create file manager object using default c'tor
		FileManager q;
		q.Backup();
		q.report();
	}
	
	system("pause");
}