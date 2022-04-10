#include<iostream>
using namespace std;

template<typename t>
class stack{
private:
	t* arr;
	int top;
	int max;
public:
	stack(int m)
	{
		max = m;
		top = -1;
		arr = new t[m];
		for (int i = 0; i < m; i++)
		{
			arr[i] = 0;
		}
	}
	bool isfull()
	{
		if (top == max - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isempty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(t val)
	{
		if (isfull())
		{
			cout << "full hain\n";
		}
		else
		{
			top++;
			arr[top] = val;
		}
	}
	t pop()
	{
		if (isempty())
		{
			cout << "empty bro\n";
			return 0;
		}
		else
		{
			t temp = arr[top];
			arr[top] = 0;
			top--;
			return temp;
		}
	}
	void display()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}
};
char* regrow(char* old, int& size, char add)
{
	char* neww = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		neww[i] = old[i];
	}
	neww[size] = add;
	neww[size + 1] = '\0';
	size++;
	old = nullptr;
	delete[] old;
	
	return neww;
}
void getcount(int& op, char* eq)
{
	for (int i = 0; eq[i] != '\0'; i++)
	{
		if (eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/' || eq[i] == '(')
		{
			op++;
		}
	}
}

stack<int> evaluating(char* infix)
{
	stack<int> ss(10);
	int operand1;
	int operand2;
	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (infix[i] >= '0'&&infix[i] <= '9')
		{
			int n = infix[i];
			n = n - 48;
			ss.push(n);

		}
		else
		{
			operand2 = ss.pop();
			operand1 = ss.pop();
			if (infix[i] == '+')
			{
				ss.push(operand1 + operand2);
			}
			else if (infix[i] == '-')
			{
				ss.push(operand1 - operand2);
			}
			else if (infix[i] == '*')
			{
				ss.push(operand1 * operand2);
			}
			else if (infix[i] == '/')
			{
				ss.push(operand1 / operand2);
			}

		}
	}
	return ss;
}
int main()
{
	char* infix = new char;
	int size = 0;
	char eq[40];
	cout << "enter your infix : ";
	cin >> eq;
	system("cls");
	int op = 0;
	getcount(op, eq);
	stack<char> s(op);
	for (int i = 0; eq[i] != '\0'; i++)
	{
		if (eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/' || eq[i] == '(')
		{
			s.push(eq[i]);
		}
		else if (eq[i] == ')')
		{
		here:
			char temp = s.pop();
			if (temp != '(')
			{
				infix = regrow(infix, size, temp);
				goto here;
			}
			else
			{
				continue;
			}
		}
		else
		{
			infix = regrow(infix, size, eq[i]);
		}
	}
	while (!s.isempty())
	{
		char temp = s.pop();
		
		infix = regrow(infix, size, temp);
	}
	cout << "\t\t\t\tyour infix is  :  " << eq << "\n";
	cout << "\t\t\t\tyour post fix is  :  " << infix << "\n";
	stack<int> ss =  evaluating(infix);
	cout << "\t\t\t\tyour evaluted postfix is ";
	ss.display();
	system("pause");


}