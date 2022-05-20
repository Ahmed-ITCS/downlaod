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
class ll{
private:
	node<tt>* head;
public:	ll()
{
			head = nullptr;
}
		ll(node<tt>* n)
		{
			head = n;
		}
		node<tt>* exist(int k)
		{
			node<tt>* temp = head;
			while (temp != nullptr)
			{
				if (temp->getkey() == k)
				{
					return temp;
				}
				temp = temp->getnext();
			}
			return 0;
		}
		void append(node<tt>* n)
		{
			if (exist(n->getkey()))
			{
				cout << "alredy in there bro\n";
			}
			else
			{
				if (head == nullptr)
				{
					head = n;
				}
				else
				{
					node<tt>* temp = head;
					while (temp->getnext() != nullptr)
					{
						temp = temp->getnext();
					}
					temp->setnext(n);
					n->setnext(nullptr);
				}
			}
		}
		void prepend(node<tt>* n)
		{
			if (exist(n->getkey()))
			{
				cout << "alredy exist\n";
			}
			else
			{
				if (head == nullptr)
				{
					head = n;
				}
				else
				{
					n->setnext(head);
					head = n;
				}
			}
		}
		void insert(int k, node<tt>* n)
		{
			if (head == nullptr)
			{
				append(n);
			}
			node<tt>* ptr = exist(k);
			if (ptr)
			{
				n->setnext(ptr->getnext());
				ptr->setnext(n);
			}
			else
			{
				cout << "it doesn't exist\n";
			}
		}
		void deletee(int k)
		{
			if (head->getkey() == k)
			{
				node<tt>* t = head;
				head = head->getnext();
				t = nullptr;
				delete[]t;

			}
			node<tt>* temp = head;
			node<tt>* temp2 = head->getnext();

			while (temp2 != nullptr)
			{
				if (temp2->getkey() == k)
				{
					temp->setnext(temp2->getnext());
					temp2 = nullptr;
					delete[] temp2;

					break;
				}
				temp = temp->getnext();
				temp2 = temp2->getnext();
			}
		}
		void show(int k,node<int>* temp)
		{
			if (temp->getkey() == k)
			{
				deletee(k);
				return;
			}
			else
			{
				show(k, temp->getnext());
			}
			
		}
		node<tt>* gethead()
		{
			return head;
		}
		void show()
		{
			node<tt>* temp = head;
			while (temp != nullptr)
			{
				cout << temp->getkey() << "          " << temp->getdata() << endl;
				temp = temp->getnext();
			}
			cout << "-------------------\n";
		}
};



int main()
{
	int input[8];
	for (int i = 0; i<8; i++)
	{
		cout << "enter " << i + 1 << "  ";
		cin >> input[i];
	}
	node<int>* n1 = new node<int>(1, input[0]);
	node<int>* n2 = new node<int>(2, input[1]);
	node<int>* n3 = new node<int>(3, input[2]);
	node<int>* n4 = new node<int>(4, input[3]);
	node<int>* n5 = new node<int>(5, input[4]);
	node<int>* n6 = new node<int>(6, input[5]);
	node<int>* n7 = new node<int>(7, input[6]);
	node<int>* n8 = new node<int>(8, input[7]);
	ll<int> l;
	l.append(n1);
	l.append(n2);
	l.append(n2);
	l.append(n3);
	l.append(n4);
	l.append(n5);
	l.append(n6);
	l.append(n7);
	l.show();
	node<int>* temp = l.gethead();
	int k;
	cout << "enter the key to delete : ";
	cin >> k;
	l.show(k,temp);
	l.show();

	system("pause");
}