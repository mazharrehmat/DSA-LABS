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

	void insertatbegining(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	

	}

	void deletenode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
    node* prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        delete temp;
        cout << "Node deleted" << endl;
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node deleted" << endl;
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
	l.insertatbegining(21);
	l.display();
	l.deletenode(21);
	l.display();




	return 0;
}
