#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

struct Car
{
	char model[20];
	char color[10];
	short year;
};

void PrintMenu();
void AddCar();
void PrintCarList();
void SearchCarByModel();
void SearchCarByYear();
void SearchCarByColor();
void AddToTxt(Car car);
bool CheckFile();
void CreateFile();
void DeleteFile();
bool CheckEmptyFile();
bool CharCompare(char *ch, char *structChar, short len);

int main()
{
	setlocale(LC_ALL, "rus");
	short menu;

	do
	{
		cout << "������� ��������...\n\n";
		PrintMenu();
		cout << "$user_input: ";
		cin >> menu; cout << endl;
		
		switch (menu)
		{
		case 1:
			AddCar();
			break;

		case 2:
			PrintCarList();
			break;

		case 3:
			SearchCarByModel();
			break;

		case 4:
			SearchCarByColor();
			break;

		case 5:
			SearchCarByYear();
			break;

		case 6:
			system("cls");
			break;

		case 7:
			DeleteFile();
			break;

		case 99:
			system("cls");
			break;

		default:
			cout << "�� ����� �������� �����...\n\n";
			break;
		}
	} while (menu != 99);

	return 0;
}

void DeleteFile()
{
	FILE *fp;
	fp = fopen("cars.txt", "w");
	fclose(fp);

	cout << "������ �������!\n\n";
}

void SearchCarByColor()
{
	if (CheckFile())
	{
		if (CheckEmptyFile())
		{
			cout << "������� ���� ������...\n";
			char color[10];
			cin >> color; cout << endl;
			
			short len = strlen(color);
			int count = 0;
			Car car;
			FILE *fp;
			fp = fopen("cars.txt", "r");

			while (!feof(fp))
			{
				fread(&car, sizeof(car), 1, fp);
				if (CharCompare(color, car.color, len))
				{
					cout << "����� : " << car.model << endl;
					cout << "���� : " << car.color << endl;
					cout << "��� : " << car.year << endl << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "����� �� ��� �����������... ���((\n\n";
		}
		else
			cout << "���... � ���� �� ������... -_-\n\n";
	}
	else
		CreateFile();
}

bool CharCompare(char *ch, char *structChar, short len)
{
	if (structChar[len] == '�' || structChar[len] == '\0')
		for (int i = 0; i < len; i++)
		{
			if (ch[i] != structChar[i])
				return false;
		}
	else
		return false;
	return true;
}

void SearchCarByYear()
{
	if (CheckFile())
	{
		if (CheckEmptyFile())
		{
			cout << "������� ��� ������...\n";
			short year;
			cin >> year; cout << endl;

			int count = 0;
			Car car;
			FILE *fp;
			fp = fopen("cars.txt", "r");
			while (!feof(fp))
			{
				fread(&car, sizeof(car), 1, fp);
				if (car.year == year)
				{
					cout << "����� : " << car.model << endl;
					cout << "���� : " << car.color << endl;
					cout << "��� : " << car.year << endl << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "����� �� ��� �����������... ���((\n\n";
		}
		else
			cout << "���... � ���� �� ������... -_-\n\n";
	}
	else
		CreateFile();
}

void PrintCarList()
{
	if (CheckFile())
	{
		if (CheckEmptyFile())
		{
			Car car;
			FILE *fp;
			fp = fopen("cars.txt", "r");
			fread(&car, sizeof(car), 1, fp);

			while (!feof(fp))
			{
				cout << "����� : " << car.model << endl;
				cout << "���� : " << car.color << endl;
				cout << "��� : " << car.year << endl << endl;
				fread(&car, sizeof(car), 1, fp);
			}
		}
		else
			cout << "���... � ���� �� ������... -_-\n\n";
	}
	else
		CreateFile();
}

bool CheckEmptyFile()
{
	FILE *fp;
	fp = fopen("cars.txt", "r");
	fseek(fp, 0, SEEK_END);
	long pos = ftell(fp);
	if (pos > 0)
		return true;
	return false;
}

void CreateFile()
{
	cout << "���... �������, ����� �� ���������� ���� �� ����������... ������� �����?\n";
	cout << "Y[��]/N[���]\n\n";
	cout << "$user_input: ";
	char ch; cin >> ch; cout << endl;
	if (ch == 'Y')
	{
		FILE *fp;
		fp = fopen("cars.txt", "a");
	}

	cout << "���� ������!\n\n";
}

void SearchCarByModel()
{
	if (CheckFile())
	{
		if (CheckEmptyFile())
		{
			cout << "������� ����� ������...\n";
			char model[20];
			cin >> model; cout << endl;

			short len = strlen(model);
			int count = 0;
			Car car;
			FILE *fp;
			fp = fopen("cars.txt", "r");
			while (!feof(fp))
			{
				fread(&car, sizeof(car), 1, fp);
				if (CharCompare(model, car.model, len))
				{
					cout << "����� : " << car.model << endl;
					cout << "���� : " << car.color << endl;
					cout << "��� : " << car.year << endl << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "����� �� ��� �����������... ���((\n\n";
		}
		else
			cout << "���... � ���� �� ������... -_-\n\n";
	}
	else
		CreateFile();
}

void AddCar()
{
	if (CheckFile())
	{
		cout << "������� ������ ������...\n\n";
		cout << "$user_input: ";
		char model[20];
		cin >> model; cout << endl;

		cout << "������� ���� ������...\n\n";
		cout << "$user_input: ";
		char color[10];
		cin >> color; cout << endl;

		cout << "������� ��� ������...\n\n";
		cout << "$user_input: ";
		short year;
		cin >> year; cout << endl;

		Car car;
		strcpy(car.model, model);
		strcpy(car.color, color);
		car.year = year;

		AddToTxt(car);
		cout << "������ ������� ���������!\n\n";
	}
	else
		CreateFile();
}

void AddToTxt(Car car)
{
	FILE *fp;
	fp = fopen("cars.txt", "a");
	fwrite(&car, sizeof(car), 1, fp);
	cout << "��� ������ ���� ������� ��������� � ������!\n\n";
	fclose(fp);
}

bool CheckFile()
{
	FILE *fp;
	if ((fp = fopen("cars.txt", "r+")) != NULL)
		return true;
	return false;
}

void PrintMenu()
{
	cout << "1.�������� ������ � ���� ������;\n";
	cout << "2.���������� ������ �����;\n";
	cout << "3.����� ����� �� �����;\n";
	cout << "4.����� ����� �� �����;\n";
	cout << "5.����� ����� �� ���� �������;\n";
	cout << "6.�������� �������;\n";
	cout << "7.������� ������;\n";
	cout << "99.�����.\n\n";
}