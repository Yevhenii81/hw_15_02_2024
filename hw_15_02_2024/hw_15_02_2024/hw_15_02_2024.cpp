#include <iostream>
#include <string>
#include <stack>
using namespace std;

void Verification(string math)
{
	stack<char> parentheses;

	parentheses.push(math[0]);

	for (int i = 1; i < math.length(); i++)
	{
		if (math[i] == '(' || math[i] == '[' || math[i] == '{')
		{
			parentheses.push(math[i]);
		}
		else if (math[i] == ')')
		{
			if (parentheses.top() == '(')
				parentheses.pop();
			else
				break;
		}
		else if (math[i] == ']')
		{
			if (parentheses.top() == '[')
				parentheses.pop();
			else
				break;
		}
		else if (math[i] == '}')
		{
			if (parentheses.top() == '{')
				parentheses.pop();
			else
				break;
		}
	}

	if (parentheses.empty())
	{
		cout << "correct expression" << "\n";

	}
	else
	{
		cout << "wrong expression" << "\n";
	}
};

int main()
{
	string mathFirst = "{(5-[3+<9>])-4}";
	cout << mathFirst << " - ";
	Verification(mathFirst);

	string mathSecond = "{(<5->[3 +)9-4]}";
	cout << mathSecond << " - ";
	Verification(mathSecond);
}
