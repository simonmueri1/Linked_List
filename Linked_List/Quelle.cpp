#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

typedef struct Person {
	char Vorname[40];
	char Nachname[40];
	int Jahrgang;
	struct Person* pNext;
} struPerson;

void sequences();
void printMenu();
struPerson* createFirstPerson(struPerson* firstPerson);
void addPerson(struPerson* head);
int randomNumber();
int scanNumber();
int sortvalue;
void printList(struPerson* element, int number);
int countElements(struPerson* firstPerson);
struPerson* deleteList(struPerson* firstPerson);
struPerson* deleteElements(struPerson* firstPerson, char vorname[40], char nachname[40]);
void sortlist(struPerson* firstPerson);
bool personnamesize(Person* person1, Person* person2);




int main() {
	sequences();
	return 0;
}

void sequences() {
	//define randomness
	srand((unsigned)time(NULL));
	Person *pHead = NULL;

	int numberOfElements = 0;
	struPerson* firstPerson = NULL;
	char vorname[40];
	char nachname[40];
	

	
	printMenu();
	
	while (true) {
		switch (scanNumber()) {
		case 1:
			printf("How many people do you want to create? ");
			scanf_s("%i", &numberOfElements);
			getchar();
			for (int i = 1; i <= numberOfElements; i++) {
				if (i == 1)
					firstPerson = createFirstPerson(firstPerson);
				else
					addPerson(firstPerson);
			}
			break;
			
		case 2:
			firstPerson = deleteList(firstPerson);
			break;
		case 3:
			printf("How many Elements do you want to print? ");
			scanf_s("%i", &numberOfElements);
			getchar();
			printList(firstPerson, numberOfElements);
			break;
		case 4:
			printf("Enter Vorname: ");
			scanf_s(" %c", &vorname);
			getchar();
			printf("Enter Nachname: ");
			scanf_s(" %c", &nachname);
			getchar();
			firstPerson = deleteElements(firstPerson, vorname, nachname);
			break;
			
		case 5:
			exit(0);
			break;

		case 6:
			printf("By wich criteria do you wanna sort?\n");
			printf("Sort by 'Datum'		[1]\n");
			printf("Sort by 'Vorname'	[2]\n");
			printf("Sort by 'Nachname'	[3]\n");
			scanf_s("%i", &sortvalue);
			getchar();
			sortlist(firstPerson);
			break;

		case 7:
			printMenu();
			break;

		default:
			break;
		}
	}
}

void printMenu() {
	printf("_________________________________________________________________\n");
	printf("LINKED LIST - APP from Simon Mueri & Michel Leisibach v1.0\n");
	printf("_________________________________________________________________\n");
	printf("Create List\t\t = [1]\n");
	printf("Delete List\t\t = [2]\n");
	printf("Print List Elements\t = [3]\n");
	printf("Delete Element\t\t = [4]\n");
	printf("End Program\t\t = [5]\n");
	printf("Sort List\t\t = [6]\n");
	printf("Print menu\t\t = [7]\n");
	printf("_________________________________________________________________\n\n");
}
	
struPerson* createFirstPerson(struPerson* firstPerson) {
	firstPerson = (struPerson*)malloc(sizeof(struPerson));

	if (firstPerson == NULL)
		return firstPerson;

	firstPerson->Vorname[0] = 'A' + rand() % 26;
	firstPerson->Vorname[1] = '\0';
	firstPerson->Nachname[0] = 'A' + rand() % 26;
	firstPerson->Nachname[1] = '\0';
	firstPerson->Jahrgang = randomNumber();
	firstPerson->pNext = NULL;

	return firstPerson;
}

void addPerson(struPerson* head) {
	struPerson* current = head;
	while (current->pNext != NULL) {
		current = current->pNext;
	}

	current->pNext = (struPerson*)malloc(sizeof(struPerson));
	current->pNext->Vorname[0] = 'A' + rand() % 26;
	current->pNext->Vorname[1] = '\0';
	current->pNext->Nachname[0] = 'A' + rand() % 26;
	current->pNext->Nachname[1] = '\0';
	current->pNext->Jahrgang = randomNumber();
	current->pNext->pNext = NULL;
}

