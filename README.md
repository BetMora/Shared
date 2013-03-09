Shared
======
Little shared\utility library mostly features a functions to handle binary files.
Features:
------
* Binary file I/O
* Directory handling(not completely implemented yet)
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
* Make CMake script determine what OS it is ran on and create Configure.h file based on this. 
Currently we need only Unix/Windows, Little-Endian/Big-Endian defines
* Test array writing to binary files
