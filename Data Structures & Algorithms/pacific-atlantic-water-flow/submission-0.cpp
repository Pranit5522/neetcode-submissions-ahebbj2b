class Solution {
public:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited, int& n, int& m){
        int i, j;
        pair<int, int> curr;
        while(!q.empty()){
            curr = q.front(); q.pop();
            i = curr.first; j = curr.second;

            if(i+1<n && !visited[i+1][j] && heights[i+1][j] >= heights[i][j]){ 
                q.push({i+1, j});
                visited[i+1][j] = true;
            }
            if(i-1>=0 && !visited[i-1][j] && heights[i-1][j] >= heights[i][j]){ 
                q.push({i-1, j});
                visited[i-1][j] = true;
            }
            if(j+1<m && !visited[i][j+1] && heights[i][j+1] >= heights[i][j]){ 
                q.push({i, j+1});
                visited[i][j+1] = true;
            }
            if(j-1>=0 && !visited[i][j-1] && heights[i][j-1] >= heights[i][j]){ 
                q.push({i, j-1});
                visited[i][j-1] = true;
            }    
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> pVisited(n, vector<bool>(m, false)), aVisited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            q.push({i, 0});
            pVisited[i][0] = true;
        }
        for(int i=1; i<m; i++){
            q.push({0, i});
            pVisited[0][i] = true;
        }
        bfs(heights, q, pVisited, n, m);

        for(int i=0; i<n; i++){
            q.push({i, m-1});
            aVisited[i][m-1] = true;
        }
        for(int i=0; i<m-1; i++){
            q.push({n-1, i});
            aVisited[n-1][i] = true;
        }
        bfs(heights, q, aVisited, n, m);

        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(aVisited[i][j] && pVisited[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
