class Solution {
public:
    // if all of the numbers will decline into single digit
    // 2 4 16 37 58 89 145 42 20 4
    // 3 9 81 65 61 37 58
    // 5 25 29 85 89
    // 6 36 45 41 17 50 25
    // 7 49 97 130 10 1
    // 8 64 52
    // 0 2 3 4 5 6 8 9 are not a happy numbers
    bool isHappy(int n) {
        while (n > 9){
            int tmp = 0;
            while (n > 0){
                int digit = n % 10;
                tmp += pow(digit,2);
                n /= 10;
            }
            n = tmp;
            cout << n << endl;
        }
        if (n == 1 || n == 7){
            return true;
        }        
        else {
            return false;
        }
    }
};