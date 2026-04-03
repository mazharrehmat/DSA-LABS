#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int frontIndex, rearIndex, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int val) {
        if (size == capacity) return;
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return val;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    int getSize() {
        return size;
    }

    void display() {
        int i = frontIndex;
        for (int c = 0; c < size; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

void reverseK(Queue &q, int k) {
    if (k <= 1 || q.isEmpty()) return;

    int n = q.getSize();
    if (k > n) k = n;

    int *st = new int[k];
    int top = -1;

    for (int i = 0; i < k; i++)
        st[++top] = q.dequeue();

    while (top != -1)
        q.enqueue(st[top--]);

    for (int i = 0; i < n - k; i++)
        q.enqueue(q.dequeue());

    delete[] st;
}

void inputQueue(Queue &q, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }
}

int main() {
    int n, k;

    cout << "Enter size: ";
    cin >> n;

    Queue q(n);

    cout << "Enter elements: ";
    inputQueue(q, n);

    cout << "Enter k: ";
    cin >> k;

    reverseK(q, k);

    cout << "Result: ";
    q.display();

    return 0;
}