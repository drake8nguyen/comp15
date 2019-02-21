#include<string>
#include<iostream>

using namespace std;

#ifndef HashItem_H
#define HashItem_H

class HashItem
{
    public:
    	HashItem();
    	HashItem(string, int, string, string);
   	 	// HashItem & operator = (const HashItem &);

   		friend bool operator == (const HashItem &, const HashItem &);
   		
    	string get_word() const;
      string get_directory() const;
      int get_line_no() const;
      string get_line() const;

    	void set_word(string);
    	void set_directory(string);
    	void set_line_no(int);
      void set_line(string);

      string get_lower_case() const;

      void print() const;
    private:
	    string word;
	    int line_no;
	    string directory;
      string line;
    
};

#endif
