class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int day = prices[0];
        for( int i = 1 ; i < prices.size(); i++){
           int  profit = prices[i]-day;
            max_profit = max(max_profit,profit);

             day= min(day,prices[i]);
        }
        return max_profit;
    }
};