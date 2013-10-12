#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;

bool get_result(bool empty, const char c, const char top, size_t pos)
{
	bool found = false;
	bool flag = false;

	if (empty)
		flag = false;
	else
		flag = (c == '}' && top == '{') || (c == ']' && top == '[') || (c == ')' && top == '(');
	
	if (!flag)
	{
		cout << "FALSE" << endl;
		cout << pos << endl;
		found = true;
	}

	return found;
}

void match(const string &str)
{
	stack<char> cs;
	bool found = false;
	for (size_t i = 0; i < str.size(); ++i)
	{
		switch(str[i])
		{
			case '{':
			case '[':
			case '(':
				cs.push(str[i]);
				break;

			case '}':
			case ']':
			case ')':
				{
					size_t pos = i;
					if (i == str.size() - 1)
						pos = str.size();

					if (cs.empty())
						found = get_result(true, str[i], str[i], pos);
					else
					{
						char c = cs.top();
						cs.pop();
						found = get_result(false, str[i], c, pos);
					}
				}
				break;

			default:
				break;
		}

		if (found)
			break;
	}

	if (!found)
	{
		cout << "TRUE" << endl;
		cout << 0 << endl;
	}
}

int main()
{
	freopen("02.in", "r", stdin);

	string s;
	while (cin >> s)
	{
		match(s);
	}

	fclose(stdin);
	return 0;
}