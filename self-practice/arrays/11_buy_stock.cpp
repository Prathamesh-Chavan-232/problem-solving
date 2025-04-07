// Question - Best time to buy stock - Leetcode - Easy
// Similar to question max_diff
// link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int diff = 0, max_diff = 0;
        int min_price = prices[0];
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < min_prices)
            {
                min_price = prices[i];
            }

            diff = prices[i] - min_price;

            if (diff > max_diff)
            {
                max_diff = diff;
            }
        }
        return max_diff;
    }
};