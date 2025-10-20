#include "FEngine.h"

#include <iostream>

void customSort(int arr[], int size) {
	int baseIndex = 0;
	int lastIndex = size - 1;

	while (baseIndex < lastIndex) {
		int baseValue = arr[baseIndex];
		bool foundBigger = false;
		int lastMinIndex = -1;

		for (int i = baseIndex + 1; i <= lastIndex; ++i) {
			if (arr[i] > baseValue) {
				baseIndex = i;
				foundBigger = true;
				break;
			}
			if (arr[i] < baseValue) {
				lastMinIndex = i;
			}
		}

		if (!foundBigger) {
			if (lastMinIndex != -1) {
				// swap baseIndex and lastMinIndex
				int temp = arr[baseIndex];
				arr[baseIndex] = arr[lastMinIndex];
				arr[lastMinIndex] = temp;

				lastIndex = lastMinIndex - 1;
				baseIndex = 0; // restart from beginning
			}
			else {
				break; // no smaller value found, sorting done
			}
		}
	}
}

using namespace std;

int main(int argc, char* argv[])
{
	// sort 구현하기.
	// BaseIndex = 배열의 원소중 확인된 가장 큰값의 인덱스 (BaseValue)
	// LastIndex = 배열에서 확인이 필요한 마지막 인덱스 
	// LastMinIndex = BaseValue와 비교시 마지막으로 발견된 작은값의 인덱스


	// 0 1 2 3 2 1 0 2 1 3	
	// 처음에 [0]의 값이 BaseIndex로 설정. BaseIndex가 갱신될때마다 다시 포문 내부에서, BaseIndex부터 LastIndex까지 포문을 돌면서 값 비교.
	// 만약에 BaseIndex의 값보다 더 큰 값이 있다면 포문 탈출하고, BaseIndex를 갱신 BaseIndex의 값부터 LastIndex까지 검사 > 반복.

	// [1]:1 이 Base로 설정됨. 탈출>
	// [2]:2 이 Base로 설정됨. 탈출>
	// [3]:3 이 Base로 설정됨. 
	// 0 1 2 <3> 2 1 0 2 <1> 3 : [3]기준값의 인덱스, [8]기준값하고 비교시 마지막으로 확인된 작은값 인덱스
	// 마지막인덱스 도달했을때, Base값보다 큰 값이 없는경우 LastMinIndex랑 BaseIndex의 값을 교환.
	
	// 기준값하고 비교시 마지막으로 확인된 작은값 인덱스를 기억하고 다시 for문을 돌릴때 그 인덱스 전까지만 확인.
	// 0 1 <2> 1 2 1 <0> 2 / [3] 3 : (LastMinIndex) = 8 >>>>> 여기까지가 한주기. (Base 초기화)

	// 0 1 0 1 <2> <1> / [2] 2 3 3
	// 0 <1> <0> 1 1 / 2 2 2 3 3
	// <0> 0 / 1 1 1 2 2 2 3 3 : Base 값하고 LastIndex 까지의 값을 비교했을때, 작거나 같다면, sort 마치기.

	// 문제점1. >> 한주기가 끝나고 항상 Base가 [0]인덱스로 설정됨.


	bool SortEnd = false;
	//int Array[10] = { 0, 1, 2, 3, 2, 1, 0, 2, 1, 3 };
	//int Array[10] = { 3, 5, 2, 3, 2, 1, 6, 1, 23, 5 };
	int Array[10] = { 123, 23, 51, 22, 2, 3, 4, 2,0, 0 };

	int BaseIndex = 0;
	int BaseValue = -1;
	int LastIndex = (sizeof(Array) / sizeof(int));
	int LastMinIndex = 0;
	bool Swap = false;
	while (!SortEnd)
	{
		BaseIndex = 0;
		BaseValue = -1;

		// Base, LastMinIndex 설정
		for (int i = BaseIndex; i < LastIndex; i++)
		{
			if (BaseValue <= Array[i])
			{
				BaseValue = Array[i];
				BaseIndex = i;
				Swap = false;
			}
			else if (BaseValue > Array[i])
			{
				LastMinIndex = i;
				Swap = true;
			}
		}

		// 교환
		if (Swap)
		{
			int temp = Array[LastMinIndex];
			Array[LastMinIndex] = Array[BaseIndex];
			Array[BaseIndex] = temp;
			LastIndex = LastMinIndex;	
		}
		else
		{
			SortEnd = true;
		}
	}

	for (int v : Array)
	{
		cout << v << ", ";
	}


	//if (FEngine* NewEngine = GEngine)
	//{
	//	NewEngine->Init();
	//	NewEngine->Run();
	//	NewEngine->Term();

	//	delete NewEngine;
	//	NewEngine = nullptr;
	//}

	return 0;
}
