#include <algorithm>
#include <string>
#include<iostream>
using namespace std;

#define PERSONS_LIMIT 50

int countPersons = 0;


class Persons {
public:
	int Id;
	char Name[20];
	int Age;
	char Dob[20];
	char Position[30];
	char Gender;
};

Persons obj[PERSONS_LIMIT];

void input() {

	if (countPersons < PERSONS_LIMIT)
	{
		cout << "\n Enter id (number): ";
		cin >> obj[countPersons].Id;
		cout << "\n Enter Name (20 characters): ";
		cin >> obj[countPersons].Name;
		cout << "\n Enter Age (number): ";
		cin >> obj[countPersons].Age;
		cout << "\n Enter DOB (dd-mm-yy): ";
		cin >> obj[countPersons].Dob;
		cout << "\n Enter Position : ";
		cin >> obj[countPersons].Position;
		cout << "\n Enter Gender (M/F) : ";
		cin >> obj[countPersons].Gender;
		countPersons++;
	}
	else
	{
		cout << "\n Error : Limit is only " << PERSONS_LIMIT;
	}
}

void printAll() {
	cout << "\n **** **** Printing All Records **** ****";
	cout << "\n total number of persons : " << countPersons << endl;
	for (int i = 0; i < countPersons; i++) {
		cout << "\n Id : " << obj[i].Id;
		cout << "\t Name : " << obj[i].Name;
		cout << "\t Age : " << obj[i].Age;
		cout << "\t DOB : " << obj[i].Dob;
		cout << "\t Position: " << obj[i].Position;
		cout << "\t Gender : " << obj[i].Gender;
	}
}

void printbyAge() {
	cout << "\n **** **** Printing All Records by Age********";
	int count50plus = 0;
	int count40plus = 0;
	int lessthen40 = 0;

	for (int i = 0; i < countPersons; i++) {
		if (obj[i].Age > 50)
			count50plus++;
		else if (obj[i].Age > 40)
			count40plus++;
		else
			lessthen40++;
	}

	cout << "\n Persons more than 50 : " << count50plus;
	cout << "\n Persons more than 40 : " << count40plus;
	cout << "\n Persons less than 40 : " << lessthen40;
}


void printGenderCount() {
	cout << "\n **** **** Printing All Records by Sex Count ********";
	int ml = 0;
	int fl = 0;

	for (int i = 0; i < countPersons; i++) {
		if (obj[i].Gender == 'M')
			ml++;
		else if (obj[i].Gender == 'F')
			fl++;
	}
	cout << "\n Number of Male : " << ml;
	cout << "\n Number of Female : " << fl;
}

int main() {

	int choice = -1;

	while (choice != 0) {
		cout << "\n\n ============Proram Menu==========";
		cout << "\n 1 Input Records ";
		cout << "\n 2 Print All Records";
		cout << "\n 3 Print by Age";
		cout << "\n 4 Print by Gender count";
		cout << "\n 0 to exit";

		cout << "\n Enter you choice : ";
		cin >> choice;

		switch (choice) {

		case 1: input(); break;
		case 2: printAll(); break;
		case 3: printbyAge(); break;
		case 4: printGenderCount(); break;
		case 0: cout << "\n Hope you like the program !!"; break;
		default: cout << "\n Error: Invalid Selection: Try Again";
		}

	}

	return 0;

}