class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> p;
        map<int, map<int, vector<int>>> mp;
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        p.push(make_pair(root, make_pair(0, 0)));
        while (!p.empty()) {
            pair<TreeNode*, pair<int, int>> temp = p.front();
            p.pop();
            TreeNode* fNode = temp.first;
            int hd = temp.second.first;
            int lv = temp.second.second;
            mp[hd][lv].push_back(fNode->val);

            if (fNode->left) {
                p.push(make_pair(fNode->left, make_pair(hd - 1, lv + 1)));
            }
            if (fNode->right) {
                p.push(make_pair(fNode->right, make_pair(hd + 1, lv + 1)));  
            }
        }

        for (auto it : mp) {
            vector<int> col;  
            for (auto j : it.second) {
                sort(j.second.begin(), j.second.end());
                for (auto k : j.second) {
                    col.push_back(k);  
                }
            }
            ans.push_back(col);  
        }

        return ans;
    }
};
