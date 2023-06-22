class Solution {
public:
    // for each day we can sell or buy
    // if we want to buy profit ager profit(make sure agge kini nai) + (-prices[i])
    // if we want to sell ager profit + prices[i] - fee(make sure agge kinsi)
    // ekhane agge kisi pabo hold[i - 1]
    // agge kini nai pabo free[i-1]
    
    // abr ith e kena beach kichu nao korte pari
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> free(prices.size(), 0), hold(prices.size(), 0);
        
        free[0] = 0;
        hold[0] = -prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            free[i] = max(free[i-1], hold[i-1] + prices[i] - fee);
            hold[i] = max(hold[i-1], free[i-1] - prices[i]);
        }

        return free[prices.size() - 1];
    }
};