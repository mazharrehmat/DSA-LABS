#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class list {
    node* head;

public:
    list() {
        head = NULL;
    }

    void insert(int val, int pos) {
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;

        if (pos == 1) {
            temp->next = head;
            head = temp;
            return;
        }

        node* cur = head;
        for (int i = 1; i < pos - 1 && cur != NULL; i++) {
            cur = cur->next;
        }

        if (cur == NULL) {
            cout << "invalid position" << endl;
            return;
        }

        temp->next = cur->next;
        cur->next = temp;
    }

    void del(int pos) {
        if (head == NULL) {
            cout << "list empty" << endl;
            return;
        }

        if (pos == 1) {
            node* del = head;
            head = head->next;
            delete del;
            return;
        }

        node* cur = head;
        for (int i = 1; i < pos - 1 && cur->next != NULL; i++) {
            cur = cur->next;
        }

        if (cur->next == NULL) {
            cout << "invalid position" << endl;
            return;
        }

        node* del = cur->next;
        cur->next = del->next;
        delete del;
    }

    void search(int val) {
        node* cur = head;
        int pos = 1;

        while (cur != NULL) {
            if (cur->data == val) {
                cout << "found at position " << pos << endl;
                return;
            }
            cur = cur->next;
            pos++;
        }

        cout << "not found" << endl;
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

    void show() {
        node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list l;
    int ch, val, pos;

    do {
        cout << "\n1 insert\n2 delete\n3 search\n4 count\n5 show\n0 exit\n";
        cout << "enter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "enter value and position: ";
            cin >> val >> pos;
            l.insert(val, pos);
        }
        else if (ch == 2) {
            cout << "enter position: ";
            cin >> pos;
            l.del(pos);
        }
        else if (ch == 3) {
            cout << "enter value: ";
            cin >> val;
            l.search(val);
        }
        else if (ch == 4) {
            cout << "total nodes: " << l.count() << endl;
        }
        else if (ch == 5) {
            l.show();
        }

    } while (ch != 0);

    return 0;
}