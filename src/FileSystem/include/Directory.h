#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

#include <vector>
#include <string>

/*! \brief Directory class provides functions to list all files and sub-directories in choosen root directory
 *
 *	Upon opening directory lists every file and sub-directories in two arrays
 *	One array contains full path to files and directories, and another array contains relative path to them
 */
class Directory
{
public:
	/*! Directory consturctor
	 *! 
	 *  Default directory is working directory
	 */
	Directory(const char* Path = ".");
	~Directory();

	/*!	Opens choosen directory
	 *	\param [in] Name name of directory to open
	 *	\return Nothing
	 */
	void						Open(IN const char* Name);

	/*! Closes directory.
	 *	\return Nothing
	 */
	void						Close();

	/*!	\return true if directory is opened, false if else
	 */
	bool						IsOpened();

	/*!	\return Number of files in total
	 */

	size_t						FilesNum();
	/*! \return Number of directories in total
	 */

	size_t						DirectoriesNum();

	/*! \return Root directory specified upon opening
	 */

	char*						RootDirectory();

	/*! \param [in] Relative if true, will return vector with relative path
	 *	\return std::vector containing all files in root directory
	 */
	std::vector<std::string>	Files(IN bool Relative = false);

	/*! \param [in] Relative if true, will return vector with relative path
	 *	\return std::vector containing all directories in root directory
	 */
	std::vector<std::string>	Directories(IN bool Relative = false);

	/*! Checks if specified file exist in directory
	 *	\param [in] Name name of file to search
	 *	\return Full path to file containing Name if any was found
	 */
	char*						FindFile(IN const char* Name);

	/*! Checks if specified directory exist in directory
	 *	\param [in] Name name of directory to search
	 *	\return Full path to directory containing Name if any was found
	 */
	char*						FindDirectory(IN const char* Name);
private:
	struct DirectoryData;
	DirectoryData*	mData;
};