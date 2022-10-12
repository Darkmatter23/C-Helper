#include "HelperClass.h"

int main(int argc,char* argv[])
{
	helper myhelper;
	map<string, string> repmap;

	if (string(argv[1]) == "format")
	{
		myhelper.format(argv[2]);
	}
	else if (string(argv[1]) == "create-by-template")
	{
		myhelper.create_by_template(argv[2]);
	}
	else if (string(argv[1]) == "replace")
	{
		for (int i = 4; i < argc; i += 3)
		{
			string oldstr = string(argv[i]);
			oldstr = oldstr.substr(0, oldstr.length() - 1);
			string newstr = string(argv[i + 1]);
			repmap[oldstr]= newstr;
		}
		myhelper.replace(argv[2], repmap);
	}
	return 0;
}