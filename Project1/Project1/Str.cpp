#include "Str.h"
#include <string.h>
#include<iostream>
using namespace std;

Str::Str(int leng)
{
	if (leng < 0)
		cout << "Error!" << endl;
	else
	{
		len = leng;
		str = new char[leng + 1];
	}
}
Str::Str(const char* neyong)
{
	if (neyong == NULL)
	{
		cout << "Error!" << endl;
	}
	else
	{
		len = strlen(neyong);
		str = new char[len + 1];
		strcpy(str, neyong);
	}
}
Str::~Str()
{
	delete(str);
}
int Str::length(void)
{
	return len;
}
char* Str::contents(void)
{
	return str;
}
int Str::compare(class Str& a)
{
	return strcmp(str, a.contents());
}
int Str::compare(const char* a)
{
	return strcmp(str, a);
}
void Str::operator=(const char* a)
{
	delete(str);
	if (a == NULL)
	{
		len = 0;
		str = new char[0];
		str = '\0';
	}
	else
	{
		len = strlen(a);
		str = new char[len + 1];
		strcpy(str, a);
	}
}
void Str::operator=(class Str& a)
{
	delete(str);
	len = a.length();
	str = new char[len + 1];
	strcpy(str, a.contents());
}