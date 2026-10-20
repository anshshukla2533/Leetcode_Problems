class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        
        const auto& vec = m[key];
        int l = 0, r = vec.size() - 1;
        string res = "";
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */