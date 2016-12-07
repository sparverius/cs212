/* guess.c
 * Richard Kent
 * asks for a number from user (1-100)
 * asks user series of questions to guess the correct answer
 */

#include <stdio.h>

char input[4];
int ans;
int check();
void isNumber(int number);
void gameOver();
void play();
int num = 50;
int aux = 50;
void notNumber(int number);

int main(void) {	
	ans = 0;
	while (ans != 1) {
		play();
	}
}
void play() { 
		puts("\nPick a number, any number between 1 to 100");
		isNumber(num);
}

int check() {
	scanf("%s", input);

	if (input[0] == 'y') {
		return 1;
	} else {
		return 0;
	}
	input[0] = '\0';
}

void isNumber(int number) {
	printf("Is your number %d? Yes or No?\n", number);
	if (check()) {
		gameOver();
	} else {
		notNumber(number);
	}
}

void notNumber(int number) {
	printf("Is your number greater than %d? Yes or no?", number);
	aux = aux/2;
	if (aux <= 2 && aux >=0) {
		aux = 1;
	}
	if (check()) {
		num = num + aux;
		isNumber(num);
	} else {
		num = num - aux;
		isNumber(num);
	}
}


void gameOver() {
	puts("Would you like to play again? Yes or no?\n");
	if (check()) {
		aux = 50;
		num = 50;
		play();
	} else {
		ans = 1;
	}
}
