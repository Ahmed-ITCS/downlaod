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
		void sort()
		{
			node<tt>* n1 = head;
			node<tt>* n2 = head;
			for  (; n1!=nullptr ; n1=n1->getnext())
			{
				for (n2=head; n2 != nullptr; n2 = n2->getnext())
				{
					if (n1->getdata()>n2->getdata())
					{
						int temp;
						temp = n1->getdata();
						n1->setdata(n2->getdata());
						n2->setdata(temp);
						temp = n1->getkey();
						n1->setkey(n2->getkey());
						n2->setkey(temp);

					}
				}
			}
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
	l1.append(n3);
	l1.append(n4);
	l1.show();
	l1.sort();
	l1.show();
	system("pause");
}
