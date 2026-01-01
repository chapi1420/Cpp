#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX];   
int visited[MAX];      
int n;                

// ---------- DFS (Recursive) ----------
void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// ---------- BFS (Using Array Queue) ----------
void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = -1;

    // reset visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // enqueue start node
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// ---------- MAIN ----------
int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS starting from vertex 0: ";
    DFS(0);

    cout << "\nBFS starting from vertex 0: ";
    BFS(0);

    return 0;
}
