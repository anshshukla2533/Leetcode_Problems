class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int it:stones){
            pq.push(it);
        }
        int ans=0;
        while(pq.size()>1){
            int top=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            if(top==s)continue;
            else{
                pq.push(top-s);
            }
    

        }
        return pq.size()==1?pq.top():0;
    }
};