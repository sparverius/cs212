/*	student2.c	*/
#include <stdio.h>

#define IDSTART 4242

typedef struct {
	char* name;
	char* family;
	int id;
} student;

void display(student student);

int main(void) {
	
	student first_student, second_student;

	first_student.name = "Kelly";
	first_student.family = "Clarkson";
	first_student.id = IDSTART + 1;

	second_student = first_student;

	first_student.name = "Clark";
	first_student.family = "Kent";
	first_student. id = IDSTART + 2;

	//Predict the outcome of
	display(first_student);
	display(second_student);
}

void display(student student) {
	printf("Student %s, %s has id %d",
		student.name, student.family, student.id);
}
