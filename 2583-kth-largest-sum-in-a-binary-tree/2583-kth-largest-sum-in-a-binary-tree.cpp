/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // Handle case where root is null

        priority_queue<long long, vector<long long>, greater<long long>> minHeap; // Min-heap for top k sums
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long sum = 0;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            if (minHeap.size() < k) {
                minHeap.push(sum); 
            } else if (sum > minHeap.top()) {
                minHeap.pop(); 
                minHeap.push(sum); 
            }
        }

        return minHeap.size() < k ? -1 : minHeap.top(); 
    }
};
