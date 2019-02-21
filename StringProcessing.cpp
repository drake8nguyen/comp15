/*
Minh Duc Nguyen (Drake)
Comp 15 Project 2 phase 1
*/
#include "FSTree.h"
#include <string>
#include <iostream>

using namespace std;

string remove_non_alphanum(string);

int main()
{
	string query;
	while (!cin.eof())
	{
		cout << "Enter query: \n";
		cin >> query;
		cout << remove_non_alphanum(query) << endl; 
	}
	
	return 0; 
}


//function remove_non_alphanum
//parameter: original string
//return: alphanumerical-only string
//does remove non-alphanumerical symbol in a string
string remove_non_alphanum(string orig)
{

	string change = "";
	size_t start = 0;
	int end = orig.length() - 1;
	//case with no non-alphanumerical symbol;
	while ((!isalnum(orig[start])) && start < orig.length())
		start++;
	if (start == orig.length())
		return change;

	while ((!isalnum(orig[end])) && (end >= 0))
		end--;
	for (int i = start; i < end+1; i++)
		change += orig[i];
	return change;
} 