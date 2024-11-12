class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(), items.end(), comp);

    int n = items.size();
    vector<int> maxBeauty(n);
    maxBeauty[0] = items[0][1];
    for (int i = 1; i < n; i++) {
        maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
    }

    vector<int> result;
    for (int ele : queries) {

        auto it = upper_bound(items.begin(), items.end(), vector<int>{ele, INT_MAX}, comp) - items.begin() - 1;

        if (it >= 0)
            result.push_back(maxBeauty[it]);
        else
            result.push_back(0);
    }

    return result;
}
};