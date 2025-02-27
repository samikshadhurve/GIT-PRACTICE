#include <iostream>
using namespace std;

class tree {
    int a[10][10];
    int sp[10][10];
    int v;
    int min_cost;
    int infi;

public:
    tree() {
        infi = 999;
        min_cost = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = 0;
                sp[i][j] = 0;
            }
        }
    }

    void create() {
        char ch;
        cout << "Enter the number of vertices: ";
        cin >> v;
        do {
            int i, j;
            cout << "Enter edge:" << endl;
            cin >> i >> j;
            cout << "Enter the cost of an edge: ";
            cin >> a[i][j];
            a[j][i] = a[i][j]; // Undirected graph
            cout << "Want to add another edge? y for yes, n for no: ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }

    void display() {
        cout << "The adjacency matrix representation of the graph is:" << endl;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void spanning_tree() {
        cout << "Spanning tree for the given graph is:" << endl;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << sp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "Minimum cost is: " << min_cost << endl;
    }

    void prims() {
        int cost[10][10], dist[10], source[10], visited[10];
        int mindist, u, v;

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (a[i][j] == 0) {
                    cost[i][j] = infi;
                } else {
                    cost[i][j] = a[i][j];
                }
            }
        }

        for (int i = 0; i < v; i++) {
            dist[i] = cost[0][i];
            source[i] = 0;
            visited[i] = 0;
        }
        visited[0] = 1;

        int edges = v - 1;
        while (edges > 0) {
            mindist = infi;
            for (int i = 0; i < v; i++) {
                if (visited[i] == 0 && dist[i] < mindist) {
                    mindist = dist[i];
                    u = i;
                }
            }

            v = source[u];
            sp[u][v] = sp[v][u] = dist[u];
            edges--;
            visited[u] = 1;

            for (int i = 0; i < v; i++) {
                if (visited[i] == 0 && cost[i][u] < dist[i]) {
                    dist[i] = cost[i][u];
                    source[i] = u;
                }
            }
            min_cost += cost[u][v];
        }

        // Display the minimum spanning tree and its cost
        spanning_tree();
    }
};

int main() {
    tree t1;
    int choice;
    do {
        cout << "\n----Menu----" << endl;
        cout << "1. Create a graph" << endl;
        cout << "2. Display the graph" << endl;
        cout << "3. Find Minimum Spanning Tree (Prim's)" << endl;
        cout << "4. Display Minimum Spanning Tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t1.create();
                break;
            case 2:
                t1.display();
                break;
            case 3:
                t1.prims();
                break;
            case 4:
                t1.spanning_tree();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.";
                break;
        }
    } while (choice != 5);

    return 0;
}
