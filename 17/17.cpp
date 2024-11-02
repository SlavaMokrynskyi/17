#include <iostream>
#include <iomanip>
#include <string>
#define SIZE 10;
using namespace std;

int** AddColumn(int** parr, int index, int CountArr, int CountElements)
{

	int** new_parr = new int* [CountArr];
	for (int i = 0; i < CountArr; i++)
	{
		new_parr[i] = new int[CountElements + 1];
	}
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements + 1; j++)
		{
			if (j < index)
			{
				new_parr[i][j] = parr[i][j];
			}
			else if (j == index)
			{
				new_parr[i][j] = 0;
			}
			else
			{
				new_parr[i][j] = parr[i][j - 1];
			}
		}
	}
	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

	return new_parr;
}

int** DeleteColumn(int** parr, int index, int CountArr, int CountElements)
{

	int** new_parr = new int* [CountArr];
	for (int i = 0; i < CountArr; i++)
	{
		new_parr[i] = new int[CountElements - 1];
	}
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements - 1; j++)
		{
			if (j < index)
			{
				new_parr[i][j] = parr[i][j];
			}
			else if (j >= index)
			{
				new_parr[i][j] = parr[i][j + 1];
			}
		}
	}
	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

	return new_parr;
}

int** MoveArr(int** parr, int times, int CountArr, int CountElements)
{
	int choice_1, choice_2;
	cout << "Chose in what direction you need move arr\n1)Right\n2)Down\n3)Left\n4)Up\n";
	cin >> choice_1;
	cout << "If you want to move in one more direction enter a different one from the first choice \n1)Right\n2)Down\n3)Left\n4)Up\n";
	cin >> choice_2;

	int temp;
	if (choice_1 == 1 || choice_2 == 1)
	{
		for (int t = 0; t < times; t++)
		{
			for (int i = 0; i < CountArr; i++)
			{
				temp = parr[i][CountElements - 1];
				for (int j = CountElements - 1; j > 0; j--)
				{
					parr[i][j] = parr[i][j - 1];
				}
				parr[i][0] = temp;
			}
		}
	}
	if (choice_1 == 2 || choice_2 == 2)
	{

		for (int t = 0; t < times; t++)
		{
			for (int j = 0; j < CountElements; j++)
			{
				temp = parr[CountArr - 1][j];
				for (int i = CountArr - 1; i > 0; i--)
				{
					parr[i][j] = parr[i - 1][j];
				}
				parr[0][j] = temp;
			}
		}
	}
	if (choice_1 == 3 || choice_2 == 3)
	{
		for (int t = 0; t < times; t++)
		{
			for (int i = 0; i < CountArr; i++)
			{
				temp = parr[i][0];
				for (int j = 0; j < CountElements - 1; j++)
				{
					parr[i][j] = parr[i][j + 1];
				}
				parr[i][CountElements - 1] = temp;
			}
		}
	}
	if (choice_1 == 4 || choice_2 == 4)
	{
		for (int t = 0; t < times; t++)
		{
			for (int j = 0; j < CountElements; j++)
			{
				temp = parr[0][j];
				for (int i = 0; i < CountArr - 1; i++)
				{
					parr[i][j] = parr[i + 1][j];
				}
				parr[CountArr - 1][j] = temp;
			}
		}
	}
	return parr;
}


int** TransponseArr(int** parr, int CountArr, int CountElements)
{
	int** new_parr = new int* [CountElements];

	for (int i = 0; i < CountElements; i++)
	{
		new_parr[i] = new int[CountArr];
	}

	for (int i = 0; i < CountElements; i++)
	{
		for (int j = 0; j < CountArr; j++)
		{
			new_parr[i][j] = parr[j][i];
		}
	}

	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;

	return new_parr;
}

string** InitializeArr(string** parr, int countofcontacts)
{
	cin.ignore();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < countofcontacts; j++)
		{
			if (i == 0)
			{
				cout << "Enter name of contact: ";
				string name;
				getline(cin, name);
				parr[i][j] = name;
			}
			else
			{
				cout << "Enter phone number for " << parr[i - 1][j] << endl;
				string phone;
				getline(cin, phone);
				parr[i][j] = phone;
			}
		}
	}
	return parr;
}

