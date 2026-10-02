class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int a=source[0];
        int b=source[1];
        int x=target[0];
        int y=target[1];
        if(a==x && b==y)return 0;
        else if((a == x) || (b == y) || abs(a - x) == abs(b - y)) return 1;
        return 2; 
    }
};