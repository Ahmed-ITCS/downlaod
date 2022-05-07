#include<iostream>
using namespace std;

template<typename t>
class stack{
	t* arr;
	int current;
	int max;
public:
	stack(int s)
	{
		max = s;
		arr = new t[s];
		current = -1;
		for (int i = 0; i < max; i++)
		{
		  arr[i] = 0;
		}
	}
	bool isfull()
	{
		if (current == max - 1)
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
		if (current == -1)
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
			cout << "can't push full\n";
		}
		else
		{
			current++;
			arr[current] = val;
		}
	}
	t pop()
	{
		if (isempty())
		{
			cout << "it's empty can't pop\n";
		}
		else
		{
			t temp = arr[current];
			arr[current] = 0;
			current--;
			return temp;
		}
	}
	void display()
	{
		for (int i = 0; i < max; i++)
		{
			cout << arr[i] << endl;
		}
	}

};

int main()
{
	stack<int> s(6);
	s.display();
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.display();
	system("pause");
}
