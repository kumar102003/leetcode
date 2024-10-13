#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second; 
        }
        return a.first > b.first; 
    }

    int x_sum(int i, int j, vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comp)> pq(comp); 

        for (int idx = i; idx < j; idx++) { 
            mp[nums[idx]]++;
        }

        for (auto& entry : mp) {
            pq.push({entry.second, entry.first});
            if (pq.size() > x) {
                pq.pop();
            }
        }

        int sum = 0; 
        while (!pq.empty()) {
            auto it = pq.top();
            sum += it.first * it.second; 
            pq.pop();
        }

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);

        for (int i = 0; i <= n - k; i++) { 
            int j = i + k;
            ans[i] = x_sum(i, j, nums, k, x);
        }

        return ans;
    }
};
