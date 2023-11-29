# dynamicArray
c based simple dynamic array

```
sample code

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
