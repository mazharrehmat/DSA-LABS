#include <iostream>
using namespace std;

class Package {
public:
    int id;
    string address;
    int startTime, endTime;
};

class Queue {
    Package *arr;
    int frontIndex, rearIndex, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new Package[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(Package p) {
        if (size == capacity) {
            cout << "Queue full" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = p;
        size++;
        cout << "Package added: " << p.id << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No packages" << endl;
            return;
        }
        cout << "Delivered package: " << arr[frontIndex].id << endl;
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    void front() {
        if (isEmpty()) {
            cout << "No packages" << endl;
            return;
        }
        Package p = arr[frontIndex];
        cout << "Next Package -> ID: " << p.id << " Address: " << p.address 
             << " Time: " << p.startTime << "-" << p.endTime << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending packages" << endl;
            return;
        }
        int i = frontIndex;
        for (int c = 0; c < size; c++) {
            Package p = arr[i];
            cout << "ID: " << p.id << " Address: " << p.address 
                 << " Time: " << p.startTime << "-" << p.endTime << endl;
            i = (i + 1) % capacity;
        }
    }

    void timeToDeliver(int currentTime) {
        if (isEmpty()) {
            cout << "No packages" << endl;
            return;
        }

        Package p = arr[frontIndex];

        if (currentTime >= p.startTime && currentTime <= p.endTime) {
            cout << "On time delivery for package: " << p.id << endl;
            dequeue();
        }
        else {
            cout << "Package expired: " << p.id << endl;
            dequeue();
        }
    }
};

int main() {
    int n;
    cout << "Enter capacity: ";
    cin >> n;

    Queue q(n);

    int choice;

    do {
        cout << endl;
        cout << "1 Add Package" << endl;
        cout << "2 Deliver Package" << endl;
        cout << "3 Check Front" << endl;
        cout << "4 Display" << endl;
        cout << "5 Check Time" << endl;
        cout << "0 Exit" << endl;

        cin >> choice;

        if (choice == 1) {
            Package p;
            cout << "Enter ID: ";
            cin >> p.id;
            cout << "Enter address: ";
            cin >> p.address;
            cout << "Enter start time: ";
            cin >> p.startTime;
            cout << "Enter end time: ";
            cin >> p.endTime;

            q.enqueue(p);
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
        else if (choice == 5) {
            int t;
            cout << "Enter current time: ";
            cin >> t;
            q.timeToDeliver(t);
        }

    } while (choice != 0);

    return 0;
}