#include "HashItem.h"
#include<string>
#include<iostream>

using namespace std;

//default constructor
HashItem::HashItem()
{

}

// parameterize constructor
HashItem::HashItem(string s, int i, string d, string l)
{
	word = s;
	line_no = i;
	directory = d;
	line = l;

}

// HashItem & HashItem::operator = (const HashItem &hi)
// {
// 	word = hi.word;
// 	line_no = hi.line_no;
// 	directory = hi.directory;
// }


// Function get word
// Parameter: none 
// Return: string
// Does: getter function for the word
string HashItem::get_word() const
{
	return word;
}

// Function get directory
// Parameter: none 
// Return: string
// Does: getter function for the directory
// the word appears in
string HashItem::get_directory() const
{
	return directory;
}


// Function get line no
// Parameter: none 
// Return: string
// Does: getter function for the line number
// the word appears on
int HashItem::get_line_no() const
{
	return line_no;
}

// Function get line
// Parameter: none 
// Return: string
// Does: getter function for the line the word
// appears on
string HashItem::get_line() const
{
	return line;
}

// Function set word
// Parameter: string 
// Return: void
// Does: edit the word
void HashItem::set_word(string s)
{
	word = s;
}


// Function set directory
// Parameter: string 
// Return: void
// Does: edit the word's directory
void HashItem::set_directory(string s)
{
	directory = s;
}

// Function set line number
// Parameter: int 
// Return: void
// Does: setter function for line number
void HashItem::set_line_no(int i)
{
	line_no = i;
}

// Function set line
// Parameter: string 
// Return: void
// Does: setter function for the line
void HashItem::set_line(string l)
{
	line = l;
}

// operator == overloader
bool operator == (const HashItem &h1, const HashItem &h2)
{
	return ((h1.word == h2.word) && (h1.directory == h2.directory) 
			&& (h1.line_no == h2.line_no));
}

// Function print
// Parameter: none 
// Return: void
// Does: print the word and relevant info
void HashItem::print() const
{
	cout << directory;
	cout << ":";
	cout << line_no;
	cout << ": ";
	cout << line << endl;

}

// Function get lower case
// Parameter: none 
// Return: string
// Does: return the lower case version of the word
string HashItem::get_lower_case() const
{
	string lower_case = word;
	for (size_t i = 0; i < lower_case.length(); i++)
		lower_case[i] = tolower(lower_case[i]);
	return lower_case;
}