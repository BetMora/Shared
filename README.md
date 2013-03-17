Shared
======
Little library aimed to provide features to work with binary files(data serialization\deserialization)

Features:
------
* Binary file I/O
* Directory handling
* String utilities
* High-resolution timer(processor time, 1ms resolution on my system)
* Very-very basic logging

Planned features:
------
* Data compression
* Basic networking using CURL

Current TODO list
------
* Buffer implementation
* Make CMake script determite what OS it is ran on and create Configure.h file based on this. 
Currently we need only Unix/Windows, Little-Endian/Big-Endian defines