#pragma once

#include <memory>

#define DECLARE_WRITE(Type, Name) \
void Name(Type Value);

#define DECLARE_WRITE_ARRAY(Type, Name) \
void Name(Type Value, size_t Size);

#define DECLARE_READ(Type, Name) \
Type Name();

#define DECLARE_READ_ARRAY(Type, Name) \
Type* Name(size_t Size);

#ifdef BIG_ENDIAN

#define IMPLEMENT_WRITE(Type, Name) \
void Stream::Name(Type Value) \
{ \
    Type Buf; \
    uint8* s = (uint8*)&Value; \
    uint8* d = (uint8*)&Buf + sizeof(Buf) - 1; \
    for(int i = 0; i < (int)sizeof(Type); i++) \
    { \
        *d-- = *s++; \
    } \
    Write(&Buf, sizeof(Value)); \
} 

#define IMPLEMENT_WRITE_ARRAY(Type, Name) \
void Stream::Name(Type Value, size_t Size) \
{ \
    Type Buf; \
    uint8* s = (uint8*)&Value; \
    uint8* d = (uint8*)&Buf + sizeof(Buf) - 1; \
    for(int i = 0; i < (int)sizeof(Type); i++) \
    { \
        *d-- = *s++; \
    } \
    Write(&Buf, Size); \
} 

#define IMPLEMENT_READ(Type, Name) \
Type Stream::Name() \
{ \
Type Rtn, Buf = 0; \
	Read(&Buf, sizeof(Buf)); \
	uint8* s = (uint8*)&Buf; \
	uint8* d = (uint8*)&Rtn + sizeof(Rtn) - 1; \
	for(int i = 0; i < (int)sizeof(Type); i++) \
	{ \
	    *d-- = *s++; \
	} \
	return Rtn; \
}

#define IMPLEMENT_READ_ARRAY(Type, Name) \
Type* Stream::Name(size_t Size) \
{ \
    Type* Rtn = 0; \
    memset(Rtn, 0, sizeof(Rtn) * Size); \
    Read(&Rtn, sizeof(*Rtn) * Size);
    for(int i = 0; i < Size; i++) \
    { \ 
        Type Buffer = Rtn[i]; \
        unsigned char* s = (unsigned char*)&Bufer; \
        unsigned char* d = &Rtn[i] + sizeof(Type) - 1; \
        for(int n = 0; n < sizeof(Type); n++) \
        { \
            *d-- = *s++; \
        } \
    } \
    return Rtn; \
}

#else

#define IMPLEMENT_WRITE(Type, Name) \
void Stream::Name(Type Value) \
{ \
    Write(&Value, sizeof(Value)); \
} 

#define IMPLEMENT_WRITE_ARRAY(Type, Name) \
void Stream::Name(Type Value, size_t Size) \
{ \
    Write(&Value, Size); \
}

#define IMPLEMENT_READ(Type, Name) \
Type Stream::Name() \
{ \
	Type Rtn = 0; \
	Read(&Rtn, sizeof(Rtn)); \
	return Rtn; \
}

#define IMPLEMENT_READ_ARRAY(Type, Name) \
Type* Stream::Name(size_t Size) \
{ \
    Type* Rtn = 0; \
    memset(Rtn, 0, sizeof(Rtn) * Size); \
    Read(&Rtn, Size); \
    return Rtn; \
}

#endif

static const int MaxStringLength = 4096;