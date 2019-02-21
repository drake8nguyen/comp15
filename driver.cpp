#include"Index.h"
#include<string>
#include<iostream>

using namespace std;


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc < 2)
			cerr << "Missing directory\n";
		else
			cerr << "One at a time\n";
		return 0; 
	}

	Index gerp;
	// create FSTree
	FSTree fst(argv[1]); 
	DirNode *dn = fst.get_root();

	// populate tree
	gerp.traverse(dn, "");

	// search
	gerp.run(cin, cout);
	
	return 0;
}