#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class doublylinkedlist {
private:
    node* head;

public:
    doublylinkedlist() {
        head = NULL;
    }

    void insertatend(int value) {
        node* newnode = new node(value);

        if (head == NULL) {
            head = newnode;
            return;
        }

        node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    void insertatstart(int value) {
        node* newnode = new node(value);

        if (head == NULL) {
            head = newnode;
            return;
        }

        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    void insertatposition(int value, int position) {
        if (position <= 1 || head == NULL) {
            insertatstart(value);
            return;
        }

        node* newnode = new node(value);
        node* temp = head;
        int count = 1;

        while (temp->next != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL) {
            temp->next = newnode;
            newnode->prev = temp;
        }
        else {
            newnode->next = temp->next;
            newnode->prev = temp;

            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }

    void deletebyvalue(int value) {
        if (head == NULL) {
            cout << "list is empty. nothing to delete." << endl;
            return;
        }

        node* temp = head;

        if (head->data == value) {
            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            }

            delete temp;
            cout << value << " deleted from the list." << endl;
            return;
        }

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << value << " not found in the list." << endl;
            return;
        }

        if (temp->next == NULL) {
            temp->prev->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << value << " deleted from the list." << endl;
    }

    void displayforward() {
        if (head == NULL) {
            cout << "list is empty." << endl;
            return;
        }

        node* temp = head;

        cout << "forward : ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayreverse() {
        if (head == NULL) {
            cout << "list is empty." << endl;
            return;
        }

        node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "reversed : ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main() {
    doublylinkedlist dll;

    dll.insertatend(34);
    dll.insertatend(25);
    dll.insertatend(45);

    dll.insertatstart(5);

    dll.insertatposition(15, 3);

    cout << "list after insertion:" << endl;
    dll.displayforward();
    dll.displayreverse();

    dll.deletebyvalue(5);
    dll.deletebyvalue(34);
    dll.deletebyvalue(45);

    cout << endl;
    cout << "list after deletion:" << endl;

    dll.displayforward();
    dll.displayreverse();

    return 0;
}