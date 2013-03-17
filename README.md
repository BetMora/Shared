Shared
======
Little shared\utility library mostly features a functions to handle binary files.

Features:
------
* Binary file I/O
* Directory handling
* Some string utilities
* High-resolution timer(processor time)

Planned features:
------
* Data compression
* Basic networking using CURL

Current TODO list
------
* Buffer implementation
* Logging implementation
* Make CMake script determite what OS it is ran on and create Configure.h file based on this. 
Currently we need only Unix/Windows, Little-Endian/Big-Endian defines