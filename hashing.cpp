/*#include <iostream>
using namespace std;
#define SIZE 10

using namespace std;

template <class T>
void Print(T& vec, int n, string s) {
    cout << s << ": [";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Function to calculate hash value for a key
int Hash(int key) {
    return key % SIZE;
}

// Linear probing to resolve collisions
int LinearProbe(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != 0) {
        i++;
    }
    return (idx + i) % SIZE;
}

// Function to insert a key into the hash table
void Insert(int H[], int key) {
    int idx = Hash(key);

    // If the slot is occupied, use linear probing to find the next available slot
    if (H[idx] != 0) {
        idx = LinearProbe(H, key);
    }

    H[idx] = key;
}

// Function to search for a key in the hash table
int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;

    // Linear probing to find the key or an empty slot
    while (H[(idx + i) % SIZE] != key) {
        i++;

        // If an empty slot is encountered, the key is not present
        if (H[(idx + i) % SIZE] == 0) {
            return -1;
        }
    }

    // Return the index where the key was found
    return (idx + i) % SIZE;
}

int main() {
    // Array of elements to be inserted into the hash table
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, " A");

    // Hash Table initialization
    int HT[SIZE] = {0};

    // Insert elements into the hash table
    for (int i = 0; i < n; i++) {
        Insert(HT, A[i]);
    }

    // Print the resulting hash table
    Print(HT, SIZE, "HT");

    // Search for keys in the hash table and print the result
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;

    index = Search(HT, 35);
    cout << "key found at: " << index << endl;

    return 0;
}
*/
#include <iostream>
#define SIZE 10

using namespace std;

template <class T>
void Print(T& vec, int n, string s) {
    cout << s << ": [";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Hash function to calculate the index for a key
int Hash(int key) {
    return key % SIZE;
}

// Quadratic probing to resolve collisions
int QuadraticProbe(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i * i) % SIZE] != 0) {
        i++;
    }
    return (idx + i * i) % SIZE;
}

// Function to insert a key into the hash table using quadratic probing
void Insert(int H[], int key) {
    int idx = Hash(key);

    // If the slot is occupied, use quadratic probing to find the next available slot
    if (H[idx] != 0) {
        idx = QuadraticProbe(H, key);
    }

    H[idx] = key;
}

// Function to search for a key in the hash table using quadratic probing
int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;

    // Quadratic probing to find the key or an empty slot
    while (H[(idx + i * i) % SIZE] != key) {
        i++;

        // If an empty slot is encountered, the key is not present
        if (H[(idx + i * i) % SIZE] == 0) {
            return -1;
        }
    }

    // Return the index where the key was found
    return (idx + i * i) % SIZE;
}

int main() {
    // Array of elements to be inserted into the hash table
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, " A");

    // Hash Table initialization
    int HT[SIZE] = {0};

    // Insert elements into the hash table using quadratic probing
    for (int i = 0; i < n; i++) {
        Insert(HT, A[i]);
    }

    // Print the resulting hash table
    Print(HT, SIZE, "HT");

    // Search for keys in the hash table and print the result
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;

    index = Search(HT, 35);
    cout << "key found at: " << index << endl;

    return 0;
}
