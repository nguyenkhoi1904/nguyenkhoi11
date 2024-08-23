#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; // Số đỉnh

    // Danh sách kề của đồ thị
    list<int> *adj;

    // Đệ quy của thuật toán DFS
    void DFSUtil(int v, bool visited[]);

public:
    // Constructor
    Graph(int V);

    // Thêm một cạnh vào đồ thị
    void addEdge(int v, int w);

    // Gọi thuật toán DFS,
    // duyệt theo chiều sâu từ đỉnh s
    void DFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Thêm w vào danh sách kề của v
}

void Graph::DFSUtil(int v, bool visited[]) {
    // Đánh dấu đỉnh hiện tại là đã xét
    visited[v] = true;
    cout << v << " ";

    // Lặp qua tất cả các đỉnh kề của đỉnh hiện tại
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int s) {
    // Tạo một mảng đánh dấu các đỉnh đã xét
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Gọi hàm đệ quy để in các đỉnh đến được từ đỉnh s
    DFSUtil(s, visited);
}

int main() {
    // Khởi tạo đồ thị với 4 đỉnh
    Graph g(4);

    // Thêm các cạnh vào đồ thị
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Duyệt theo chiều sâu (DFS) từ đỉnh 2: ";
    g.DFS(2);

    return 0;
}