class Solution {
public:
    void updateGrid(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != '1'){
            return;
        }

        grid[i][j] = '0';
        updateGrid(grid, i+1, j);
        updateGrid(grid, i-1, j);
        updateGrid(grid, i, j+1);
        updateGrid(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    updateGrid(grid, i, j);
                }
            }
        }

        return count;
    }
};
