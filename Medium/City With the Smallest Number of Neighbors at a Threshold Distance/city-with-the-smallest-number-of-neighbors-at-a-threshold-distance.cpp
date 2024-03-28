//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Node {
public:
    int v, w;
    Node(int v, int w) : v(v), w(w) {}
};

class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<Node>> adj(n);

        // Constructing adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]); // Considering bidirectional edges
        }

        int minCities = numeric_limits<int>::max();
        int result = -1;

        // Running Dijkstra's for each city
        for (int i = 0; i < n; i++) {
            vector<int> dis(n, numeric_limits<int>::max());
            dijkstra(adj, i, dis);

            int reachableCities = 0;
            for (int j = 0; j < n; j++) {
                if (dis[j] <= distanceThreshold) {
                    reachableCities++;
                }
            }

            // Tracking minimum
            if (reachableCities <= minCities) {
                minCities = reachableCities;
                result = i;
            }
        }

        return result;
    }

private:
    // Dijkstra's Algorithm
    void dijkstra(const vector<vector<Node>>& adj, int start, vector<int>& dis) {
        auto cmp = [](const Node& left, const Node& right) { return left.w > right.w; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        dis[start] = 0;
        pq.emplace(start, 0);

        while (!pq.empty()) {
            Node currNode = pq.top(); pq.pop();
            for (const Node& nei : adj[currNode.v]) {
                if (dis[nei.v] > dis[currNode.v] + nei.w) {
                    dis[nei.v] = dis[currNode.v] + nei.w;
                    pq.emplace(nei.v, dis[nei.v]);
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends