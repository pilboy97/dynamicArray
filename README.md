# dynamicArray
c based simple dynamic array

```
sample code

#include <stdio.h>
#include <string.h>

#include "dynamic_array.h"

void printDynamicArray(DynamicArray* arr) { // 동적 할당배열을 출력하는 함수
	for(int i = 0; i < arr->len; i++) { // 동적 할당 배열을
		putchar(*((char*) arr->ptr + i));
	}
}

int main() {
	DynamicArray arr = da_new(char, 0);
	char str[] = "hello world";

	printDynamicArray(&arr);
	puts("");
	printf("%d %d\n", arr.len, arr.cap);

	for(int i = 0; i < strlen(str); i++) {
		da_append(arr, str[i]);

		printDynamicArray(&arr);
		puts("");
		printf("%d %d\n", arr.len, arr.cap);
	}

	fit(&arr);

	printDynamicArray(&arr);
	puts("");
	printf("%d %d\n", arr.len, arr.cap);
	return 0;
}
```
