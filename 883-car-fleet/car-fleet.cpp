class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<double, double>> cars;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        sort(cars.begin(), cars.end());
        
        int fleets = 0;
        double maxTime = 0.0;
        
        for (int i = n - 1; i >= 0; i--) {
            double currentTime = cars[i].second;
            
            if (currentTime > maxTime) {
                fleets++;
                maxTime = currentTime;
            }
        }
        
        return fleets;
    }
};