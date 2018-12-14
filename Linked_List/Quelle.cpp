#include "stdio.h"
#include "stdlib.h"

void sequences();
void printMenu();

void main() {
	sequences();
}


void sequences() {
	printMenu();
}

void printMenu() {
	printf("_________________________________________________________________\n");
	printf("LINKED LIST - APP from Simon Mueri & Michel Leisibach v1.0\n");
	printf("_________________________________________________________________\n");
	printf("Create List\t\t = [C]\n");
	printf("Delete List\t\t = [DE]\n");
	printf("Print List Elements\t\ = [P] + (Number)\n");
	printf("Print all\t\t = [P] +fsadf (0)\n");
	printf("Delete Element\t\t = [DE] + (Firstname + Lastname)\n");
	printf("End Program\t\t = [X]\n");
	printf("_________________________________________________________________\n\n");
	
	system("pause");

}


