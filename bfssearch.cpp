#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int v;
    int **arr;
    int *visited;

public:
    Graph() {
        v = 0;
        arr = nullptr;
        visited = nullptr;
    }

    void create() {
        cout << "Enter the number of vertices: ";
        cin >> v;

        arr = new int*[v];
        for (int i = 0; i < v; ++i) {
            arr[i] = new int[v];
            for (int j = 0; j < v; ++j) {
                arr[i][j] = 0;
            }
        }

        visited = new int[v]();

        char ch;
        do {
            int v1, v2;
            cout << "Enter edge vertices (v1 v2): ";
            cin >> v1 >> v2;
            if (v1 >= 0 && v1 < v && v2 >= 0 && v2 < v) {
                arr[v1][v2] = 1;
                arr[v2][v1] = 1;
            } else {
                cout << "Invalid vertices, please enter again." << endl;
            }
            cout << "Enter more edges? (y/n): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }

    void bfs() {
        if (v == 0) {
            cout << "Graph not created yet." << endl;
            return;
        }

        queue<int> Q;
        
        int s;
        cout << "Enter the start vertex for BFS: ";
        cin >> s;
        Q.push(s);
        visited[s] = 1;

        cout << "BFS Traversal: ";
        while (!Q.empty()) {
            int current = Q.front();
            Q.pop();
            cout << current << " ";

            for (int i = 0; i < v; ++i) {
                if (arr[current][i] == 1 && visited[i] == 0) {
                    Q.push(i);
                    visited[i] = 1;
                }
            }
        }
        cout << endl;
    }

    void dfsUtil(int k) {
        stack<int> s;
        s.push(k);
        visited[k] = 1;

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            cout << current << " ";

            for (int i = 0; i < v; ++i) {
                if (arr[current][i] == 1 && visited[i] == 0) {
                    s.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    void dfs() {
        if (v == 0) {
            cout << "Graph not created yet!" << endl;
            return;
        }

        for (int i = 0; i < v; ++i) {
            visited[i] = 0;
        }
        
        int k;
        cout << "Enter the start vertex for DFS: ";
        cin >> k;
        cout << "DFS Traversal: ";
        dfsUtil(k);
        cout << endl;
    }

    void initialize_visited() {
        for (int i = 0; i < v; ++i) {
            visited[i] = 0;
        }
    }
    void delete_vertex(){
        int s;
        cout<<"Enter the vertex to del:";
        cin>>s;
        for(int i=0;i<v;i++){
            arr[s][i]=0;
            arr[i][s]=0;
        }
        cout<<"vertex s deleted successfully";
    }

    ~Graph() {
        for (int i = 0; i < v; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] visited;
    }
};

int main() {
    Graph G;
    int choice;

    do {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Create Graph" << endl;
        cout << "2. BFS Traversal" << endl;
        cout << "3. DFS Traversal" << endl;
        cout<<"4.delete"<<endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                G.create();
                break;
            case 2:
                G.bfs();
                break;
            case 3:
                G.initialize_visited();
                G.dfs();
                break;
            case 4:
                 G.delete_vertex();
                 break;    
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option (1-4)." << endl;
        }
    } while (choice != 4);

    return 0;
}
