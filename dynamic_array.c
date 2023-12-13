#include "dynamic_array.h"

void __append(DynamicArray* arr, void* elem) {
	bool renewal = false;
	while(arr->len + 1 > arr->cap) { // 만약 배열이 가득 찼다면
		if(arr->cap == 0) { // 만약 배열의 길이가 0이라면
			arr->cap = 1;	// 배열의 길이를 1로 설정
		} else {
			arr->cap *= 2;	// 배열의 길이를 2배로 바꿈
		}
		renewal = true;
	}
	if(renewal) {
		void* neo = malloc(arr->elemSize * arr->cap); // 새 배열을 할당함
		void* old = arr->ptr;	// 이전 배열 포인터

		memcpy(neo, arr->ptr, arr->len * arr->elemSize); // 새 배열에 기존 내용을 복사함

		arr->ptr = neo; // 배열 포인터 갱신
		free(old);	// 기존 배열 삭제
	}
	memcpy((char*) arr->ptr + arr->len * arr->elemSize, elem, arr->elemSize); // 배열의 마지막에 새 원소 추가
	arr->len += 1;	// 길이 증가
}
void da_fit(DynamicArray* arr) { // 동적 배열 길이에 배열 사이즈를 맞추는 함수 
	arr->cap = arr->len;
	void* neo = malloc(arr->elemSize * arr->cap); // 새 배열을 할당함
	void* old = arr->ptr;	// 이전 배열 포인터

	memcpy(neo, arr->ptr, arr->len * arr->elemSize); // 새 배열에 기존 내용을 복사함

	arr->ptr = neo; // 배열 포인터 갱신
	free(old);	// 기존 배열 삭제
}

void da_free(DynamicArray* arr) {
	free(arr->ptr);
}
