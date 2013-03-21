#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

#include "Stream.h"

/*! \brief Buffer class handles dynamic memory management
 *
 *	Buffer class is derived from Stream.
 *	Commonly used to temporary hold file data.
 */
class Buffer : public Stream
{
public:
	/*! Consturctor
	 * 
	 *  Default size is 8 KiB
	 */
	Buffer(size_t Size = 8192);
	virtual ~Buffer();

	/*!	Writes data to buffer at current position
	 *	If size of writeable data is larger than capacity of the buffer, buffer will be automatically resized to fit this data
	 *	\param [in] Data to be written
	 *	\param [in] Size of the data
	 *	\return Nothing
	 */
	virtual void Write(IN void* Data, IN size_t Size);

	/*!	Reads data from buffer at current position
	 *	If size of readable data larger than there left to the end. Only this amount of data will be read
	 *	\param [in] Data array to read into
	 *	\param [in] Size of data to be read
	 *	\return Nothing
	 */
	virtual void Read(OUT void* Data, IN size_t Size);

	/*!	Check state of buffer
	 *	\return true if buffer is opened, false if else
	 *	\attention it checks buffer size, so buffer will be "closed" after calling \link Buffer::Clear
	 */
	virtual bool IsOpened();

		/*!	\return Buffer data
	 */
	virtual char* Data();

	/*!	\return Buffer size
	 */
	virtual size_t Size();

	/*!	Allocate memory for buffer
	 *	\param [in] Capacity of buffer
	 *	\return Nothing
	 */
	void Allocate(IN size_t Capacity);

	/*!	Resize buffer
	 *	Data is not lost on resizing.
	 *	\param [in] Capacity of buffer
	 *	\return Nothing
	 */
	void Resize(IN size_t Capactiy);

	/*! Clear buffer data
	 *	\return Nothing
	 */
	void Clear();

	/*! Check if end of data was reached
	 *	\return true if pointer is set to end of buffer, false if else
	 */
	bool IsEOF();

	/*!	Set pointer to Offset
	 *	\param [in] Offset to set pointer to
	 *	\param [in] SeekBase base of seeking
	 *	\return Nothing
	 */
	void Seek(IN int Offset, IN int SeekBase = SET);

	/*! \return Pointer position
	 */
	int	Tell();
private:
	struct BufferData;
	BufferData* mData;
};