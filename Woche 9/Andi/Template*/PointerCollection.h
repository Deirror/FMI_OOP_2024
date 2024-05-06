#pragma once
#include <exception>
#define DEFAULT_CAPACITY 8

unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) > 0);

	return (1 << --times);
}

template<typename T>
class PointerCollection
{
private:
	T* _collection = nullptr;

	size_t _size = 0;
	size_t _capacity = 0;

public:
	PointerCollection();
	PointerCollection(size_t size);

	PointerCollection(const PointerCollection& other);
	PointerCollection& operator=(const PointerCollection& other);

	PointerCollection(PointerCollection&& other) noexcept;
	PointerCollection& operator=(PointerCollection&& other) noexcept;

	~PointerCollection();

private:
	void free();
	void copyFrom(const PointerCollection& other);

	void moveFrom(PointerCollection&& other);

	void resize(size_t newCapacity);

public:
	void pushBack(const T& newElement);
	void pushBack(T&& newElement);

	void insertAtIndex(const T& newElement, size_t index);
	void insertAtIndex(T&& newElement, size_t index);

	void setAtIndex(const T& element, size_t index);
	void setAtIndex(T&& element, size_t index);

	void popBack();

	void removeAt(size_t index);

	size_t getCapacity() const;
	size_t getSize() const;
	bool isEmpty() const;

	bool contains(const T& element) const;

	const T& operator[](size_t index) const;
	T& operator[](size_t index);
};

template<typename T>
PointerCollection<T>::PointerCollection() :  PointerCollection(DEFAULT_CAPACITY)
{

}

template<typename T>
PointerCollection<T>::PointerCollection(size_t size) : _size(0)
{
	_capacity = roundToPowerOfTwo(size);
	_collection = new T[_capacity];
}

template<typename T>
PointerCollection<T>::PointerCollection(const PointerCollection & other)
{
	copyFrom(other);
}

template<typename T>
PointerCollection<T> & PointerCollection<T>::operator=(const PointerCollection & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
 PointerCollection<T>::PointerCollection(PointerCollection && other) noexcept
{
	 moveFrom(std::move(other));
}

 template<typename T>
PointerCollection<T> & PointerCollection<T>::operator=(PointerCollection && other) noexcept
 {
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
 }

template<typename T>
PointerCollection<T>::~PointerCollection()
{
	delete[] _collection;
}

template<typename T>
void PointerCollection<T>::free()
{
	delete[] _collection;

	_collection = nullptr;

	_size = _capacity = 0;
}

template<typename T>
void PointerCollection<T>::copyFrom(const PointerCollection & other)
{
	_size = other._size;
	_capacity = other._capacity;

	_collection = new T[_capacity];

	for (int i = 0; i < _size; i++)
	{
		_collection[i] = other._collection;
	}
}

template<typename T>
void PointerCollection<T>::moveFrom(PointerCollection && other)
{
	_size = other._size;
	_capacity = other._capacity;

	other._size = other._capacity = 0;

	_collection = other._collection;

	other._collection = nullptr;
}

template<typename T>
void PointerCollection<T>::resize(size_t newCapacity)
{
	newCapacity = roundToPowerOfTwo(newCapacity);


	T* newCollection = new T[newCapacity];

	for (int i = 0; i < _size; i++)
		newCollection[i] = _collection[i];

	delete[] _collection;
	_collection = newCollection;

	_capacity = newCapacity;
}

template<typename T>
void PointerCollection<T>::pushBack(const T & newElement)
{
	if (_size == _capacity)
		resize(_size + 1);

	_collection[_size++] = newElement;
}

template<typename T>
void PointerCollection<T>::pushBack(T && newElement)
{
	if (_size == _capacity)
		resize(_size + 1);

	_collection[_size++] = std::move(newElement);
}

template<typename T>
void PointerCollection<T>::insertAtIndex(const T & newElement, size_t index)
{
	if (index > _size)
		throw std::out_of_range("PointerCollection<T>::insertAtIndex out of range");

	if (_size == _capacity)
		resize(_size + 1);

	for (int i = _size - 1; i >= index; i++)
	{
		_collection[i + 1] = _collection[i];
	}

	_collection[index] = newElement;

	_size++;
}

template<typename T>
void PointerCollection<T>::insertAtIndex(T && newElement, size_t index)
{
	if (index > _size)
		throw std::out_of_range("PointerCollection<T>::insertAtIndex out of range");

	if (_size == _capacity)
		resize(_size + 1);

	for (int i = _size - 1; i >= index; i--)
	{
		_collection[i + 1] = _collection[i];
	}

	_collection[index] = std::move(newElement);

	_size++;
}

template<typename T>
void PointerCollection<T>::setAtIndex(const T & element, size_t index)
{
	if (index >= _size)
		throw std::out_of_range("PointerCollection<T>::operator[] out of range");

	_collection[index] = element;
}

template<typename T>
void PointerCollection<T>::setAtIndex(T && element, size_t index)
{
	if (index >= _size)
		throw std::out_of_range("PointerCollection<T>::operator[] out of range");

	_collection[index] = std::move(element);
}

template<typename T>
void PointerCollection<T>::popBack()
{
	if(_size == 0)
		throw std::out_of_range("PointerCollection<T>::popBack empty");

	_size--;

	if (_size * 4 == _capacity)
		resize(_size);
}

template<typename T>
void PointerCollection<T>::removeAt(size_t index)
{
	if (index > _size)
		throw std::out_of_range("PointerCollection<T>::removeAt out of range or empty");

	for (int i = index; i < _size - 1; i++)
	{
		_collection[i] = _collection[i + 1];
	}

	_size--;

	if (_size * 4 == _capacity)
		resize(_size);
}

template<typename T>
size_t PointerCollection<T>::getCapacity() const
{
	return _capacity;
}

template<typename T>
size_t PointerCollection<T>::getSize() const
{
	return _size;
}

template<typename T>
bool PointerCollection<T>::isEmpty() const
{
	return(_size == 0);
}

template<typename T>
bool PointerCollection<T>::contains(const T & element) const
{
	for (int i = 0; i < _size; i++)
	{
		if (_collection[i] == element)
			return true;
	}

	return false;
}

template<typename T>
const T & PointerCollection<T>::operator[](size_t index) const
{ 
	if (index >= _size)
		throw std::out_of_range("PointerCollection<T>::operator[] out of range");

	return _collection[index];
}

template<typename T>
T & PointerCollection<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("PointerCollection<T>::operator[] out of range");

	return _collection[index];
}
