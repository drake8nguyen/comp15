#include<functional>
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include "Index.h"

using namespace std;

// Constructor
Index::Index()
{
	counter = 0;
}

// Function traverse
// Parameter: pointer to DirNode, string
// Return: void
// Does:Traverse the directory tree
// Open file and populate the hastable as it goes
void Index::traverse(DirNode* node, string directory)
{
	HashItem item;
    if (node == NULL)
    	return;
    //update directory when moving to a new node
    directory = directory + node->get_name() +"/";
    // traverse recursively on the children node
    for (int i = 0; i < node->num_subdirs(); i++)
    	traverse(node->get_subdir(i), directory);
    // if the directory has files in it
    if (node->has_files())
    {
    	//iterate through all the files
    	for (int i = 0; i < node->num_files(); i++)
    	{
    		// update HashItem's directory
    		// populate HashItem into Hash Table
    		item.set_directory(directory 
    			+ node->get_file(i));   		
    		populate_index(directory 
    			+ node->get_file(i), item);
    	}
    }
}

// Function populate index
// Parameter: file name, Hash Item 
// Return: void
// Does: fill the hash table with words inside a file
void Index::populate_index(string file_name, HashItem& item)
{
	ifstream infile;
	string line, word;
	int line_no = 0;

	infile.open(file_name.c_str());
	if(!infile.is_open())
		cerr << "Error opening file\n";

	// iterate through file
	while(!infile.eof())
	{
		// process line by line
		// update line and line number for the Hash Item
		getline(infile,line);
		vector<string> this_line;
		item.set_line(line);
		line_no++;
		item.set_line_no(line_no);

		// parse line into word	
		istringstream ss(line);
		while (ss >> word)
		{
			// update Hash Item's word
			item.set_word(remove_non_alphanum(word));
			this_line.push_back(word);
			// insert Hash Item into Hash Table
			// avoid duplicate on same line			
			bool existed = false;
			for (size_t i = 0; i 
				< this_line.size() - 1; i++)
			{
				if (remove_non_alphanum(word) == 
					remove_non_alphanum(this_line[i]))
				{
					existed = true;
					break;
				}
			}
			if (!existed)
				htab.insert(item);
		}
		this_line.clear();
	}
	infile.close();
}

// Function run
// Parameter: istream&, ostream& 
// Return: void
// Does: execute the search
void Index::run(istream& in, ostream& out)
{
	// end of file signal
	bool end = in.eof();
	do
	{
		end = in.eof();		
		// read input
		string query, line;
		out << "Query? ";
		getline(in, line); //changed from in >> line
		htab.set_case_sensitive();
		//parse input into words
		istringstream ss(line);
		while (ss >> query)
		{
			// set case insensitive
			if (query == "@i" || query == "@insensitive")
				htab.set_case_insensitive();
			// quit
			else if (query == "@q" || query == "@quit")
			{
				end = true;
				break;
			}
			// read in words, alphanumerical only
			// counter for instances of word in hash table
			// find the hash value of query
			// search through the chain at that hash value
			else
			{						
				string query2 = remove_non_alphanum(query);
				counter = 0;
				size_t location = htab.hash_value(query2);
				for (size_t i = 0; i < 
					htab.get_chain_size(location); i++)
					search_chain(query2, i);
				if ((counter == 0) && 
					(!htab.is_case_insensitive()))
					cout << remove_non_alphanum(query)
					<< " Not Found. Try with @insensitive or @i." 
					<< endl;
				else if ((counter == 0) && 
					(htab.is_case_insensitive()))
					cout << remove_non_alphanum(query)
					<< " Not Found." << endl;
			}
		}
		end = in.eof();		
	} while (!end);
	cout << endl << "Goodbye! Thank you and have a nice day." 
	<< endl;
}

// Function search chain
// Parameter: alphanumerical query, hash value 
// Return: void
// Does: search through a particular chain
void Index::search_chain(string query, 
	size_t chain_location)
{
	HashItem target = htab.retrieve(query, chain_location);
	// if target is not the dummy
	if (target.get_word() != "")
	{
		target.print();
		counter++;
	}	
}


// Function remove_non_alphanum
// Parameter: string 
// Return: string
// Does: strip a string of all 
// nonalphanumerical symbols
string Index::remove_non_alphanum(string orig) const
{

	string change = "";
	size_t start = 0;
	int end = orig.length() - 1;
	//case with no non-alphanumerical symbol;
	while ((!isalnum(orig[start])) 
		&& start < orig.length())
		start++;
	if (start == orig.length())
		return change;
	while ((!isalnum(orig[end])) && (end >= 0))
		end--;
	for (int i = start; i < end+1; i++)
		change += orig[i];
	return change;
} 