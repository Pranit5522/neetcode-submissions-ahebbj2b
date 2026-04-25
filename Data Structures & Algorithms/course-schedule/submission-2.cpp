class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int curr, vector<bool> &visited, vector<bool> &dfs_visited) {
        visited[curr] = true;
        dfs_visited[curr] = true;
        
        for(int nei: adj[curr]) {
            if(dfs_visited[nei]){
                return true;
            }
            if(!visited[nei]){
                if (dfs(adj, nei, visited, dfs_visited)){
                    return true;
                }
            }
        }

        dfs_visited[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto prerequisite: prerequisites){
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<bool> visited(numCourses, false), dfs_visited(numCourses, false);
        bool isCyclic;

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                isCyclic = dfs(adj, i, visited, dfs_visited);
                if(isCyclic){
                    return false;
                }
            }
        }

        return true;
    }
};
