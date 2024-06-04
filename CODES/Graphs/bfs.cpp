// Writing is IMP, it's complex
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        
        vector<int> ans;
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty())
        {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for (auto it : adj[x])
            {
                if (!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};



// BROOO!!!
//   GOT SOMETHING!!!
//     HOW THESE PLATFORMS WORK!!!
//       OOPS!!!

---------------------------------------xx---------------------------------------------------

//{ Driver Code Starts.
// int main() {
//     int tc;
//     cin >> tc;
//     while (tc--) {
//         int V, E;
//         cin >> V >>

//             E;

//         vector<int> adj[V];

//         for (int i = 0; i < E; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             // 		adj[v].push_back(u);
//         }
//         // string s1;
//         // cin>>s1;
//         Solution obj;
//         vector<int> ans = obj.bfsOfGraph(V, adj);
//         for (int i = 0; i < ans.size(); i++) {
//             cout << ans[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// } Driver Code Ends
