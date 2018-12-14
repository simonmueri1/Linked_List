#include "stdio.h"
#include "stdlib.h"

void sequences();
void printMenu();
void scanInput();

void main() {
	sequences();
}


void sequences() {
	char input[30];

	printMenu();
	input = scanInput();
	system("pause");

	switch(input)
		case C:
				break;
		case DE: 
				break;
		case P:
				break;
}

void printMenu() {
	printf("_________________________________________________________________\n");
	printf("LINKED LIST - APP from Simon Mueri & Michel Leisibach v1.0\n");
	printf("_________________________________________________________________\n");
	printf("Create List\t\t = [CL]\n");
	printf("Delete List\t\t = [DL]\n");
	printf("Print List Elements\t\ = [PE] + (Number)\n");
	printf("Print all\t\t = [PE] + (0)\n");
	printf("Delete Element\t\t = [DE] + (Firstname + Lastname)\n");
	printf("End Program\t\t = [XX]\n");
	printf("_________________________________________________________________\n\n");
}

void scanInput() {
	char input[30];
	scanf_s(input);

	if(input)

	return input;
}


