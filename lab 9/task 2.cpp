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
#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int songid;
    string songname;
    float duration;

    node* next;
    node* prev;

    node(int id, string name, float dur) {
        songid = id;
        songname = name;
        duration = dur;
        next = NULL;
        prev = NULL;
    }
};

class playlistmanager {
private:
    node* head;
    node* tail;
    node* current;

public:
    playlistmanager() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addsong(int id, string name, float dur) {
        node* newnode = new node(id, name, dur);

        if (head == NULL) {
            head = tail = current = newnode;
        }
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        cout << "song added: " << name << endl;
    }

    void deletesong(string name) {
        if (head == NULL) {
            cout << "playlist is empty." << endl;
            return;
        }

        node* temp = head;

        while (temp != NULL && temp->songname != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "song not found." << endl;
            return;
        }

        if (temp == head) {
            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            }
        }
        else {
            temp->prev->next = temp->next;
        }

        if (temp == tail) {
            tail = temp->prev;

            if (tail != NULL) {
                tail->next = NULL;
            }
        }
        else if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        if (current == temp) {
            current = head;
        }

        cout << "song deleted: " << temp->songname << endl;

        delete temp;
    }

    void playnext() {
        if (current == NULL) {
            cout << "playlist is empty." << endl;
            return;
        }

        if (current->next != NULL) {
            current = current->next;
            cout << "now playing: " << current->songname << endl;
        }
        else {
            cout << "this is the last song." << endl;
        }
    }

    void playprevious() {
        if (current == NULL) {
            cout << "playlist is empty." << endl;
            return;
        }

        if (current->prev != NULL) {
            current = current->prev;
            cout << "now playing: " << current->songname << endl;
        }
        else {
            cout << "this is the first song." << endl;
        }
    }

    void reverseplaylist() {
        if (head == NULL) {
            cout << "playlist is empty." << endl;
            return;
        }

        node* temp = NULL;
        node* curr = head;

        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        current = head;

        cout << "playlist reversed successfully." << endl;
    }

    void displayplaylist() {
        if (head == NULL) {
            cout << "playlist is empty." << endl;
            return;
        }

        node* temp = head;

        cout << endl;
        cout << "playlist songs:" << endl;

        while (temp != NULL) {
            cout << "id: " << temp->songid << endl;
            cout << "name: " << temp->songname << endl;
            cout << "duration: " << temp->duration << " mins" << endl;
            cout << "------------------------" << endl;

            temp = temp->next;
        }
    }
};

int main() {
    playlistmanager p;

    p.addsong(1, "shape of you", 4.2);
    p.addsong(2, "believer", 3.8);
    p.addsong(3, "perfect", 4.5);

    p.displayplaylist();

    cout << endl;
    cout << "playing next songs:" << endl;

    p.playnext();
    p.playnext();

    cout << endl;
    cout << "playing previous song:" << endl;

    p.playprevious();

    cout << endl;
    p.deletesong("believer");

    p.displayplaylist();

    cout << endl;
    cout << "reversing playlist..." << endl;

    p.reverseplaylist();

    p.displayplaylist();

    return 0;
}
    dll.displayforward();
    dll.displayreverse();

    return 0;
}