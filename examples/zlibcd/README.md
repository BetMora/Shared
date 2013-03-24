zlibcd
======
Zlib compression\decompression example

Description
------
Little example to show how to use Shared to compress and decompress any file

Usage
------
zlibcd <input file> <output file> [options]

Available options is:
-c			compression
-d			decompression
-l <level>	level of compression, from 1(fastest) to 9(best)

Note
------
Currently, for decompression it allocates x5 more memory than input file size, should fix this, as it's pretty much for large files
The best way to do this is use compress\decompress instea of inflate\deflate, so we pass, for example, 10kB buffer of compressed data and 30kB buffer for uncompressed data, and repeat decompressing of small chunks untill end of file