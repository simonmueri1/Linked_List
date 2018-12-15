#include "stdio.h"
#include "stdlib.h"

void sequences();
void printMenu();
void scanChar();
struPerson* createList(int Anzahl)

void main() {
	sequences();
}

typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	struct Person* pNext;
} struPerson;

void sequences() {
	char input[30];

	printMenu();
	input = scanChar();

	switch (input)
		case CL:	
					createList();
					break;
		case DL: 
				break;
		case PE:
				break;
		case DE:
				break;
		case XX:
				break;

	system("pause");
}

void printMenu() {
	printf("_________________________________________________________________\n");
	printf("LINKED LIST - APP from Simon Mueri & Michel Leisibach v1.0\n");
	printf("_________________________________________________________________\n");
	printf("Create List\t\t = [CL]\n");
	printf("Delete List\t\t = [DL]\n");
	printf("Print List Elements\t\ = [PE]\n");
	printf("Print all\t\t = [PE0]\n");
	printf("Delete Element\t\t = [DE]\n");
	printf("End Program\t\t = [XX]\n");
	printf("_________________________________________________________________\n\n");
}

char scanChar() {
	char input[];
	scanf_s(input);

	//start programm new if input is not valid.
	if (input != "CL" || input != "DL" || input != "PE" || input != "PE0" || input != "DE" || input != "XX") {
		printf("Please enter a valid entry.");
		system("cls");
		main();
	}

	return input;
}

int scanNumber(){
	int number = 0;
	printf("Enter a number.");
	scanf_s(number);

	if (number != 0..9) {
		printf("Please enter a vaild number.\n")
			scanNumber();
	}														

	return number;


struPerson* createList(int Anzahl) {
	// Erstellt eine Liste von definierter Anzahl Elementen.
	struPerson* pStart = NULL;
	struPerson* pLast = NULL;

	for (int iElm = 0; iElm < Anzahl; iElm) {
		struPerson* pNew = (struPerson*)malloc(sizeof(struPerson));
		pNew->Nummer = iElm + 1;
		pNew->pNext = NULL;
		if (pStart == NULL) pStart = pNew;
		if (pLast != NULL) pLast->pNext = pNew;
		pLast = pNew;
	}
	return pStart;
}
