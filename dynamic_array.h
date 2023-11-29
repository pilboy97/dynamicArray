#ifndef __dynamic_array_h__
#define __dynamic_array_h__

#include <stdlib.h>
#include <string.h>

#define da_new(T, SIZE) {malloc(sizeof(T) * SIZE), sizeof(T), SIZE, SIZE}
#define da_append(arr, elem) _append(&arr, &elem)

typedef struct DynamicArray {
	void* ptr;
	int elemSize;
	int len;
	int cap;
} DynamicArray;

void _append(DynamicArray* arr, void* elem); // 동적할당 배열에 원소를 추가하는 함수 (사용하지 말 것)
void fit(DynamicArray* arr); // 동적 배열 길이에 배열 사이즈를 맞추는 함수

#endif