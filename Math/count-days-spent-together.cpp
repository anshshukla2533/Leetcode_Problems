class Solution {
public:
    int numberofdays(string s){
        vector<int>months={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        int mn=stoi(s.substr(0,2));
        int st=stoi(s.substr(3,2));
        int t=st;
        for(int i=0;i<mn-1;i++){
            t+=months[i];
        }
        return t;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int as=numberofdays(arriveAlice);
        int ae=numberofdays(leaveAlice);
        int bs=numberofdays(arriveBob);
        int be=numberofdays(leaveBob);
        return max(0,min(ae,be)-max(as,bs)+1);
    }
};