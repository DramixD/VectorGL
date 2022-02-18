#pragma once
#include"ForwardIteratorGL.h"
#include<iostream>
using namespace std;


template<class T>
class VectorGL {
	T* data = nullptr;
	int size = 0;
	int capacity = 0;
public:
	VectorGL();
	~VectorGL();
	VectorGL(const VectorGL& obj);
	VectorGL(VectorGL&& obj);
	VectorGL& operator=(const VectorGL& obj);
	VectorGL& operator=(VectorGL&& obj);

	int get_size()const;
	bool empty()const;
	int get_capacity()const;
	void reserve(int newCapacity);
	void push_back(const T& val);
	void erase(int index);
	void clear();
	T& operator[](int index);

	ForwardIteratorGL<T> begin()const;
	ForwardIteratorGL<T> end()const;
	ForwardIteratorGL<T> find(const T& val)const;

	void print()const;
};

template<class T>
VectorGL<T>::VectorGL() = default;

template<class T>
VectorGL<T>::~VectorGL()
{
	if (capacity)
		delete[]data;
}

template<class T>
VectorGL<T>::VectorGL(const VectorGL & obj)
{
	capacity = obj.capacity;
	size = obj.size;
	data = new T[capacity];
	for (int i = 0; i < size; ++i)
		data[i] = obj.data[i];
}

template<class T>
VectorGL<T>::VectorGL(VectorGL && obj)
{
	swap(capacity, obj.capacity);
	swap(size, obj.size);
	swap(data, obj.data);
}

template<class T>
VectorGL<T>& VectorGL<T>::operator=(const VectorGL & obj)
{
	if (this == &obj)
		return *this;
	if (capacity)
		delete[] data;
	capacity = obj.capacity;
	size = obj.size;
	data = new T[capacity];
	for (int i = 0; i < size; ++i)
		data[i] = obj.data[i];
	return *this;
}

template<class T>
VectorGL<T>& VectorGL<T>::operator=(VectorGL && obj)
{
	if (this == &obj)
		return *this;
	if (capacity)
		delete[] data;
	data = nullptr;

	swap(data, obj.data);
	swap(size, obj.size);
	swap(capacity, obj.capacity);
	return *this;
}

template<class T>
int VectorGL<T>::get_size() const
{
	return size;
}

template<class T>
bool VectorGL<T>::empty() const
{
	return !size;
}

template<class T>
int VectorGL<T>::get_capacity() const
{
	return capacity;
}

template<class T>
void VectorGL<T>::reserve(int newCapacity)
{
	if (newCapacity > capacity) {
		T* tmp = new T[newCapacity];
		if (capacity) {
			for (int i = 0; i < size; ++i)
				tmp[i] = data[i];
			delete[] data;
		}
		capacity = newCapacity;
		data = tmp;
	}
}

template<class T>
void VectorGL<T>::push_back(const T & val)
{
	if (size == capacity) {
		if (capacity == 0) {
			capacity = 1;
			data = new T[capacity];
		}
		else {
			capacity *= 2;
			T* tmp = new T[capacity];
			for (int i = 0; i < size; ++i)
				tmp[i] = data[i];
			delete[] data;
			data = tmp;
		}
	}
	data[size] = val;
	++size;
}

template<class T>
void VectorGL<T>::erase(int index)
{
	if (index >= 0 && index < size) {
		for (int i = index; i < size - 1; ++i)
			data[i] = data[i + 1];
	}
	--size;
}

template<class T>
void VectorGL<T>::clear()
{
	size = 0;
}

template<class T>
T& VectorGL<T>::operator[](int index)
{
	return data[index];
}


template<class T>
ForwardIteratorGL<T> VectorGL<T>::begin() const
{
	return ForwardIteratorGL<T>(data);
}

template<class T>
ForwardIteratorGL<T> VectorGL<T>::end() const
{
	return ForwardIteratorGL<T>(data + size);
}

template<class T>
ForwardIteratorGL<T> VectorGL<T>::find(const T & val) const
{
	T* ptr;
	for (ptr = data; ptr != data+size; ++ptr) {
		if (*ptr == val)
			return ForwardIteratorGL<T>(ptr);
	}
	return ForwardIteratorGL<T>(ptr);
}

template<class T>
void VectorGL<T>::print() const
{
	cout << "capacity = " << capacity << endl;
	cout << "size = " << size << endl;
	for (int i = 0; i < size; ++i)
		cout << data[i] << " ";
	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
