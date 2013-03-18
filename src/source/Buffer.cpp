#include "Buffer.h"

#include <memory>

struct BufferData
{
	// the actual size of data inside buffer
	size_t	Size;
	// maximum size of data that could be put in buffer
	size_t	Capacity;
	// current position for seeking, writing, reading
	uint8*	Pointer;
	// the data itself
	uint8*	Data;

	BufferData()
	{
		Size = 0;
		Capacity = 0;
		Pointer = 0;
		Data = 0;
	}

	~BufferData()
	{
		Size = 0;
		Capacity = 0;
		Pointer = 0;
		delete [] Pointer;
		delete [] Data;
	}
};

Buffer::Buffer(size_t Size)
{
	mData = new BufferData();

	Allocate(Size);
}

Buffer::~Buffer()
{
	Clear();

	delete mData;
}

size_t Buffer::Write(void* Data, size_t Size)
{
	if(mData->Size)
	{
		size_t BytesToEnd = mData->Size - (mData->Pointer - mData->Data);

		if(Size > BytesToEnd)
			Resize(mData->Size + (int)(Size - BytesToEnd));
	}

	memcpy(mData->Pointer, Data, Size);

	mData->Pointer += Size;
	mData->Size += Size;

	return 0;
}

size_t Buffer::Read(void* Data, size_t Size)
{
	size_t BytesToEnd = mData->Size - (mData->Pointer - mData->Data);

	if(Size <= BytesToEnd)
	{
		memcpy(Data, mData->Pointer, Size);

		mData->Pointer += Size;
	}
	else
	{
		memcpy(Data, mData->Pointer, BytesToEnd);

		mData->Pointer += BytesToEnd;
	}

	return 0;
}

bool Buffer::IsOpened()
{
	if(mData->Size)
		return true;

	return false;
}

void Buffer::Allocate(size_t Capacity)
{
	if(Capacity == 0)
		return;

	mData->Capacity = Capacity;

	mData->Data = new uint8[Capacity];
	memset(mData->Data, 0, Capacity);
	mData->Pointer = mData->Data;
}

void Buffer::Resize(size_t Capacity)
{
	if(mData->Capacity == Capacity)
		return;

	if(mData->Size)
	{
		// copy current data to temporary buffer
		size_t TempSize = mData->Size;
		uint8* Temp = new uint8[TempSize];
		memset(Temp, 0, TempSize);
		memcpy(Temp, mData->Data, TempSize);

		// delete current data
		Clear();

		// allocate new buffer with specified size
		Allocate(Capacity);
		// move data from temporary buffer to newly allocated one
		memcpy(mData->Data, Temp, TempSize);
		mData->Size = TempSize;

		// delete temporary buffer
		delete [] Temp;

		// set the pointer to the end of written data
		mData->Pointer += TempSize;
	}
	else
		Allocate(Capacity);
}

void Buffer::Clear()
{
	// make sure we allocated memory before, if else - we have nothing to clear
	if(mData->Capacity)
		return;

	mData->Size = 0;
	mData->Capacity = 0;
	delete [] mData->Pointer;
	delete [] mData->Data;
}

uint8* Buffer::Data()
{
	// make sure we have any data at all
	// probably better to use if(mData->Data)
	if(mData->Size)
		return mData->Data;
	else
		return 0;
}

size_t Buffer::Size()
{
	return mData->Size;
}

bool Buffer::IsEOF()
{
	return (mData->Pointer - mData->Data >= mData->Size);
}

void Buffer::Seek(int Offset, int SeekBase)
{
	switch(SeekBase)
	{
	case SET:
		mData->Pointer = mData->Data + Offset;
		break;
	case BEG:
		mData->Pointer = (uint8*)(0 + Offset);
		break;
	case END:
		mData->Pointer = mData->Data + mData->Capacity - Offset;
		break;
	case CUR:
		mData->Pointer += Offset;
		break;
	default:
		break;
	}
}


int Buffer::Tell()
{
	return (int)(mData->Pointer - mData->Data);
}