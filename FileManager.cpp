/*FileManager.cpp
* contains code for classes
* Author: Jason Goldenberg
*/
#include "FileManager.hpp"

FileManager::FileManager()
{
	//Create new directory
	_mkdir("C://backup");
	//Make source current working directory
	source = ".";
	destination = "C:\\backup";

}

FileManager::FileManager(path mySource)
{
	//Create new directory
	_mkdir("C://backup");
	source = mySource;
	destination = "C:\\backup";
	int counter = 0;
}

FileManager::FileManager(path mySource, path myDestination)
{
	recursive_directory_iterator dir(source);
	recursive_directory_iterator end;

	source = mySource;
	destination = myDestination;

}

FileManager::FileManager(const FileManager & f)
{
	cout << "Copy constructor called" << endl;
	source = f.source;
	destination = f.destination;
}

FileManager & FileManager::operator=(const FileManager & t)
{
	cout << "Copy-assignment operator called" << endl;
	source = t.source;
	destination = t.destination;
	return *this;
}

//Backup method will backup any source files stored in the source directory to the backup directory
void FileManager::Backup()
{
	//Check source/destination folder
	recursive_directory_iterator dir(source);
	recursive_directory_iterator end;

	while (dir != end)
	{
		//Find specific files with the correct extensions
		if (dir->path().filename().extension().string() == ".cpp" ||
			dir->path().filename().extension().string() == ".hpp" ||
			dir->path().filename().extension().string() == ".c" ||
			dir->path().filename().extension().string() == ".h")
		{
			copy(dir->path(), destination);
		}
		++dir;
	}



}

//Report method lists the backup state of the file
void FileManager::report()
{
	//makes number output comma separated
	cout.imbue(std::locale(std::cout.getloc(), new threes));

	cout << "Root Directory: " << current_path() << endl;
	cout << "Backup Directory: " << destination << endl;

	recursive_directory_iterator dir(destination);
	recursive_directory_iterator end;

	int counter = 0;

	while (dir != end)
	{
		
		int length = dir->path().filename().string().length();
			cout <<right<< "+ " << dir->path().filename() << setw(40 - length) << "Size: " << file_size(dir->path()) << endl;
			counter++;

		++dir;
	}

	cout << "Backup Total: " << setw(23) << counter << endl;
}
