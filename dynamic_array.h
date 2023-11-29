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

void _append(DynamicArray* arr, void* elem); // �����Ҵ� �迭�� ���Ҹ� �߰��ϴ� �Լ� (������� �� ��)
void fit(DynamicArray* arr); // ���� �迭 ���̿� �迭 ����� ���ߴ� �Լ�

#endif