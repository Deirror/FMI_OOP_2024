#include <cstring>
#include <stdexcept>
#include <utility>
#pragma warning (disable : 4996)
#define DEF_CAP 8

template <typename T>
class Dictionary
{
public:
	Dictionary();

	Dictionary(const Dictionary<T>& other);
	Dictionary<T>& operator=(const Dictionary<T>& other);

	Dictionary(Dictionary<T>&& other) noexcept;
	Dictionary<T>& operator=(Dictionary<T>&& other) noexcept;

	void add(const char* key, const T& object);

	void removeByKey(const char* key);
	const T& getByKey(const char* key) const;

	int contains(const char* key) const;
	bool isEmpty() const;
	void clear();

	size_t getSize() const;
	size_t getCapacity() const;

	~Dictionary();

private:
	struct Node
	{
		char* key = nullptr;
		T value;

		void setKey(const char* _key);
		void setValue(const T& object);
	};

	Node* nodes = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void free();
	void copyFrom(const Dictionary<T>& other);
	void moveFrom(Dictionary<T>&& other);

	void resize(size_t newCapacity);

};

template<typename T>
Dictionary<T>::Dictionary() : size(0), capacity(DEF_CAP)
{
	nodes = new Node[capacity]{};
}

template<typename T>
Dictionary<T>::Dictionary(const Dictionary<T>& other)
{
	copyfrom(other);
}

template<typename T>
Dictionary<T>& Dictionary<T>::operator=(const Dictionary<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Dictionary<T>::Dictionary(Dictionary<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Dictionary<T>& Dictionary<T>::operator=(Dictionary<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
void Dictionary<T>::add(const char * _key, const T & object)
{
	if (size == capacity)
		resize(capacity * 2);

	int index = contains(_key);

	if (index != -1)
		throw std::exception("Already contains element");

	nodes[size].setKey(_key);
	nodes[size].setValue(object);

	size++;
}

template<typename T>
void Dictionary<T>::Node::setKey(const char * _key)
{
	if (!_key)
		throw std::exception("Nullptr");

	delete[] key;
	key = new char[strlen(_key) + 1]{};

	strcpy(key, _key);
}

template<typename T>
void Dictionary<T>::Node::setValue(const T & object)
{
	value = object;
}

template<typename T>
void Dictionary<T>::free()
{
	for (int i = 0; i < size; i++)
	{
		delete[] nodes[i].key;
		nodes[i].key = nullptr;
	}

	delete[] nodes;

	nodes = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
void Dictionary<T>::copyFrom(const Dictionary<T>& other)
{
	size = other.size;
	capacity = other.capacity;

	nodes = new Node[capacity];

	for (int i = 0; i < size; i++)
	{
		nodes[i].setKey(other.nodes[i].key);
		nodes[i].setValue(other.nodes[i].value);
	}
}

template<typename T>
void Dictionary<T>::moveFrom(Dictionary<T>&& other)
{
	size = other.size;
	capacity = other.capacity;

	size = capacity = 0;

	nodes = other.nodes;
	other.nodes = nullptr;
}

template<typename T>
void Dictionary<T>::resize(size_t newCapacity)
{
	Node* newNodes = new Node[newCapacity];

	for (int i = 0; i < size; i++)
	{
		newNodes[i] = nodes[i];
	}

	delete[] nodes;
	nodes = newNodes;
	capacity = newCapacity;
}

template<typename T>
void Dictionary<T>::removeByKey(const char * key)
{
	int index = contains(key);

	if (index == -1)
		throw std::exception("Not found");

	if (size == capacity / 4 && capacity > DEF_CAP)
		resize(capacity / 2);

	for (int i = index; i < size - 1; i++)
	{
		nodes[i] = nodes[i + 1];
	}

	delete[] nodes[size].key;
	nodes[size].key = nullptr;
	size--;
}

template<typename T>
const T & Dictionary<T>::getByKey(const char * key) const
{
	int index = contains(key);

	if (index == -1)
		throw std::exception("Not found");

	return nodes[index].value;
}

template<typename T>
int Dictionary<T>::contains(const char * key) const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(nodes[i].key, key) == 0)
			return i;
	}

	return -1;
}

template<typename T>
bool Dictionary<T>::isEmpty() const
{
	return (size == 0);
}

template<typename T>
void Dictionary<T>::clear()
{
	free();
	capacity = DEF_CAP;

	nodes = new Node[capacity];
}

template<typename T>
inline size_t Dictionary<T>::getSize() const
{
	return size;
}

template<typename T>
inline size_t Dictionary<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
Dictionary<T>::~Dictionary()
{
	free();
}
