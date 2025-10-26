#pragma once

#include <string.h>

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	void PushBack(T Value);

	size_t GetSize() const
	{
		return Size;
	}

	size_t GetCapacity() const
	{
		return Capacity;
	}
	
	T& operator[](size_t Index)
	{
		return Data[Index];
	}

	class iterator
	{
	public:
		iterator() : Ptr(nullptr) {}
		iterator(T* p) : Ptr(p) {}

		T& operator*() { return *Ptr; }
		iterator& operator++() 
		{
			++Ptr;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp = *this;
			++Ptr;
			return temp;
		}
		bool operator==(const iterator& Rhs) const
		{
			return Ptr == Rhs.Ptr;
		}
		bool operator!=(const iterator& Rhs) const
		{
			return Ptr != Rhs.Ptr;
		}
		bool operator<(const iterator& Rhs) const
		{
			return Ptr < Rhs.Ptr;
		}
		bool operator>(const iterator& Rhs) const
		{
			return Ptr > Rhs.Ptr;
		}

	private:
		T* Ptr;

	};

	iterator begin()
	{
		return iterator(Data);
	}
	iterator end()
	{
		return iterator(Data + Size);
	}

protected:
	T* Data;
	
	size_t Size = 0;
	size_t Capacity = 0;
	size_t CurrentIndex = 0;
};


template<typename T>
void TDynamicArray<T>::PushBack(T Value)
{
	if (CurrentIndex < Capacity)
	{
		Data[CurrentIndex] = Value;
		CurrentIndex++;
		Size++;
	}
	else
	{
		if (Capacity == 0)
		{
			Capacity = 1;
		}

		T* NewArray = new T[Capacity * 2];

		memmove(NewArray, Data, Size * sizeof(T));

		if (Data)
		{
			delete[] Data;
		};
		Data = NewArray;
		Capacity = Capacity * 2;
		Size++;

		Data[CurrentIndex] = Value;
		CurrentIndex++;
	}
}

template<typename T>
TDynamicArray<T>::~TDynamicArray()
{
	if (Data)
	{
		delete[] Data;
	}
}

template<typename T>
TDynamicArray<T>::TDynamicArray() : Data(nullptr), Size(0), Capacity(0)
{

}

