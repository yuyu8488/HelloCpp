#pragma once

#include <string.h>
#include <stdio.h>



template<typename T>
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	void PushBack(T Value);

 
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


	class iterator
	{
	public:
		//++ 연산자 오버로딩 
		T& iterator++operator();

	private:
		TDynamicArray* Array; 
		T* ArrayData;       
		size_t ArrayIndex;
	};

	typename TDynamicArray<T>::iterator begin();
	typename TDynamicArray<T>::iterator end();

protected:
	T* Data;
	
	size_t Size = 0;
	size_t Capacity = 0;
	size_t CurrentIndex = 0;
};

template<typename T>
typename TDynamicArray<T>::iterator TDynamicArray<T>::end()
{

}

template<typename T>
typename TDynamicArray<T>::iterator TDynamicArray<T>::begin()
{

}

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

