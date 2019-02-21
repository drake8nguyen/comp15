#include<string>
#include<functional>
#include<vector>
#include "HashTable.h"
using namespace std;

// Default constructor
HashTable::HashTable()
{
    htab.resize(20000);
    no_key = 0;
    case_insensitive = false;
}


// Function has value
// Parameter: string 
// Return: size_t
// Does: find the hash value of a string
// convert that string to lower case before hashing
size_t HashTable::hash_value(string s) const
{
	string lower = s;
	for (size_t i = 0; i < s.length(); i++)
 		lower[i] = tolower(s[i]);

	hash<string> hash;
	return hash(lower) % htab.size();
}


// Function: retrieve
// Parameters: string, size_t
// Returns: HashItem
// Does: get the HashItem that correspond to the query
// by searching through a specific chain
HashItem HashTable::retrieve(string query, size_t chain_location) const
{
	//get position of the chain
	size_t location = hash_value(query); //edge case, empty chain etc
	//case insensitive
	if (case_insensitive)
	{	
		// return if lower case versions match
		string lower = query;
		for (size_t i = 0; i < query.length(); i++)
 			lower[i] = tolower(query[i]);	
		string s = htab[location][chain_location].get_lower_case();
		if (s == lower)
			return htab[location][chain_location];
	}
	// case sensitive
	// return if the string matches exactly
	else if (htab[location][chain_location].get_word() == query)
		return htab[location][chain_location];
	// return dummy if cannot find
	HashItem dummy("", 0, "", "");
	return dummy;

}

// Function expand
// Parameter: none 
// Return: void
// Does: expand the hash table by
// making a copy of the hashtable, clearing the copy
// expanding the size of the copy
// rehashing all value in the old table into the copy
void HashTable::expand() 
{
	HashTable new_table = *this; 
	new_table.htab.clear();
	new_table.htab.resize(htab.size()*2);

	for (size_t i = 0; i < htab.size(); i++)
	{
		for (size_t j = 0; j < htab[i].size(); j++)
		{
			size_t location = 
			new_table.hash_value(htab[i][j].get_word());
			new_table.htab[location].push_back(htab[i][j]);
		}
	}
	*this = new_table;
	
}
// Function: insert
// Parameters: HashItem
// Returns: void
// Does: insert an item into the table
void HashTable::insert(HashItem item)
{
	// exist the hash table if load factor too high
	load_factor = no_key/(double)htab.size();
	if (load_factor > 0.7)
		expand();
	// determine the hash valyue of the item
	// insert the item, update total key number
	else
	{
		size_t location = hash_value(item.get_word());
			no_key++;	
			htab[location].push_back(item);
	}
	return;
}

//assignment operator to be used in the expand function
HashTable & HashTable::operator = (const HashTable &orig)
{
	htab.clear();
	htab = orig.htab;
	load_factor = orig.load_factor;
	no_key = orig.no_key;
	return *this;
}

// Function set case insensitive
// Parameter: none 
// Return: void
// Does: turn on case insensitive
void HashTable::set_case_insensitive()
{
	case_insensitive = true;
}

// Function set case sensitive
// Parameter: none 
// Return: void
// Does: turn on case sensitive
void HashTable::set_case_sensitive()
{
	case_insensitive = false;
}


// Function check case insensitive
// Parameter: none 
// Return: bool
// Does: check if case insensitive
bool HashTable::is_case_insensitive() const
{
	return case_insensitive;
}

// Function get size
// Parameter: none 
// Return: size_t
// Does: return size of table
size_t HashTable::get_size() const
{
	return htab.size();
}


// Function get chain size
// Parameter: size_t position of chain 
// Return: size_t
// Does: return size of chain at a give position
size_t HashTable::get_chain_size(size_t location) const
{
	return htab[location].size();
}