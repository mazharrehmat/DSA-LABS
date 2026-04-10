#include <iostream>
using namespace std;

class node {
public:
    string name;
    int p;
    node* next;
};

class book {
    node* head;

public:
    book() {
        head = NULL;
    }

    void add(string n, int pr) {
        node* temp = new node();
        temp->name = n;
        temp->p = pr;
        temp->next = NULL;

        if (head == NULL || pr < head->p) {
            temp->next = head;
            head = temp;
            return;
        }

        node* cur = head;
        while (cur->next != NULL && cur->next->p <= pr) {
            cur = cur->next;
        }

        temp->next = cur->next;
        cur->next = temp;
    }

    void remove(string n) {
        if (head == NULL) {
            cout << "empty" << endl;
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

    void update(string n, int pr) {
        remove(n);
        add(n, pr);
    }

    void serve() {
        if (head == NULL) {
            cout << "no student" << endl;
            return;
        }

        node* del = head;
        cout << "served: " << del->name << endl;
        head = head->next;
        delete del;
    }

    void show() {
        node* cur = head;
        while (cur != NULL) {
            cout << cur->name << "(" << cur->p << ") -> ";
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
    book b1, b2;

    cout << "book1 data" << endl;
    b1.add("ali", 2);
    b1.add("ahmad", 1);
    b1.add("sara", 3);

    b1.show();
    cout << "total: " << b1.count() << endl;

    cout << "\nupdate priority (ali -> 1)" << endl;
    b1.update("ali", 1);
    b1.show();

    cout << "\nserve book1" << endl;
    b1.serve();
    b1.show();

    cout << "\nremove sara" << endl;
    b1.remove("sara");
    b1.show();

    cout << "\n\nbook2 data" << endl;
    b2.add("zain", 3);
    b2.add("usman", 1);
    b2.add("hira", 2);

    b2.show();
    cout << "total: " << b2.count() << endl;

    cout << "\nserve book2" << endl;
    b2.serve();
    b2.show();

    return 0;
}