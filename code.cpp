#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;

void Displaymenu() {
	cout << "------------------------------------------------------------------\n";
	cout << "Welcome to Library Management System\n";
	cout << "Press 1: To see all the(available / unavailable) books\n";
	cout << "Press 2 : To return to the main menu\n";
	cout << "Press 3 : To add new books\n";
	cout << "Press 4 : To delete books from the available books\n";
	cout << "Press 5 : To edit the details of a book\n";
	cout << "Press 6 : To search a book from the Library management system\n";
	cout << "Press 7 : To check the book issue record\n";
	cout << "Press 0: To exit the Program\n";
	cout << "------------------------------------------------------------------\n";
}

void Fillupdata(int& linecount, char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {

	ifstream file;
	file.open("Books.txt", ios::app);
	//Read data
	char line[100];
	for (int i = 0; i < 100; i++) {		//Storing Nulls.
		line[i] = '\0';
	}
	if (file.is_open()) {
		while (file.getline(line, 99)) {
			linecount++;
		}
	}
	file.close();

	file.open("Books.txt");

	for (int i = 0; i < 100; i++) {		//Storing Nulls.
		line[i] = '\0';
	}

	int j = 0;
	if (file.is_open()) {
		while (file.getline(line, 99)) {
			char bnam[50] = "";
			char bnum[15];
			for (int j = 0; j < 15; j++) {
				bnum[j] = '\0';
			}
			char dep[15] = "";
			char avail[15] = "";
			char details[15] = "";
			int i = 0;
			int index = 0;
			while (!(line[i] >= 48 && line[i] <= 57)) {
				bnam[index] += line[i];
				i++;
				index++;
			}
			bnam[index - 1] = '\0';	//It was storing a extra space.
			
			index = 0;
			while (line[i] != ' ') {
				bnum[index] += line[i];
				i++;
				index++;
			}
			index = 0;
			i++;
			while (line[i] != ' ') {
				dep[index] += line[i];
				i++;
				index++;
			}
			i++;
			index = 0;
			while (line[i] != ' ') {
				avail[index] += line[i];
				i++;
				index++;
			}
			i++;
			index = 0;
			while (line[i] != '.') {
				details[index] += line[i];
				i++;
				index++;
			}

			for (int z = 0; z < 49; z++) {
				Bookname[j][z] = bnam[z];
			}
			for (int z = 0; z < 15; z++) {
				BookNumber[j][z] = bnum[z];
			}
			for (int z = 0; z < 15; z++) {
				Department[j][z] = dep[z];
			}
			for (int z = 0; z < 15; z++) {
				Availability[j][z] = avail[z];
			}
			for (int z = 0; z < 15; z++) {
				IssueDetails[j][z] = details[z];
			}
			j++;


			for (int i = 0; i < 100; i++) {		//Storing Nulls.
				line[i] = '\0';
			}
		}
	}
}

void availablebooks(int& linecount, char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {
	cout << "------------------------------------------------------------------\n";
	cout << "Book Name" << "\t\t\t\t" << "Book Number" << "\t" << "Department" << "\t" << "Availability" <<"\t"<< "Issued to" << endl;
	for (int i = 0; i < linecount; i++) {
		if (BookNumber[i][0] !='\0') {
			cout << Bookname[i] << "\t\t\t" << BookNumber[i] << "\t\t" << Department[i] << "\t" << Availability[i] << "\t" << IssueDetails[i] << endl;
		}
	}
	cout << "------------------------------------------------------------------\n";
}


void returnfunc() {
	Displaymenu();
}

void addbooks(char bnam[], char bnum[], char dep[], char avail[], char details[]) {
	ofstream file;
	file.open("Books.txt", ios::app);
	file <<endl <<bnam << " " << bnum << " " << dep << " " << avail << " " << details<<".";
}

void deletebooks(int& linecount,char bnum[], char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {
	bool found = 0;
	for (int i = 0; i < linecount; i++) {

		bool enterif = true;
		for (int k = 0; bnum[k] != '\0'; k++) {
			if (BookNumber[i][k] != bnum[k]) {
				enterif = false;
			}
		}

		if (enterif) {
			for (int z = 0; z < 49; z++) {
				Bookname[i][z] ='\0';
			}
			for (int z = 0; z < 15; z++) {
				BookNumber[i][z] = '\0';
			}
			for (int z = 0; z < 15; z++) {
				Department[i][z] = '\0';
			}
			for (int z = 0; z < 15; z++) {
				Availability[i][z] = '\0';
			}
			for (int z = 0; z < 15; z++) {
				IssueDetails[i][z] = '\0';
			}
			found = 1;
		}
	}
	if (found == 0) {
		cout << "Book not found"<<endl;
	}
}

void updatefile(int& linecount, char bnum[], char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {
	ofstream file;
	file.open("Books.txt");
	for (int i = 0; i < linecount; i++) {
		if (Bookname[i][0] != '\0') {
			file << Bookname[i] <<" "<< BookNumber[i] << " " << Department[i] << " " << Availability[i] << " " << IssueDetails[i] <<"."<<"\n";

		}
	}
}

void editbooks(int& linecount, char bnum[], char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {
	for (int i = 0; i < linecount; i++) {

		bool enterif = true;
		for (int k = 0; bnum[k] != '\0'; k++) {
			if (BookNumber[i][k] != bnum[k]) {
				enterif = false;
			}
		}
		if (enterif) {
			cout << "The book is " << Availability[i] << endl;
			int choice;

			char unav[] = "Unavailable";
			char av[] = "Available";

			bool enterunav = true;			//Comparing both arrays by loop.
			for (int u = 0; unav[u] != '\0'; u++) {
				if (Availability[i][u] != unav[u]) {
					enterunav = false;
				}
			}
			bool enterav= true;				//Comparing both arrays by loop.
			for (int u = 0; av[u] != '\0'; u++) {
				if (Availability[i][u] != av[u]) {
					enterav = false;
				}
			}
			if (enterunav) {
				cout << "Press 1: If you want to return the book? ";
				cin >> choice;
				IssueDetails[i][0] = '-';
				cout << "Book returned successfuly!!" << endl;
			}
			else if (enterav) {
				cout << "Press 1: If you want to issue this book. ";
				cin >> choice;

				char roll[15];
				for (int k = 0; k < 15; k++) {
					roll[k] = '\0';
				}
				cout << "Enter your rollno: Example(201934): ";
				cin >> roll;
				for (int m = 0; m < 15; m++) {
					IssueDetails[i][m] = roll[m];
				}
			}
		}
	}
}

void searchbooks(int& linecount, char bnum[], char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {
	for (int i = 0; i < linecount; i++) {
		bool enterif = true;
		for (int k = 0; bnum[k] != '\0'; k++) {
			if (BookNumber[i][k] != bnum[k]) {
				enterif = false;
			}
		}

		if (enterif) {
			cout << "The book is " << Availability[i] << endl;
		}
	}
}

void issuerecord(int& linecount, char bnum[], char Bookname[][50], char BookNumber[][15], char Department[][15], char Availability[][15], char IssueDetails[][15]) {
	for (int i = 0; i < linecount; i++) {
		bool enterif = true;
		for (int k = 0; bnum[k] != '\0'; k++) {
			if (BookNumber[i][k] != bnum[k]) {
				enterif = false;
			}
		}

		if (enterif) {
			cout << "The book is " << Availability[i] << endl;


			char unav[] = "Unavailable";
			bool enterunav = true;			//Comparing both arrays by loop.
			for (int u = 0; unav[u] != '\0'; u++) {
				if (Availability[i][u] != unav[u]) {
					enterunav = false;
				}
			}
			if (enterunav) {
				cout << "This book is issued to " << IssueDetails[i];
			}
		}
	}
}
int main() {
	char Bookname[10][50];
	char BookNumber[10][15];
	char Department[10][15];
	char Availability[10][15];
	char IssueDetails[10][15];

	int linecount = 0;	//For determining length if array.
	Fillupdata(linecount, Bookname, BookNumber, Department, Availability, IssueDetails);

		Displaymenu();
		int input;
		cin >> input;
		while (input != 0) {

			if (input == 1) {
				availablebooks(linecount, Bookname, BookNumber, Department, Availability, IssueDetails);
			}
			else if (input==2) {
				returnfunc();
			}
			else if (input==3) {
				char bnam[50] = "";
				char bnum[15] = "";
				char dep[15] = "";
				char avail[15] = "";
				char details[15] = "";

				cout << "Enter Book name: ";
				cin >> bnam;
				cout << "Enter Book number: ";
				cin >> bnum;
				cout << "Enter Department ";
				cin >> dep;
				cout << "Enter Availibilty: ";
				cin >> avail;
				cout << "Enter details: ";
				cin >> details;
				addbooks(bnam, bnum, dep, avail, details);
				linecount;
				for (int z = 0; z < 49; z++) {
					Bookname[linecount][z] = bnam[z];
				}
				for (int z = 0; z < 15; z++) {
					BookNumber[linecount][z] = bnum[z];
				}
				for (int z = 0; z < 15; z++) {
					Department[linecount][z] = dep[z];
				}
				for (int z = 0; z < 15; z++) {
					Availability[linecount][z] = avail[z];
				}
				for (int z = 0; z < 15; z++) {
					IssueDetails[linecount][z] = details[z];
				}
				linecount++;
			}
			else if (input==4) {
				char bnum[15];
				for (int i = 0; i < 15; i++) {
					bnum[i] = '\0';
				}
				availablebooks(linecount, Bookname, BookNumber, Department, Availability, IssueDetails);

				cout << "Enter book id :";
				cin >> bnum;
				deletebooks(linecount, bnum, Bookname, BookNumber, Department, Availability, IssueDetails);
				updatefile(linecount, bnum, Bookname, BookNumber, Department, Availability, IssueDetails);
			}
			else if (input == 5) {
				char bnum[15];
				for (int i = 0; i < 15; i++) {
					bnum[i] = '\0';
				}
				cout << "Enter book id: ";
				cin >> bnum;
				editbooks(linecount, bnum, Bookname, BookNumber, Department, Availability, IssueDetails);
				updatefile(linecount, bnum, Bookname, BookNumber, Department, Availability, IssueDetails);
			}
			else if (input == 6) {
				char bnum[15];
				for (int i = 0; i < 15; i++) {
					bnum[i] = '\0';
				}
				cout << "Enter book id: ";
				cin >> bnum;
				searchbooks(linecount, bnum, Bookname, BookNumber, Department, Availability, IssueDetails);

			}
			else if(input==7){
				char bnum[15];
				for (int i = 0; i < 15; i++) {
					bnum[i] = '\0';
				}
				cout << "Enter book id: ";
				cin >> bnum;
				issuerecord(linecount, bnum, Bookname, BookNumber, Department, Availability, IssueDetails);
			}
			cout << "\nEnter you choice again: (Hint 2 for main menu)";
			cin >> input;
		}
}