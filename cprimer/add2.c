/* add2.c
 * Richard Kent
 * function header before definition after main method.
 */

int printf(const char *format, ...);  // printf can have a variable number of
                                      // parameters: the ... indicates this


int add(int n1, int n2);

int main(void) {
	int a = 42;
	int b = 84;

	int c = add(a,b);
	printf("The sum of %d and %d is %d\n", a, b, c);
}

int add(int n1, int n2) {
	int sum;
	sum = n1 + n2;
	return sum;
}
