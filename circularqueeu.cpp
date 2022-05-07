#include<iostream>
using namespace std;

template<typename t>
class queue{
private:
	t* arr;
	int rear;
	int front;
	int size;
public:
	queue(int s)
	{
		size = s;
		arr = new t[s];
		rear = -1;
		front = -1;
		for (int i = 0; i < size; i++)
		{
		  arr[i] = 0;
		}
	}
	bool isfull()
	{
		if ((rear+1)%size == front)
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
		if (rear == -1 && front == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue(t val)
	{
		if (isfull())
		{
			cout << "can't push full\n";
		}
		else if (isempty())
		{
			rear = 0;
			front = 0;
			arr[rear] = val;
		}
		else
		{
			rear = (rear+1)%size;
			arr[rear] = val;
		}
	}
	t pop()
	{
		if (isempty())
		{
			cout << "it's empty can't pop\n";
		}
		else if (rear == front)
		{
			rear = -1;
			front = -1;
		}
		else
		{
			
			t temp = arr[front];
			arr[front] = 0;
			front = (front + 1) % size;
			return temp;
		}
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "   ";
		}
		cout << endl;
	}

};

int main()
{
	queue<int> q(6);
	q.display();
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.pop();
	q.pop();
	q.enqueue(2);
	q.enqueue(2);
	q.display();
	system("pause");
}
