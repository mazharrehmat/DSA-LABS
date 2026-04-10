#include <iostream>
using namespace std;

class node {
public:
    string name;
    node* next;
};

class list {
    node* head;

public:
    list() {
        head = NULL;
    }

    void add(string n) {
        node* temp = new node();
        temp->name = n;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
        }
    }

    void remove(string n) {
        if (head == NULL) {
            cout << "list empty" << endl;
            return;
        }

        if (head->name == n) {
            node* del = head;
            head = head->next;
            delete del;
            return;
        }

        node* cur = head;
        while (cur->next != NULL && cur->next->name != n) {
            cur = cur->next;
        }

        if (cur->next != NULL) {
            node* del = cur->next;
            cur->next = del->next;
            delete del;
        } else {
            cout << "not found" << endl;
        }
    }

    void show() {
        node* cur = head;
        while (cur != NULL) {
            cout << cur->name << " -> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }

    int count() {
        int c = 0;
        node* cur = head;
        while (cur != NULL) {
            c++;
            cur = cur->next;
        }
        return c;
    }
};

int main() {
    list l;

    l.add("ali");
    l.add("ahmad");
    l.add("sara");

    cout << "patients: ";
    l.show();

    cout << "total: " << l.count() << endl;

    l.remove("ahmad");

    cout << "after remove: ";
    l.show();

    cout << "total: " << l.count() << endl;

    return 0;
}