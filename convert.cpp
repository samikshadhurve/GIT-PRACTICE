#include<iostream>
using namespace std;

class circularQ {
private:
    int maxsize;
    int front;
    int rear;
    int arr[6];
public:
    circularQ() {
        maxsize = 6;
        front = -1;
        rear = -1;
    }

    int isempty() {
        return (front == -1 && rear == -1);
    }

    int isfull() {
        return ((rear + 1) % maxsize == front);
    }

    void enQ(int val) {
        if (isfull()) {
            cout << "Full Queue!" << endl;
        }
        else {
            if (isempty()) {
                front = 0;
            }
            rear = (rear + 1) % maxsize;
            arr[rear] = val;
        }
    }

    void deQ() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Deleted: " << arr[front] << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % maxsize;
            }
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
        }
        else {
            int i = front;
            cout << "Queue is: ";
            do {
                cout << arr[i] << " ";
                i = (i + 1) % maxsize;
            } while (i != (rear + 1) % maxsize);
            cout << endl;
        }
    }
};

int main() {
    circularQ c;
    int n, m;
    n = 6;
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> m;
        c.enQ(m);
    }
    c.display();
    c.deQ();
    c.display();

    return 0;
}