int scanNumber() {
	int number;
	printf("Enter a menu number: ");
	scanf_s("%i", &number);

	if (number > 0 && number < 8) {
		return number;
	}
	else {
		printf("Please enter a vaild number.\n");
		getchar();
		scanNumber();
		return 0;
	}
}

int randomNumber()
{
	int result = 0, low_num = 1900, hi_num = 2018;
		
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}

void printList(struPerson* element, int number) {

	if (countElements(element) < 1) {
		printf("List is empty\n");
		return;
	}
	
	struPerson* current = element;
	if (number == 0) {
		while (current != NULL) {
			printf("%i\t %s\t %s\n",current->Jahrgang, current->Vorname, current->Nachname);
			current = current->pNext;
		}
	}
	else {
		for (int i = 1; current != NULL && i <= number; i++) {
			printf("%i\t %s\t %s\n", current->Jahrgang, current->Vorname, current->Nachname);
			current = current->pNext;
		}
	}
}

int countElements(struPerson* firstPerson) {
	struPerson* current = firstPerson;
	int numberOfElements = 0;

	if (firstPerson == NULL)
		return 0;

	while (current != NULL) {
		current = current->pNext;
		numberOfElements++;
	}

	return numberOfElements;
}

struPerson* deleteList(struPerson* firstPerson) {
	int numberOfElements = countElements(firstPerson);
	for (int i = 0; i < numberOfElements; i++) {
		if (firstPerson != NULL) {
			if (firstPerson->pNext == NULL) {
				free(firstPerson);
				firstPerson = NULL;
			}
			else {
				struPerson* personToDelete = firstPerson;
				firstPerson = firstPerson->pNext;
				free(personToDelete);
				personToDelete = NULL;
			}
		}
	}
	return firstPerson;
}

struPerson* deleteElements(struPerson* firstPerson, char vorname[40], char nachname[40]) {
	struPerson* current = firstPerson;
	struPerson* previous = NULL;

	while (current != NULL && firstPerson != NULL) {
		if (current->Vorname[0] == vorname[0] && current->Nachname[0] == nachname[0]) {
			if (firstPerson->pNext == NULL) {
				free(firstPerson);
				firstPerson = NULL;
			}
			else if(previous == NULL){
				struPerson* personToDelete = firstPerson;
				firstPerson = firstPerson->pNext;
				current = firstPerson;
				free(personToDelete);
				personToDelete = NULL;
			}
			else {
				previous->pNext = current->pNext;
				free(current);
				current = NULL;
			}
		}
		if (current == NULL) {
			current = previous->pNext;
		}
		else {
			previous = current;
			current = current->pNext;
		}
	}
	return firstPerson;
}

void sortlist(struPerson* firstPerson) {

	struPerson* element1;
	struPerson* element2;
	Person* Person1;
	Person* Person2;
	int temp;
	char temp2[40];
	
	if (firstPerson != NULL) {
		if (sortvalue == 1) {
			for (element1 = firstPerson; element1->pNext != NULL; element1 = element1->pNext) {
				for (element2 = element1->pNext; element2 != NULL; element2 = element2->pNext) {
					if (element1->Jahrgang > element2->Jahrgang) {
						temp = element1->Jahrgang;
						element1->Jahrgang = element2->Jahrgang;
						element2->Jahrgang = temp;
					}
				}
			}
		}
	}
	else if (sortvalue == 2) {

		

		for (element1 = firstPerson; element1 != NULL; element1->pNext) {
			for (element2 = element1->pNext; element2 != NULL; element2 = element2->pNext) {

				Person1 = element1;
				Person2 = element2;

				while (strcmp(Person1->Vorname, Person2->Vorname) > 0) {
					
					while (strcmp(Person1->Nachname, Person2->Nachname) > 0) {

						/*temp2 = element1->Vorname;
						element1->Vorname = element2->Vorname;
						element2->Vorname = temp2;*/

					}

				}
			}
		}
	}

	else if (sortvalue == 3) {

	}
		
		else {
			printf("Please create first a List!");
			getchar();
			printMenu();
		}
	}




