class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumofodd=0;
        int sumofeven=0;
         int i=1;
         int j=2;
         int countofodd=0;
         int countofeven=0;
         while(countofodd<n){
            sumofodd+=i;
            countofodd++;
            i+=2;

         }

         while(countofeven<n){
            sumofeven+=j;
            countofeven++;
            j+=2;
         }
         return __gcd(sumofeven,sumofodd);
    }
};