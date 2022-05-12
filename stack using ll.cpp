#include<iostream>
using namespace std;

template<typename t>
class node{
private:
	t data;
	int key;
	node* next;
public:
	node()
	{
		next = nullptr;
	}
	node(int k, int d)
	{
		data = d;
		key = k;
		next = nullptr;
	}
	void setkey(int k)
	{
		key = k;
	}
	void setdata(int d)
	{
		data = d;
	}
	void setnext(node* n)
	{
		next = n;
	}
	t getdata()
	{
		return data;
	}
	int getkey()
	{
		return key;
	}
	node* getnext()
	{
		return next;

	}
};

template<typename tt>
class stack{
private:
	node<tt>* top;
public:
	stack()
	{
		top = nullptr;
	}
	void push(tt data)
	{
		node<tt>* n = new node<tt>(data, data);
		if (top == nullptr)
		{
			top = n;
			n->setnext(nullptr);
		}
		else
		{
			n->setnext(top);
			top = n;
		}

	}
	tt pop()
	{
		tt temp = top->getdata();
		top = top->getnext();
		return temp;
	}
	void display()
	{
		node<tt>*  temp = top;
		while (temp != nullptr)
		{
			cout << temp->getdata();
			temp = temp->getnext();
		}
	}
};

/*class stack{
private:
	node<tt>* top;
public:
	stack()
	{
		top == nullptr;
	}
	void push(node<tt>* n)
	{
		if (top == nullptr)
		{
			top = n;
			n->setnext(nullptr);
		}
		else
		{
			n->setnext(top);
			top = n;
		}
		
	}
	tt pop()
	{
		tt temp = top->getdata();
		top = top->getnext();
		return temp;
	}
	void display()
	{
		node<tt>*  temp = top;
		while (temp != nullptr)
		{
			cout << temp->getdata();
			temp = temp->getnext();
		}
	}
};*/



int main()
{
	node<int>* n1 = new node<int>(1, 10);
	node<int>* n2 = new node<int>(2, 20);
	node<int>* n3 = new node<int>(3, 30);
	node<int>* n4 = new node<int>(4, 40);
	stack<int> s;
	s.push(1);
	s.push(2);
	s.display();
	cout << s.pop();
	system("pause");
}

