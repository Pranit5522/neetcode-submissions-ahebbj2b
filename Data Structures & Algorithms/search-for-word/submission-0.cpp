class Solution {
public:
    bool calc(
        vector<vector<char>>& board,
        int i,
        int j,
        string& word,
        int k, 
        unordered_set<int>& visited
    ) {
        if(k==word.size()) return true;
        if(
            i<0 
            || j<0 
            || i>=board.size() 
            || j>=board[0].size() 
            || visited.find(board[0].size() * i + j) != visited.end() 
            || word[k] != board[i][j]
        )
            return false;

        visited.insert(board[0].size()*i + j);
        bool res = (
            calc(board, i+1, j, word, k+1, visited)
            || calc(board, i-1, j, word, k+1, visited)
            || calc(board, i, j+1, word, k+1, visited)
            || calc(board, i, j-1, word, k+1, visited)
        );
        visited.erase(board[0].size()*i + j);

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_set<int> visited;

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(calc(board, i, j, word, 0, visited)){
                    return true;
                }
            }
        }

        return false;
    }
};
