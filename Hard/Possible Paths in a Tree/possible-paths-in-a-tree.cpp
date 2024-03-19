//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int ans;
    vector<int> parent;
    vector<int> size;
	public:
	 vector<int> maximumWeight(int n, vector<vector<int>>& edges, int q, vector<int>& queries) {
        ans = 0;
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        vector<int> res;
        map<int, int> mp; // asc sorted

        // Sorting the edges based on their weights in ascending order.
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        for (int i = 0; i < n - 1; i++) {
            // (k,v) - value is the number of path within which max weight <= k
            mp[edges[i][2]] = Union(edges[i][0], edges[i][1]);
        }

        for (int query : queries) {
            int maxWeight = 0;
            for (auto& entry : mp) {
                if (entry.first <= query)
                    maxWeight = entry.second;
                else
                    break;
            }
            res.push_back(maxWeight);
        }
        return res;
    }

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]); // path compression
    }

    int Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // Union by rank - bigger rank always become parent to avoid chaining.
        if (size[rootA] < size[rootB]) {
            ans += size[rootA] * size[rootB]; // only change
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        } else if (size[rootA] > size[rootB]) {
            ans += size[rootA] * size[rootB];
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            ans += size[rootA] * size[rootB];
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends