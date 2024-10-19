class Solution {
public:
    char findKthBit(int n, int k) {
        int len = pow(2, n) - 1;
        if (n == 1) {
            return '0';
        }
        if (k < (len / 2) + 1) { 
            return findKthBit(n - 1, k);
        }
        else if (k == (len / 2) + 1) { 
            return '1';
        }
        else {
            char ch = findKthBit(n - 1, len - (k - 1)); 
            return (ch == '0') ? '1' : '0'; 
        }
    }
};
