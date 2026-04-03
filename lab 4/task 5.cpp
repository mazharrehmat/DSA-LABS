#include <iostream>
using namespace std;

class Queue {
    string *arr;
    int frontIndex, rearIndex, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string val) {
        if (size == capacity) {
            cout << "Queue full" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        size++;
        cout << "Added: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No jobs" << endl;
            return;
        }
        cout << "Printing: " << arr[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    void front() {
        if (isEmpty()) {
            cout << "No jobs" << endl;
            return;
        }
        cout << "Next: " << arr[frontIndex] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending jobs" << endl;
            return;
        }
        int i = frontIndex;
        for (int c = 0; c < size; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter capacity: ";
    cin >> n;

    Queue q(n);

    int choice;
    string name;

    do {
        cout << endl;
        cout << "1 Add Job" << endl;
        cout << "2 Print Job" << endl;
        cout << "3 Next Job" << endl;
        cout << "4 Display" << endl;
        cout << "0 Exit" << endl;

        cin >> choice;

        if (choice == 1) {
            cout << "Enter document name: ";
            cin >> name;
            q.enqueue(name);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.front();
        }
        else if (choice == 4) {
            q.display();
        }

    } while (choice != 0);

    return 0;
}