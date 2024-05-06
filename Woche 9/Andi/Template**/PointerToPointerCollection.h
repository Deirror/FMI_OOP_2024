#pragma once
#include <exception>
#define DEFAULT_CAPACITY 8

static unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) > 0);

	return (1 << --times);
}

template<typename T>
class PointerToPointerCollection
{
private:
	T** _collection = nullptr;

	size_t _size = 0;
	size_t _capacity = 0;
	size_t _firstFreeIndex = 0;

public:
	PointerToPointerCollection();

	PointerToPointerCollection(const PointerToPointerCollection& other);
	PointerToPointerCollection& operator=(const PointerToPointerCollection& other);
	~PointerToPointerCollection();

	PointerToPointerCollection(PointerToPointerCollection&& other) noexcept;
	PointerToPointerCollection& operator=(PointerToPointerCollection&& other) noexcept;

private:
	void free();
	void copyFrom(const PointerToPointerCollection& other);
	void moveFrom(PointerToPointerCollection&& other);

	void resize(size_t newCapacity);
	void findFirstFreeIndex();

public:
	void addAtFirstFreeIndex(const T& current);
	void addAtFirstFreeIndex(T&& object);

	bool containsAt(size_t index) const;
	void popBack();
	void removeAt(size_t index);

	void setAtIndex(const T& obj, size_t index);
	void setAtIndex(T&& obj, size_t index);

	size_t getSize() const;
	size_t getCapacity() const;

	const T& operator[](size_t index) const;
	T& operator[](size_t index);

};

template<typename T>
PointerToPointerCollection<T>::PointerToPointerCollection() : _size(0)
{
	 _capacity = DEFAULT_CAPACITY;

	 _collection = new T*[_capacity]{nullptr};
}

template<typename T>
PointerToPointerCollection<T>::PointerToPointerCollection(const PointerToPointerCollection & other)
{
	copyFrom(other);
}

template<typename T>
PointerToPointerCollection<T> & PointerToPointerCollection<T>::operator=(const PointerToPointerCollection & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
PointerToPointerCollection<T>::~PointerToPointerCollection()
{
	for (int i = 0; i < _size; i++)
	{
		delete _collection[i];
	}

	delete[] _collection;
}

template<typename T>
PointerToPointerCollection<T>::PointerToPointerCollection(PointerToPointerCollection && other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
PointerToPointerCollection<T> & PointerToPointerCollection<T>::operator=(PointerToPointerCollection && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
void PointerToPointerCollection<T>::free()
{
	for (int i = 0; i < _size; i++)
	{
		delete _collection[i];
		_collection[i] = nullptr;
	}

	delete[] _collection = nullptr;
	_size = _capacity = _firstFreeIndex = 0;
}

template<typename T>
void PointerToPointerCollection<T>::copyFrom(const PointerToPointerCollection & other)
{
	_size = other._size;
	_capacity = other._capacity;
	_firstFreeIndex = other._firstFreeIndex;

	_collection = new T[_capacity];

	for (int i = 0; i < _size; i++)
	{
		if (other._collection[i] == nullptr)
			_collection[i] = nullptr;
		else
			_collection[i] = new T(*other._collection[i]);
	}
}

template<typename T>
void PointerToPointerCollection<T>::moveFrom(PointerToPointerCollection && other)
{
	_size = other._size;
	_capacity = other._capacity;
	_firstFreeIndex = other._firstFreeIndex;

	other._size = other._capacity = other._firstFreeIndex = 0;

	_collection = other._collection;
	other._collection = nullptr;
}

template<typename T>
void PointerToPointerCollection<T>::resize(size_t newCapacity)
{
	newCapacity = roundToPowerOfTwo(newCapacity);

	T** newCollection = new T*[newCapacity] {nullptr};

	for (int i = 0; i < _size; i++)
	{
		newCollection[i] = _collection[i];
	}

	delete[] _collection;

	_collection = newCollection;
	_capacity = newCapacity;
}

template<typename T>
void PointerToPointerCollection<T>::findFirstFreeIndex()
{
	for (int i = 0; i < _size; i++)
	{
		if (_collection[i] == nullptr)
		{
			_firstFreeIndex = i;
			return;
		}
	}

	_firstFreeIndex = _size;
}

template<typename T>
void PointerToPointerCollection<T>::addAtFirstFreeIndex(const T & current)
{
	if ((_firstFreeIndex == _size) && (_size == _capacity))
		resize(_size + 1);

	_collection[_firstFreeIndex] = new T(current);

	_size++;

	findFirstFreeIndex();
}

template<typename T>
void PointerToPointerCollection<T>::addAtFirstFreeIndex(T && object)
{
	if ((_firstFreeIndex == _size) && (_size == _capacity))
		resize(_size + 1);

	_collection[_firstFreeIndex] = new T(std::move(object));

	_size++;

	findFirstFreeIndex();
}

template<typename T>
bool PointerToPointerCollection<T>::containsAt(size_t index) const
{
	if (index >= _size)
		throw std::exception("Out of range");

	return (_collection[index] != nullptr);
}

template<typename T>
void PointerToPointerCollection<T>::popBack()
{
	if (_size == 0)
		throw std::exception("Empty");

	delete[] _collection[_size - 1];

	_collection[_size - 1] = nullptr;

	_size--;

	if (_size * 4 == _capacity)
		resize(_capacity / 2);

	findFirstFreeIndex();
}

template<typename T>
void PointerToPointerCollection<T>::removeAt(size_t index)
{
	if (index >= _size)
		throw std::exception("Out of range");

	delete[] _collection[index];

	_collection[index] = nullptr;

	_size--;

	if (_size * 4 == _capacity)
		resize(_capacity / 2);

	findFirstFreeIndex();
}

template<typename T>
void PointerToPointerCollection<T>::setAtIndex(const T & obj, size_t index)
{
	if (index >= _size)
		resize(index);

	if (_collection[index] != nullptr)
	{
		_collection[index]->operator=(obj);
	}
	else
	{
		_collection[index] = new T(obj);
		_size++;
	}

	findFirstFreeIndex();
}

template<typename T>
void PointerToPointerCollection<T>::setAtIndex(T && obj, size_t index)
{
	if (index >= _size)
		resize(index);

	if (_collection[index] != nullptr)
	{
		*_collection[index] = obj;
	}
	else
	{
		_collection[index] = new T(obj);
		_size++;
	}

	findFirstFreeIndex();
}

template<typename T>
size_t PointerToPointerCollection<T>::getSize() const
{
	return _size;
}

template<typename T>
size_t PointerToPointerCollection<T>::getCapacity() const
{
	return _capacity;
}

template<typename T>
const T & PointerToPointerCollection<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::exception("Out of range");

	return *_collection[index];
}

template<typename T>
T & PointerToPointerCollection<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::exception("Out of range");

	return *_collection[index];
}
