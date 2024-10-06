class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()){
            swap(s1, s2); // Ensure s1 is the longer or equal length string
        }

        vector<string> v1, v2;
        stringstream ss1(s1), ss2(s2);
        string token;
        
        while(ss1 >> token){
            v1.push_back(token);
        }
        while(ss2 >> token){
            v2.push_back(token);
        }

        int i = 0, j = v2.size() - 1;
        int k = 0, l = v1.size() - 1;

        // Compare prefixes
        while(i < v2.size() && v1[i] == v2[i]){
            i++;
        }

        // Compare suffixes
        while(j >= i && v1[l] == v2[j]){
            j--;
            l--;
        }

        return j < i;
    }
};
