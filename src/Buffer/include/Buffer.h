#pragma once

#include "Basic.h"
#include "Defines.h"
#include "Stream.h"

struct BufferData;

/*! \brief Buffer class handles dynamic memory management
 *
 *	Buffer class is derived from \link Stream class and have the same features as Stream do.
 *	Buffer should be commonly used to temporary hold file data.
 *	Reasons may be various, compress\decompress or just pass it as argument to function that loads data "in-memory"
 */
class Buffer : public Stream
{
public:
	/*! Buffer consturctor
	 *  Default size is 8 KiB
	 */
	Buffer(size_t Size = 8192);
	virtual ~Buffer();

	/*!	Writes data of specified size to the buffer at current position
	 *	Upon writing data of size larger than buffer's capacity, buffer will be resized to fit that data
	 *	\param [in] Data array of data to be written
	 *	\param [in] Size size of the array
	 *	\return Nothing
	 */
	virtual void	Write(IN void* Data, IN size_t Size);

	/*!	Reads data of specified size from the buffer at current position
	 *	Upon reading data of size larger than buffer's size from current pointer position to end of the buffer, only this amount of data will be read
	 *	\param [in] Data initialised array to read data into
	 *	\param [in] Size size of data to be read
	 *	\return Nothing
	 */
	virtual void	Read(OUT void* Data, IN size_t Size);

	/*!	Returns state of buffer
	 *	\return true if buffer is opened, false if else
	 *	\attention it checks buffer size, so buffer will be "closed" after calling \link Buffer::Clear
	 */
	virtual bool	IsOpened();

	/*!	Allocates memory for buffer
	 *	\param [in] Capacity defines maximum possible size of data to be written
	 *	\return Nothing
	 */
	void			Allocate(IN size_t Capacity);

	/*!	Resizes buffer data
	 *	Upon resizing data is not lost. 
	 *	\param [in] Capacity new capacity for buffer data
	 *	\return Nothing
	 */
	void			Resize(IN size_t Capactiy);

	/*! Clears buffer data
	 *	Deletes only buffer data, not buffer itself
	 *	\return Nothing
	 */
	void			Clear();

	/*!	\return Buffer data
	 */
	char*			Data();
	/*!	\return Buffer size
	 */
	size_t			Size();

	/*! Checks if end of data was reached
	 *	\return true if pointer is set to end of buffer, false if else
	 */
	bool			IsEOF();

	/*!	Set pointer to specified position
	 *	\param [in] Offset position to set pointer to
	 *	\param [in] SeekBase base of seeking \link Stream
	 *	\return Nothing
	 */
	void			Seek(IN int Offset, IN int SeekBase = SET);

	/*! \return Pointer position
	 */
	int				Tell();
private:
	BufferData* mData; /*!< Buffer data: size, capacity and data itself */
};