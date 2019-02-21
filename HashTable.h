#include <iostream>
#include <string>
#include <vector>
#include "HashItem.h"

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

// const int MAX_ITEMS = 20000;

class HashTable
{
public:
    HashTable();

    HashTable & operator = (const HashTable &);


    bool is_full() const;

    HashItem retrieve(string, size_t) const;
    void insert(HashItem);
    size_t get_size() const;
    size_t get_chain_size(size_t) const; 
    size_t hash_value(string) const;
    bool same_lower_case(string, string) const;
    void set_case_insensitive(); 
    void set_case_sensitive();
    bool get_found() const;
    bool is_case_insensitive() const;
    
private:
    void expand();
    vector<vector<HashItem> > htab;
    double load_factor;
    double no_key;
    bool case_insensitive;
};

#endif
