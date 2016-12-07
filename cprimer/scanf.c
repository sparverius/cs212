/* user.c
 * Richard Kent
 * Takes two integers from the user (via scanf) prints out which is larger
 */

int printf(const char *format, ...);
int scanf(const char *format, ...);

int main(void)
{
	int first;
	int second;
	int sum;

	printf("First number: ");
	scanf("%d", &first);
	printf("Second number: ");
	scanf("%d", &second);

	sum = first + second;

	if (first > second) {
		printf("%d + %d = %d and %d > %d\n", first, second, sum, first, second);
 	}
	else if (second > first) {
		printf("%d + %d = %d and %d >  %d\n", second, first, sum, second, first);
	}

	else { // first == second
		printf("%d + %d = %d and %d = %d\n", first, second, sum, first, second);
	}
	return 0;
}
