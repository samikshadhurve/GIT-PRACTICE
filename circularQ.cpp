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
        if (front == -1 && rear == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int isfull() {
        if (((rear + 1) % maxsize) == front) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void enQ(int val) {
        if (isempty()) {
            front = rear = 0;
        }
        else if (isfull()) {
            cout << "full Queue!" << endl;
        }
        else {
            rear = (rear + 1) % maxsize;
            arr[rear] = val;
        }
    }
    void deQ() {
        if (isempty()) {
            cout << "is empty!" << endl;
        }
        else if (rear == front) {
            rear = front = -1;
        }
        else {
            cout << "deleted:" << arr[front] << endl;
            front = (front + 1) % maxsize;
        }
    }
    void display() {
        if (isempty()) {
            cout << "empty!" << endl;
        }
        else {
            int i = front;
            cout << "Q is: ";
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
        cout << "element:" << endl;
        cin >> m;
        c.enQ(m);
    }
    c.display();
    c.deQ();
    c.display();
    return 0;
}
/*
bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1)
            || front == rear + 1);
}
 
// Checks whether Deque is empty or not.
bool Deque::isEmpty() { return (front == -1); }
 
// Inserts an element at front
void Deque::insertfront(int key)
{
    // check whether Deque if  full or not
    if (isFull()) {
        cout << "Overflow\n" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1;
 
    else // decrement front end by '1'
        front = front - 1;
 
    // insert current element into Deque
    arr[front] = key;
}
 
// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
    if (isFull()) {
        cout << " Overflow\n " << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size - 1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear + 1;
 
    // insert current element into Deque
    arr[rear] = key;
}
 
// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << "Queue Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size - 1)
        front = 0;
 
    else // increment front by '1' to remove current
        // front value from Deque
        front = front + 1;
}
 
// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}
 
// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return -1;
    }
    return arr[front];
}
 
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if (isEmpty() || rear < 0) {
        cout << " Underflow\n" << endl;
        return -1;
    }
    return arr[rear];
}
 /*
#include<iostream>
using namespace std;

class PriorityQueue {
private:
    int maxsize;
    int front;
    int rear;
    int arr[6];
    int priorities[6];  // Array to store priorities

public:
    PriorityQueue() {
        maxsize = 6;
        front = -1;
        rear = -1;
        for (int i = 0; i < 6; i++) {
            priorities[i] = 0;  // Initialize priorities to 0
        }
    }

    int isempty() {
        if (front == -1 && rear == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int isfull() {
        if (rear == maxsize - 1) {
            return 1;
        }
        else {
            return 0;
        }
    }

    void enQ(int val, int priority) {
        if (isfull()) {
            cout << "Full Queue!" << endl;
        }
        else {
            // Find the correct position based on priority
            int insertPosition = rear;
            while (insertPosition >= 0 && priority > priorities[insertPosition]) {
                arr[insertPosition + 1] = arr[insertPosition];
                priorities[insertPosition + 1] = priorities[insertPosition];
                insertPosition--;
            }

            // Insert the new element with its priority
            arr[insertPosition + 1] = val;
            priorities[insertPosition + 1] = priority;
            rear++;
        }
    }

    void deQ() {
        if (isempty()) {
            cout << "Empty!" << endl;
        }
        else {
            cout << "Deleted: " << arr[front] << " with priority " << priorities[front] << endl;
            for (int i = 0; i < rear; i++) {
                arr[i] = arr[i + 1];
                priorities[i] = priorities[i + 1];
            }
            rear--;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Empty!" << endl;
        }
        else {
            cout << "Priority Queue:" << endl;
            for (int i = 0; i <= rear; i++) {
                cout << "Value: " << arr[i] << " Priority: " << priorities[i] << endl;
            }
        }
    }
};

int main() {
    PriorityQueue pq;
    int n, m, priority;

    n = 6;
    for (int i = 0; i < n; i++) {
        cout << "Enter element and priority:" << endl;
        cin >> m >> priority;
        pq.enQ(m, priority);
    }

    pq.display();
    pq.deQ();
    pq.display();

    return 0;
}
*/