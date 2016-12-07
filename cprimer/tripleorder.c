/* tripleorder.c
 * Richard Kent
 * function that sorts the variables from smallest to largest
 */
#include <stdio.h>

void tripleorder(int* small, int* medium, int* large);

int main(void) {
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	tripleorder(&a , &b, &c);
	printf("%d, %d, %d\n", a, b, c);
}

void tripleorder(int* small, int* medium, int* large) {
	int array[] = {*small,*medium,*large};
	for (int i = 0; i < sizeof(array)/sizeof(int)-1; i++) {
		int placeholder = 0;
		if (array[i] >= array[i+1]) {
			placeholder = array[i+1];
			array[i+1] = array[i];
			array[i] = placeholder;
			if (i >= 1 && (array[i-1] >= array[i])) {
				placeholder = array[i-1];
				array[i-1] = array[i];
				array[i] = placeholder;
			}
		}
	}
	*small = array[0];
	*medium = array[1];
	*large = array[2];
}

