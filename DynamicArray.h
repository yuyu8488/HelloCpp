#pragma once

#include <string.h>
#include <stdio.h>

template<typename T>
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	size_t GetSize()
	{
		return Size;
	}

	size_t GetCapacity()
	{
		return Capacity;
	}
	
	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}
	
	void PushBack(T Value);

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
TDynamicArray<T>::TDynamicArray()
{

}

