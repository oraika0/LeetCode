class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> table(9,false);
        
        // row checking
        for(auto row : board){
            fill (table.begin(),table.end(),false);
            for (auto element : row){
                if (element != '.'){
                    if(table[element-'1'] == false){
                        table[element-'1'] = true;
                    } 
                    else{
                        return false;
                    }
                }
            }
        }

        // column checking
        for (int i = 0; i < 9;i++){
            fill (table.begin(),table.end(),false);
            for (int j = 0; j < 9; j++){
                if (board[j][i] != '.'){
                    if(table[board[j][i]-'1'] == false){
                        table[board[j][i]-'1'] = true;
                    } 
                    else{
                        return false;
                    }
                } 
            }
        }

        // square checking
        for (int i = 0;i < 9;i+=3){
            for (int j = 0; j < 9; j+=3){
                cout << endl;
                fill (table.begin(),table.end(),false);
                for (int in_i = 0; in_i < 3; in_i++){
                    for (int in_j = 0; in_j < 3; in_j++){
                        if (board[i+in_i][j+in_j] != '.'){
                            if(table[board[i+in_i][j+in_j]-'1'] == false){
                                table[board[i+in_i][j+in_j]-'1'] = true;
                            } 
                            else{
                                return false;
                            }
                        }       
                    }    
                }
            }
        }



        return true;
    }
};