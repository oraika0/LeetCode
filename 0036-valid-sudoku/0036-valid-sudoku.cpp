class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> column(9,vector<bool>(9,false));
        vector<vector<bool>> square(9,vector<bool>(9,false));
        for (int i = 0; i < 9;i++){
            for (int j = 0; j < 9; j++){
            int squarePos = (i/3)*3 + j/3; // floor i to 3's multiple
            int val = board[i][j]-'1';
                if (board[i][j] != '.'){
                    if(row[i][val] == true ||
                        column[j][val] == true ||
                        square[squarePos][val] == true){
                        return false;
                    } 
                    else{
                        row[i][val] = true;
                        column[j][val] = true;
                        square[squarePos][val] = true;
                    }
                } 
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<bool> table(9,false);
        
//         // row checking
//         for(auto row : board){
//             fill (table.begin(),table.end(),false);
//             for (auto element : row){
//                 if (element != '.'){
//                     if(table[element-'1'] == false){
//                         table[element-'1'] = true;
//                     } 
//                     else{
//                         return false;
//                     }
//                 }
//             }
//         }

//         // column checking
//         for (int i = 0; i < 9;i++){
//             fill (table.begin(),table.end(),false);
//             for (int j = 0; j < 9; j++){
//                 if (board[j][i] != '.'){
//                     if(table[board[j][i]-'1'] == false){
//                         table[board[j][i]-'1'] = true;
//                     } 
//                     else{
//                         return false;
//                     }
//                 } 
//             }
//         }

//         // square checking
//         for (int i = 0;i < 9;i+=3){
//             for (int j = 0; j < 9; j+=3){
//                 cout << endl;
//                 fill (table.begin(),table.end(),false);
//                 for (int in_i = 0; in_i < 3; in_i++){
//                     for (int in_j = 0; in_j < 3; in_j++){
//                         if (board[i+in_i][j+in_j] != '.'){
//                             if(table[board[i+in_i][j+in_j]-'1'] == false){
//                                 table[board[i+in_i][j+in_j]-'1'] = true;
//                             } 
//                             else{
//                                 return false;
//                             }
//                         }       
//                     }    
//                 }
//             }
//         }



//         return true;
//     }
// };