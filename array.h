#pragma once
#include <cstddef>
#include <iostream>
#include <new>
#include <utility>

template <typename T>
class Array
{
public:

	explicit Array(size_t size, const T& value = T());
	Array() = default;
	Array(const Array & other);
	~Array();
	Array& operator= (const Array & other);

	Array(Array && other);
	Array& operator= (Array && other);

	size_t size() const;
	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	void print();

private:
	size_t size_ = 0;
	T * data_ = nullptr;
};


template <typename T>
Array<T>::Array(size_t size, const T& value) : size_(size), data_((T*) new char[size_ * sizeof(T)]) {
	for (size_t i = 0; i < size_; ++i) {
		new (data_ + i) T(value);
	}
}

template <typename T>
Array<T>::Array(const Array & other) : size_(other.size_), data_((T*) new char[size_ * sizeof(T)]) {
	for (size_t i = 0; i < size_; ++i) {
		new (data_ + i) T(other.data_[i]);
	}
}

template <typename T>
Array<T>::Array(Array && other) : size_(other.size_), data_(other.data_) {
	other.data_ = nullptr;
	other.size_ = 0;
}

template <typename T>
Array<T>::~Array() {
	for (size_t i = 0; i < size_; ++i) {
		data_[i].~T();
	}
	delete[](char*) data_;
}

template <typename T>
Array<T>& Array<T>::operator= (Array && other) {
	
	std::swap(size_, other.size_);
	std::swap(data_, other.data_);
	return *this;
}


template <typename T>
Array<T>& Array<T>::operator= (const Array & other) {
	if (data_ != other.data_) {
		delete[](char*) data_;
		size_ = other.size_;
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i < size_; ++i) {
			new (data_ + i) T(other.data_[i]);
		}
	}
	return *this;
}

template <typename T>
size_t Array<T>::size() const {
	return size_;
}

template <typename T>
T& Array<T>::operator[](size_t n) {
	return data_[n];
}

template <typename T>
const T& Array<T>::operator[](size_t n) const {
	return data_[n];
}

template <typename T>
void Array<T>::print()
{
	for (size_t i = 0; i < size_; ++i)
		std::cout << *(data_ + i);
	std::cout << std::endl;
}