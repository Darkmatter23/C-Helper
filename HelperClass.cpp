#include "HelperClass.h"
using namespace std;

void helper::create_by_template(string address)
{
	outfile.open(address);
	outfile << "#include <iostream>\n#include <vector>\n#include <string>\n\nusing namespace std;\n\ntypedef vector<int> ints\ntypedef vector<string> strings\n\nint main() {\n\treturn 0;\n}" << endl;
	outfile.close();
}

void helper::replace(string address, map<string,string> repmap)
{
	//Input
	infile.open(address);
	while (! infile.eof() )
	{
		getline(infile,templine);
		lines.push_back(templine);
	}
	infile.close();
	// Edit
	outfile.open(address);
	for (iter = repmap.begin(); iter != repmap.end(); iter++)
	{
		for (int i = 0; i < lines.size(); i++)
		{
			string oldstr = iter->first;
			string newstr = iter->second;
			int pos=lines[i].find(oldstr);
			while (pos != string::npos)
			{
				lines[i].replace(pos, oldstr.length(), newstr);
				pos = lines[i].find(oldstr);
			}
		}
	}
	//Output
	for (int i = 0; i < lines.size(); i++) 
	{
		outfile << lines[i] << endl;
	}
	lines.clear();
	outfile.close();
}

void helper::format(string address)
{
	infile.open(address);
	int lines_count = 0, max_func_len=0;
	//Input
	while (!infile.eof())
	{
		getline(infile, templine);
		lines.push_back(templine);
		lines_count++;
	}
	infile.close();
	outfile.open(address);
	//cerr << "inja1" << endl;
	//Edit
	//8 Space To Tab
	for (int i = 0; i < lines.size(); i++)
	{
		int pos = lines[i].find("        ");
		while (pos != string::npos)
		{
			lines[i].replace(pos, 8, "\t");
			pos = lines[i].find("        ");
		}
	}
	//cerr << "inja2" << endl;
	//Comment
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].length() == 0)
			continue;
		if (lines[i][0] == '/' && lines[i][1] == '*')
		{
			//halati ke /* dar ye khat tanha bashad
			if (lines[i].length() == 2)
			{
				lines.erase(lines.begin() + i);
				while (true) {
					lines[i] = "//" + lines[i];
					if (lines[i + 1].length() == 0)
					{
						i++;
						continue;
					}
					if (lines[i + 1][0] == '*' && lines[i + 1][1] == '/')
					{
						lines.erase(lines.begin() + i + 1);
						break;
					}
					else if (lines[i + 1][lines[i + 1].length() - 1] == '/' && lines[i + 1][lines[i + 1].length() - 2] == '*')
					{
						lines[i + 1] = lines[i + 1].substr(0, lines[i + 1].length() - 2);
						break;
					}
					i++;
				}
				break;
			}
			//halati ke bad az /* comment shoroo she
			else
			{
				lines[i] = "//" + lines[i].substr(2, lines[i].length() - 2);
				i++;
				while (true)
				{
					lines[i] = "//" + lines[i];
					if (lines[i + 1].length() == 0)
					{
						i++;
						continue;
					}
					if (lines[i + 1][0] == '*' && lines[i + 1][1] == '/')
					{
						lines.erase(lines.begin() + i + 1);
						break;
					}
					else if (lines[i + 1][lines[i + 1].length() - 1] == '/' && lines[i + 1][lines[i + 1].length() - 2] == '*')
					{
						lines[i + 1] = lines[i + 1].substr(0, lines[i + 1].length() - 2);
						break;
					}
					i++;
				}
				break;
			}
		}
	}
	//cerr << "inja3" << endl;
	//Max Function Length
	int c=0, start, end,length;
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].find('{') != string::npos)
		{
			if (c == 0)
			{
				int pos = lines[i].find('{');
				if (lines[i].length() != 1)
					if (pos + 1 == lines[i].length())
						start = i + 1;
					else
						start = i;
				else start = i + 1;
			}
			c++;
		}
		else if (lines[i].find('}') != string::npos)
		{
			if (c == 1)
			{
				if (lines[i].length() != 1)
					end = i;
				else end = i - 1;
				length = end - start + 1;
				if (length > max_func_len)
					max_func_len = length;
			}
			c--;
		}
	}
	//cerr << "inja4" << endl;

	//Output
	for (int i = 0; i < lines.size(); i++)
	{
		outfile << lines[i] << endl;
	}
	//Print
	cout << "Lines: " << lines_count << endl;
	cout << "Max Func Length: " << max_func_len;
	lines.clear();
	outfile.close();
}
