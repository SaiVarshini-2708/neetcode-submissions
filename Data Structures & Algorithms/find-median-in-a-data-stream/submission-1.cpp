class MedianFinder {
public:
    // Smaller half
    priority_queue<int> left;

    // Larger half
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
    }

    void addNum(int num) {

        // First put it into left
        left.push(num);

        // Make sure left.top() <= right.top()
        if (!right.empty() && left.top() > right.top()) {

            int x = left.top();
            left.pop();

            int y = right.top();
            right.pop();

            left.push(y);
            right.push(x);
        }

        // Balance sizes
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() > right.size()) {
            return left.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};