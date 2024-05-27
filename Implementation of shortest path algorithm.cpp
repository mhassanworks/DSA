#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// Define an Edge as a pair of destination node and weight
using Edge = pair<int, int>;
// Define a Graph as a vector of vectors of Edges
using Graph = vector<vector<Edge>>;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(const Graph &graph, int start) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap priority queue

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_distance > dist[u]) continue;

        for (const Edge &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    Graph graph(n);
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // If the graph is undirected
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<int> distances = dijkstra(graph, start);

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < n; ++i) {
        if (distances[i] == numeric_limits<int>::max()) {
            cout << "Node " << i << ": unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << distances[i] << endl;
        }
    }

    return 0;
}
