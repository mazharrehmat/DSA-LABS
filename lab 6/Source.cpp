#include<iostream>
using namespace std;

class node {

public:
	int data;
	node* next;
};

class list {
private:
	node* head;
public:

	list()
	{
		head = NULL;
	}

	void createnode(int value)
	{
		node* curr=head;
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else {

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}

	}


	void display()
	{
		node* temp = head;

		while(temp!=NULL)
		{ 
		
			cout << temp->data << endl;
			temp = temp->next;
		
		}
	}



};

int main()
{

	list l;
	int value;
	

	l.createnode(10);
	l.createnode(20);
	l.display();




	return 0;
}
