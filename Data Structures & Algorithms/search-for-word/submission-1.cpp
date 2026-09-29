class Solution {
public:
    vector<vector<char>> board;
    string word;
    int m;
    int n;
    bool solve(int i, int j, int k){
        if(k == word.length()){
            return true;
        }
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '\0';
        bool found = solve(i + 1, j , k + 1) ||
                     solve(i - 1, j , k + 1) ||
                     solve(i, j + 1, k + 1) ||
                     solve(i, j - 1, k + 1);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->m = board.size();
        this->n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (solve(i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
