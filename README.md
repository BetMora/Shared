Shared
======
Little shared\utility library mostly features a functions to handle binary files.
Features:
------
* Binary file I/O
* Directory handling(not completely implemented yet) iterational file finding and file finding via wildcard shoul be implemented yet
* Some string utilities

Planned features:
------
* Buffer implementation
* High resolution timer
* Logging
* Data compression
* Basic networking using CURL

Current TODO list
------
* FileSystem::CopyFile currently does not work properly. 
Call trace: FileSystem::CopyFile [OK] -> Stream::WriteRaw [OK] -> File::Write [Fails, data won't get passed into, Data buffer is empty, Size is ok]
* File/direcotry existence check for FileSystem
* Read/Write array for Stream
* Make CMake script determine what OS it is ran on and create Configure.h file based on this. 
Currently we need only Unix/Windows, Little-Endian/Big-Endian defines