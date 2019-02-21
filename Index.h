#include "FSTree.h"	
#include "HashTable.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#ifndef INDEX_H_
#define INDEX_H_ 

class Index
{
	public:
		Index();
		void traverse(DirNode*, string);
		void populate_index(string, HashItem&);

		void search_chain(string, size_t);
		void run(istream &, ostream &);

		string remove_non_alphanum(string) const;

	private:
		HashTable htab;
		int counter;
};

#endif