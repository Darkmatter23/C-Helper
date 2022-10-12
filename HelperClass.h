#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class helper
{
public:
	ifstream infile;
	ofstream outfile;
	string templine;
	vector<string> lines;
	map<string, string>::iterator iter;
	void create_by_template(string);
	void replace(string, map<string, string>);
	void format(string);
};