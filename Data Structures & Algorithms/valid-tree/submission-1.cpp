class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());

        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);

        int curr;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            curr = q.front(); q.pop();
            for(int nei: adj[curr]){
                if(!visited[nei]){
                    parent[nei] = curr;
                    visited[nei] = true;
                    q.push(nei);
                } else {
                    if(parent[curr] != nei ) {
                        return false;
                    }
                }
            }
        }

        for(bool val: visited){
            if(!val){
                return false;
            }
        }

        return true;
    }
};
