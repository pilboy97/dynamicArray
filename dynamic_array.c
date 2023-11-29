#include "dynamic_array.h"

void _append(DynamicArray* arr, void* elem) {
	while(arr->len + 1 > arr->cap) { // ���� �迭�� ���� á�ٸ�
		if(arr->cap == 0) { // ���� �迭�� ���̰� 0�̶��
			arr->cap = 1;	// �迭�� ���̸� 1�� ����
		} 
		else {
			arr->cap *= 2;	// �迭�� ���̸� 2��� �ٲ�
		}
		void* neo = malloc(arr->elemSize * arr->cap); // �� �迭�� �Ҵ���
		void* old = arr->ptr;	// ���� �迭 ������

		memcpy(neo, arr->ptr, arr->len * arr->elemSize); // �� �迭�� ���� ������ ������

		arr->ptr = neo; // �迭 ������ ����
		free(old);	// ���� �迭 ����
	}

	memcpy((char*) arr->ptr + arr->len * arr->elemSize, elem, arr->elemSize); // �迭�� �������� �� ���� �߰�
	arr->len += 1;	// ���� ����
}
void fit(DynamicArray* arr) { // ���� �迭 ���̿� �迭 ����� ���ߴ� �Լ� 
	arr->cap = arr->len;
	void* neo = malloc(arr->elemSize * arr->cap); // �� �迭�� �Ҵ���
	void* old = arr->ptr;	// ���� �迭 ������

	memcpy(neo, arr->ptr, arr->len * arr->elemSize); // �� �迭�� ���� ������ ������

	arr->ptr = neo; // �迭 ������ ����
	free(old);	// ���� �迭 ����
}