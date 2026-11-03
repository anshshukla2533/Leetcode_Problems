class MedianFinder {
public:
    std::priority_queue<int> maxhp; 
    std::priority_queue<int, vector<int>, greater<int>> minhp; 
    MedianFinder() {}

    void addNum(int num) {
        maxhp.push(num);

       
        if (!maxhp.empty() && !minhp.empty() && maxhp.top() > minhp.top()) {
            minhp.push(maxhp.top());
            maxhp.pop();
        }
        if (maxhp.size() > minhp.size() + 1) {
            minhp.push(maxhp.top());
            maxhp.pop();
        } else if (minhp.size() > maxhp.size()) {
            maxhp.push(minhp.top());
            minhp.pop();
        }
    }

    double findMedian() {
        if (maxhp.size() > minhp.size()) {
            return (double)maxhp.top();
        }
        return (double)(maxhp.top() + minhp.top()) / 2.0;
    }
};