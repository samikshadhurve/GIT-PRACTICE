#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    static const int N = 100;
    int v;
    int graph[N][N];

public:
    Graph() {
        v = 0;
      
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                graph[i][j] = 0;
            }
        }
    }

    void createGraph() {
        cout << "Enter the number of vertices: " << endl;
        cin >> v;
        char ch;
        do {
            cout << "Do you want to add an edge? (Y for yes, N for no): ";
            cin >> ch;

            if (ch == 'Y' || ch == 'y') {
                int v1, v2;
                cout << "Enter the edge as a pair of vertices: ";
                cin >> v1 >> v2;

                if (v1 >= v || v2 >= v || v1 < 0 || v2 < 0) {
                    cout << "Invalid vertex! Vertex number should be less than " << v << endl;
                } else {
                    graph[v1][v2] = 1;
                    graph[v2][v1] = 1;
                }
            }
        } while (ch == 'Y' || ch == 'y');
    }

    void bfs_search() {
        queue<int> Q;
        int s;
        int vis[N] = {0};
        for (int i = 0; i < v; i++) {
            vis[i] = 0;
        }
        cout << "Enter the start vertex: ";
        cin >> s;
        vis[s] = 1;
        Q.push(s);
        while (!Q.empty()) {
            int current = Q.front();
            Q.pop();
            cout << current << " ";

            for (int i = 0; i < v; i++) {
                if (graph[current][i] == 1 && vis[i] == 0) {
                    Q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    void dfs_search() {
        stack<int> s;
        int k;
        int vis[N] = {0};
        cout << "Enter the starting vertex: ";
        cin >> k;
        s.push(k);
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (vis[current] == 0) {
                cout << current << " ";
                vis[current] = 1;
            }

            for (int i = v - 1; i >= 0; i--) {
                if (graph[current][i] == 1 && vis[i] == 0) {
                    s.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Graph\n";
        cout << "2. Perform BFS\n";
        cout << "3. Perform DFS\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.createGraph();
                break;
            case 2:
                cout << "BFS Traversal: ";
                g.bfs_search();
                cout << endl;
                break;
            case 3:
                cout << "DFS Traversal: ";
                g.dfs_search();
                cout << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
