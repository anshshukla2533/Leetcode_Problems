class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // Phase 1: Finding the intersection point in the cycle
        int slow = arr[0];
        int fast = arr[0];
        
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        
        // Phase 2: Finding the entrance to the cycle (the duplicate number)
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        
        return slow;
    }
};