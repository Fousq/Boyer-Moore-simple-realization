#include <iostream>
#include <string.h>//or cstring
using namespace std;

bool boyera_mura(string str, string substr);

int main()
{
	string str;
	string substr;
	cout << "Enter the string: ";
	cin >> str;
	cout << "Enter the substring:";
	cin >> substr;
	if (boyera_mura(str, substr))
	{
		cout << "Substring " << substr << " exists in the string " << str << endl;
	}
	else
	{
		cout << "Substring " << substr << " doesn't exuist in the string " << str << endl;
	}

	cin.get();
	return 0;
}

bool boyera_mura(string str, string substr)
{
	char *string = new char [str.length()];
	char *substring = new char [substr.length()];

	strcpy(string, str.c_str());
	strcpy(substring, substr.c_str());

	int str_len = str.length();
	int substr_len = substr.length();


	if (str_len > substr_len)
	{
		int s = 0;
		int i = substr_len - 1;
		int j = i;
		while (i <= str_len)
		{
			j = substr_len - 1;
			int k = i;

			while (j > 0 && string[k] == substring[j])
			{
				k--;
				j--;
			}

			if ( string[k] == substring[j])
			{
				return true;
			}

			while (j >= 0 && string[k] != substring[j])
			{
				j--;
			}

			if (j == -1)
			{
				i += substr_len;
				s += substr_len;
			}
			else
			{
				i += (k - (s + j));
				s += (k - (s + j));
			}
		}
		return false;
	}
	else
	{
		return false;
	}
}
