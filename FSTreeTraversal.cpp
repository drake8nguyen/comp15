/*
Minh Duc Nguyen (Drake)
Comp 15 Project 2 phase 1
*/

#include "FSTree.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void traversal(DirNode *, string);

//main function
int main(int argc, char *argv[])
{
	//check number of argument
	if (argc != 2)
	{
		if (argc < 2)
			cerr << "Missing directory\n";
		else
			cerr << "One at a time\n";
		return 0; 
	}

    //create new tree object
	FSTree fst(argv[1]);
	DirNode *dn = fst.get_root();

	traversal(dn, "");

	return 0; 
}


//function traversal
//return void
//parameter: pointer to node, string
//does traverse the tree
void traversal (DirNode *node, string directory)
{
    if (node == NULL)
    	return;
    //if node is empty
    if (node->is_empty())
    {
        cout << directory + node->get_name() << endl;
        return;
    }

    directory = directory + node->get_name() +"/";
    //traverse recursively on the children node
    for (int i = 0; i < node->num_subdirs(); i++)
    	traversal(node->get_subdir(i), directory);
    //if the directory has file in it
    if (node->has_files())
    {
    	for (int i = 0; i < node->num_files(); i++)
    		cout << directory << node->get_file(i) << endl;
    }

}
