#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class bst{
public:
	int data;
	bst* left;
	bst* right;
	bst()
	{
		left = nullptr;
		right = nullptr;
	}
	bst(int data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
	bst* insert(bst* r, int f)
	{
		if (r == nullptr)
		{
			return new bst(f);
		}
		if (r->data > f)
		{
			r->left = insert(r->left, f);
		}
		else
		{
			r->right = insert(r->right, f);
		}
		return r;
	}
	void print(bst* r)
	{
		if (r == nullptr)
		{
			return;
		}
		cout << r->data<<"  :  ";
		if (r->left != nullptr)
		{
			cout << "L " << r->left->data;
		}
		if (r->right != nullptr)
		{

			cout << "  R " << r->right->data;
		}
		cout << "\n";
		print(r->left);
		print(r->right);

	}
	bst* deletee(bst* r, int n)
	{
		if (r == nullptr)
		{
			return nullptr;
		}
		if (r->data != n)
		{
			if (r->data > n)
			{
				r->left = deletee(r->left, n);
			}
			else
			{
				r->right = deletee(r->right, n);
			}
		}
		else
		{
			if (r->left == nullptr && r->right == nullptr)
			{
				return nullptr;
			}
			else if (r->left != nullptr && r->right == nullptr)
			{
				return r->left;
			}
			else if (r->left == nullptr && r->right != nullptr)
			{
				return r->right;
			}
			else
			{
				r->left->right = r->right;
				return r->left;
			}
			
		}
		return r;

	}
};

int main()
{
	bst* tree = nullptr;
	tree = tree->insert(tree, 10);
	tree = tree->insert(tree, 5);
	tree = tree->insert(tree, 4);
	tree = tree->insert(tree, 6);
	tree = tree->insert(tree, 15);
	tree = tree->insert(tree, 14);
	tree = tree->insert(tree, 16);
	tree->print(tree);
	tree = tree->deletee(tree, 15);
	cout << "-------------------\n";
	tree->print(tree);
	
	system("pause");

}