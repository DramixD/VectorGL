#pragma once


template<class T>
class ForwardIteratorGL {
	T* ptr;
public:
	~ForwardIteratorGL();
	ForwardIteratorGL(T* inputPtr);
	ForwardIteratorGL(const ForwardIteratorGL& obj);
	ForwardIteratorGL(ForwardIteratorGL&& obj);
	ForwardIteratorGL operator++();
	ForwardIteratorGL operator++(int);
	T operator*();
	bool operator!=(const ForwardIteratorGL<T>& obj)const;
	bool operator==(const ForwardIteratorGL<T>& obj)const;
};

template<class T>
ForwardIteratorGL<T>::~ForwardIteratorGL() = default;

template<class T>
ForwardIteratorGL<T>::ForwardIteratorGL(const ForwardIteratorGL & obj)
{
	ptr = obj.ptr;
}

template<class T>
ForwardIteratorGL<T>::ForwardIteratorGL(ForwardIteratorGL&& obj)
{
	std::swap(ptr, obj.ptr);
}

template<class T>
ForwardIteratorGL<T>::ForwardIteratorGL(T* inputPtr)
{
	ptr = inputPtr;
}

template<class T>
ForwardIteratorGL<T> ForwardIteratorGL<T>::operator++()
{
	ForwardIteratorGL<T> tmp = *this;
	++ptr;
	return tmp;
}

template<class T>
ForwardIteratorGL<T> ForwardIteratorGL<T>::operator++(int)
{
	++ptr;
	return *this;
}

template<class T>
T ForwardIteratorGL<T>::operator*()
{
	return *ptr;
}

template<class T>
bool ForwardIteratorGL<T>::operator!=(const ForwardIteratorGL<T>& obj)const
{
	return ptr!=obj.ptr;
}

template<class T>
inline bool ForwardIteratorGL<T>::operator==(const ForwardIteratorGL<T>& obj) const
{
	return ptr == obj.ptr;
}
