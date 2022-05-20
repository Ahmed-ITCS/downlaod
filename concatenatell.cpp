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
		//ignore this funtion
		/*ll<tt> reverse()
		{
		ll<tt> l;
		node<tt>* temp = head;
		node<tt>* temp2 = head->getnext();
		while (head != nullptr)
		{
		if (temp2->getnext() == nullptr)
		{
		l.append(temp2);
		temp->setnext(nullptr);
		temp2 == nullptr;
		temp2 = head->getnext();
		temp = head;
		if (head->getnext() == nullptr)
		{
		l.append(head);
		head == nullptr;
		}

		}
		else
		{
		cout << "6/\n";
		temp2 = temp2->getnext();
		temp = temp->getnext();
		}
		if (head == nullptr)
		{
		break;
		}
		}
		return l;
		}*/
		
		ll<tt> concatenate(ll<tt>& l1, ll<tt>& l2)
		{
			ll<tt> l;
			l.head = l1.head;
			node<tt>* temp = l2.head;
			while (temp != nullptr)
			{
				l.append(temp);
				temp = temp->getnext();
			}
			return l;
		}


};
int main()
{
	node<int>* n1 = new node<int>(1, 10);
	node<int>* n2 = new node<int>(2, 20);
	node<int>* n3 = new node<int>(3, 30);
	node<int>* n4 = new node<int>(4, 40);
	ll<int> l1;
	l1.append(n1);
	l1.append(n2);
	ll<int> l2;
	l2.append(n3);
	l2.append(n4);

	l1.show();
	l2.show();
	ll<int> l3;
	l3 = l3.concatenate(l1, l2);
	l3.show();
	system("pause");
}
