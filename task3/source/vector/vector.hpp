#pragma once
#include <new>

namespace container {
	template<typename T>
	class vector {
	public:
		vector();
		vector(const vector& other);
		vector(const int size_);
		~vector();

		constexpr T& at(const int index);
		constexpr void push_back(const T& value);
		constexpr size_t size() const noexcept;
		constexpr size_t capacity() const noexcept;

		constexpr vector& operator=(const vector& other);

	private:
		T* arr = nullptr;
		size_t size_{};
		size_t capacity_{};
	};

	template<typename T>
	vector<T>::vector() {}

	template<typename T>
	vector<T>::vector(const vector& other) { *this = other; }

	template<typename T>
	vector<T>::vector(const int size_) : size_(size_), capacity_(size_) {

		if (size_ <= 0) { throw std::bad_array_new_length(); }

		arr = new T[size_]{};
	}

	template<typename T>
	vector<T>::~vector() { delete[] arr; }

	template<typename T>
	constexpr T& vector<T>::at(const int index) {
		if(index < 0 || index >= size_) { throw std::out_of_range("Attempt to access an element outside the container"); }

		return arr[index];
	}

	template<typename T>
	constexpr void vector<T>::push_back(const T& value) {
		if (size_ == capacity_) {

			if (!size_) { capacity_++; }
			else { capacity_ *= 2; }

			T* temp = new T[capacity_]{};

			if(size_) for (size_t i = 0; i < size_; ++i) { temp[i] = arr[i]; }

			delete[] arr;
			arr = temp;
		}

		arr[size_] = value;
		size_++;
	}

	template<typename T>
	constexpr size_t vector<T>::size() const noexcept { return size_; }
	
	template<typename T>
	constexpr size_t vector<T>::capacity() const noexcept { return capacity_; }
	
	template<typename T>
	constexpr vector<T>& vector<T>::operator=(const vector& other) {

		if (this == &other) { return *this; }
		if (arr != nullptr) { delete[] arr; }

		size_ = other.size_;
		capacity_ = other.capacity_;

		arr = new T[size_];

		for (size_t i = 0; i < size_; ++i) {
			arr[i] = other.arr[i];
		}

		return *this;
	}
}