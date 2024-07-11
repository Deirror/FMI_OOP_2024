template <class T>
class Optional {
public:
	Optional() = default;
	Optional(const T& obj);

	Optional(const Optional<T>& other);
	Optional<T>& operator=(const Optional<T>& other);

	Optional(Optional<T>&& other) noexcept;
	Optional<T>& operator=(Optional<T>&& other) noexcept;

	~Optional();

	void set(const T& obj);
	const T& get() const;

	operator bool() const;

private:
	void free();
	void copyFrom(const Optional<T>& other);
	void moveFrom(Optional<T>&& other);

	T* value = nullptr;
};

template<class T>
Optional<T>::operator bool() const
{
	return (value == nullptr);
}

template<class T>
void Optional<T>::free()
{
	delete value;
	value = nullptr;
}

template<class T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	value = new T(*other.value);
}

template<class T>
void Optional<T>::moveFrom(Optional<T>&& other)
{
	value = other.value;
}


template<class T>
Optional<T>::Optional(const T& obj)
{
	value = new T(obj);
}

template<class T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template<class T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
Optional<T>::Optional(Optional<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
Optional<T>::~Optional()
{
	free();
}

template<class T>
void Optional<T>::set(const T& obj)
{
	if (value)
	{
		*value = obj;
	}
	else
	{
		value = new T(obj);
	}
}

template<class T>
const T& Optional<T>::get() const
{
	if (!value)
		throw std::invalid_argument("Value not set!");

	return *value;
}