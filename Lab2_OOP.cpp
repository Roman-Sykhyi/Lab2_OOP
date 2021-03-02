#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

class CharSet
{
private:
	char* str;
	int strLength;

public:
	CharSet()
	{
		str = new char[1];
		strLength = 0;
	}

	CharSet(const char* str)
	{
		SetString(str);
	}
	~CharSet() 
	{
		delete[] str;
	}

	void SetString(const char* str)
	{
		strLength = strlen(str);
		this->str = new char[strLength+1];
		strcpy(this->str, str);
	}

	void Print()
	{
		cout << str << endl;
	}

	bool IsEqualTo(const char* strToCompare)
	{
		return strcmp(str, strToCompare);
	}

	bool IsGreaterThan(const char* strToCompare)
	{
		return strlen(str) > strlen(strToCompare);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CharSet charSet("Привіт світ!");
	//charSet.Set("Привіт світ!");

	charSet.Print();

	if (charSet.IsEqualTo("Привіт світ!") == 0) 
	{
		cout << "Рядки однакові" << endl;
	}
	else
	{
		cout << "Рядки відрізняються" << endl;
	}

	if (charSet.IsGreaterThan("Привіт світ!"))
	{
		cout << "Перший рядок більший за другий" << endl;
	}
	else
	{
		cout << "Другий рядок більший або рівний з першим" << endl;
	}
	
	system("pause");
}