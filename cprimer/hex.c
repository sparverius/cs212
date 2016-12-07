/* hex.c
 * Richard Kent
 * asks for an integer from user and prints it in hexadecimal form
 */

int printf(const char *format, ...);
int scanf(const char *format, ...);

int main(void)
{
	int hex;
	printf("Enter an integer: ");
	scanf("%d", &hex);
	printf("The hexadecimal form of %d is %x\n", hex, hex);
	return 0;
}
