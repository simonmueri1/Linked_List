#include "stdio.h"
#include "stdlib.h"

void sequences();
void printMenu();
void scanInput();
struPerson* createList(int Anzahl) {}

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
	printMenu();
	int input = scanInput();

	switch (input)
		case 1:	
					createList();
					break;
		case 2: 
				break;
		case 3:
				break;
		case 4:
				break;
		case 5:
				break;

	system("pause");
}

void printMenu() {
	printf("_________________________________________________________________\n");
	printf("LINKED LIST - APP from Simon Mueri & Michel Leisibach v1.0\n");
	printf("_________________________________________________________________\n");
	printf("Create List\t\t = [1]\n");
	printf("Delete List\t\t = [2]\n");
	printf("Print List Elements\t\ = [3]\n");
	printf("Delete Element\t\t = [4]\n");
	printf("End Program\t\t = [5]\n");
	printf("_________________________________________________________________\n\n");
}

int scanInput() {
	char input = NULL;
	scanf_s("%c", input); 

	//start programm new if input is not valid.
	if (input > 0 && input < 6) {
		return input;
	}

	else {
		printf("Please enter a valid entry.");
		system("cls");
		main();
	}
	
}

int scanNumber() {
	char number = 0;
	printf("Enter a number.");
	scanf_s("%c", number);

	if (number > 10 && number < 0) {
		printf("Please enter a vaild number.\n");
			scanNumber();
	}

	return number;
}


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
