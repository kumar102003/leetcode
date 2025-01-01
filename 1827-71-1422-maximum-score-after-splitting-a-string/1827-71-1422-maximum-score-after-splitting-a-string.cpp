class Solution {
public:
    int maxScore(string s) {
        int zc = 0; 
        int oc = 0; 
        int n = s.length();
        
      
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oc++;
            } else if (s[i] == '0') {
                zc++;
            }
        }
        
        int remZ = 0; 
        int remO = oc; 
        int ans = 0;

        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                remZ++;
            } else if (s[i] == '1') {
                remO--;
            }
            int sum = remZ + remO;
            ans = max(sum, ans); 
        }
        
        return ans;
    }
};
