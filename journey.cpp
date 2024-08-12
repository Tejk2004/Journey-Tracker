#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

const int INF = INT_MAX;

// Class to represent a weighted graph
class Graph {
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list (node, weight)

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // For undirected graph
    }

    vector<int> dijkstra(int src, vector<int>& prev) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                    prev[v] = u;
                }
            }
        }

        return dist;
    }

    void printShortestPath(int src, int dest) {
        vector<int> prev(V, -1); // To store the previous node in the path
        vector<int> dist = dijkstra(src, prev);

        if (dist[dest] == INF) {
            cout << "No path from " << src << " to " << dest << endl;
            return;
        }

        cout << "Shortest path from " << src << " to " << dest << " is " << dist[dest] << endl;

        // Reconstruct the path
        stack<int> path;
        for (int v = dest; v != -1; v = prev[v]) {
            path.push(v);
        }

        cout << "Stations (Path): ";
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
};

int main() {
    int V = 10; // Number of metro stations
    Graph g(V);

    // Add edges (station1, station2, distance)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(1, 2, 12);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 6, 8);
    g.addEdge(5, 6, 9);
    g.addEdge(6, 7, 10);
    g.addEdge(7, 8, 11);
    g.addEdge(8, 9, 12);
    g.addEdge(7, 9, 7);

    int src, dest;
    cout << "Enter the current station (0-9): ";
    cin >> src;
    cout << "Enter the destination station (0-9): ";
    cin >> dest;

    if (src < 0 || src >= V || dest < 0 || dest >= V) {
        cout << "Invalid station number!" << endl;
    } else {
        g.printShortestPath(src, dest);
    }

    return 0;
}