void ShowArr(string** parr, int countofcontacts)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < countofcontacts; j++)
		{
			cout <<setw(15)<< parr[i][j];
		}
		cout << endl;
	}
}

void SearchIndexByName(string** parr, int countofcontacts, string name)
{
	int index;
	for (int j = 0; j < countofcontacts; j++)
	{
		if (parr[0][j] == name)
		{
			index = j;
		}
	}
	cout << "Name : " << parr[0][index] << endl;
	cout << "Phone : " << parr[1][index] << endl;
}

void SearchIndexByPhone(string** parr, int countofcontacts, string phone)
{
	int index;
	for (int j = 0; j < countofcontacts; j++)
	{
		if (parr[1][j] == phone)
		{
			index = j;
		}
	}
	cout << "Name : " << parr[0][index] << endl;
	cout << "Phone : " << parr[1][index] << endl;
}

string** AddNewContact(string** parr, int countofcontacts)
{
	string name, phone;
	cout << "Enter name for your new contanct: ";
	cin >> name;
	cout << "Enter phone for your new contanct: ";
	cin >> phone;
	string** New_Contacts = new string * [2];
	for (int i = 0; i < 2; i++)
	{
		New_Contacts[i] = new string[countofcontacts + 1];
	}
	New_Contacts[0][countofcontacts + 1] = name;
	New_Contacts[1][countofcontacts + 1] = phone;
	return New_Contacts;
}

string** EditContact(string** parr, int countofcontacts, int index)
{
	string phone, name;
	int choice;
	cout << "What you need to edit?\n1)Name\n2)Phone";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter new name: ";
		getline(cin, name);
		parr[0][index] = name;
		break;
	case 2:
		cout << "Enter new phone: ";
		getline(cin, phone);
		parr[0][index] = phone;
		break;
	}
}

int main()
{
	/*srand(time(NULL));
	int CountArr, CountElements;
	cout << "Enter count of arr -> ";
	cin >> CountArr;
	cout << "Enter count of elements -> ";
	cin >> CountElements;

	int** parr = new int* [CountArr];

	for (int i = 0; i < CountArr; i++)
	{
		parr[i] = new int[CountElements];
	}
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements; j++)
		{
			parr[i][j] = rand() % 100;
		}
	}

	int index = 0;
	cout << "Enter index -> ";
	cin >> index;
	if (index > CountElements || index < 0)
	{
		cout << "Invalid index!" << endl;
		return 1;
	}
	parr = AddColumn(parr, index, CountArr, CountElements);


	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements + 1; j++)
		{
			cout << setw(3) << parr[i][j];
		}
		cout << endl;
	}

	parr = DeleteColumn(parr, index, CountArr, CountElements + 1);
	for (int i = 0; i < CountArr; i++)
	{
		for (int j = 0; j < CountElements; j++)
		{
			cout << setw(3) << parr[i][j];
		}
		cout << endl;
	}
	parr = TransponseArr(parr, CountArr, CountElements);
	for (int i = 0; i < CountElements; i++)
	{
		for (int j = 0; j < CountArr; j++)
		{
			cout << setw(3) << parr[i][j];
		}
	}

	for (int i = 0; i < CountArr; i++)
	{
		delete[] parr[i];
	}
	delete[] parr;*/
	int CountOfContacts;
	cout << "How many contacts in contact book? ";
	cin >> CountOfContacts;
	string** Contacts = new string * [2];
	for (int i = 0; i < 2; i++)
	{
		Contacts[i] = new string[CountOfContacts];
	}

	Contacts = InitializeArr(Contacts, CountOfContacts);
	ShowArr(Contacts, CountOfContacts);

	string name;
	cout << "Enter what name need to find -> ";
	cin >> name;
	SearchIndexByName(Contacts, CountOfContacts, name);

	string phone;
	cout << "Enter what phone need to find -> ";
	cin >> phone;
	SearchIndexByPhone(Contacts, CountOfContacts, phone);
}