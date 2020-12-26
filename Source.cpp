// Lab_08_1.cpp 
// < �������� ������ > 
// ����������� ������ � 8.1 
// ������ 1

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>

using namespace std;

int Count(char* str)
{
	if (strlen(str) < 2)
		return 0;
	int k = 0;
	for (int i = 0; str[i + 1] != 0; i++)
		if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
			k++;
	return k;
}

char* Change(char* str)
{
	if (strlen(str) < 2)
		return str;
	char* tmp = new char[strlen(str) * 4 / 2 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	int i = 0;
	while (str[i + 1] != 0)
	{
		if (str[i] == 'n' && str[i + 1] == 'o')
		{
			strcat(t, "***");
			t += 3;
			i += 2;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}

int main()
{
	char str[128];

	cout << "Enter string: ";
	cin.getline(str, 128);

	cout << "String contained " << Count(str) << " groups of 'no' or 'on'" << endl;

	char* dest = new char[256];
	dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}
