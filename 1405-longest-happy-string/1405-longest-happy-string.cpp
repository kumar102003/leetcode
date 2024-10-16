class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans = "";
        while(!pq.empty()){
            int firstfreq = pq.top().first;
            char firstchar = pq.top().second;
            pq.pop();
            if(ans.length()>=2 && ans[ans.length()-1]==firstchar && ans[ans.length()-2]==firstchar){
                //cant use
                if(pq.empty()){
                    break;
                }
                int secondfreq = pq.top().first;
                int secondchar = pq.top().second;
                pq.pop();
                ans.push_back(secondchar);
                secondfreq--;
                if(secondfreq>0){
                    pq.push({secondfreq, secondchar});
                }
            }

            else{
                ans.push_back(firstchar);
                firstfreq--;
            }
            if(firstfreq>0){
                pq.push({firstfreq,firstchar});
            }
        }
        return ans;
    }
};