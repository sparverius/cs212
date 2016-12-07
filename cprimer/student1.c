/*	student1.c	*/
#include <stdio.h>

#define IDSTART 4242

typedef struct {
	char* name;
	char* family;
	int id;
} student;

int main(void) {

	student firstStudent, secondStudent;

	firstStudent.name = "Kelly";
	firstStudent.family = "Clarkson";
	firstStudent.id = IDSTART + 1;

	secondStudent = firstStudent;

	firstStudent.name = "Clark";
	firstStudent.family = "Kent";
	firstStudent.id = IDSTART + 2;

	//Predict the outcome of
	printf("firstStudent %s, %s, has id %d",
			firstStudent.name, firstStudent.family, firstStudent.id);
	printf("secondStudent: %s, %s has id %d",
			secondStudent.name, secondStudent.family, secondStudent.id);
	return 0;
}
