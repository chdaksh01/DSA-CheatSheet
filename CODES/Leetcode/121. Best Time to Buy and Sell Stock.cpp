//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.class Solution {

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Time - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least=prices[0];
        int ans=0;
      
        for (int i=1; i<prices.size(); i++)
        {
            if (prices[i]<least) {least = prices[i];}
            if (prices[i]-least>ans) {ans=prices[i]-least;}
        }
        return ans;
    }
};
