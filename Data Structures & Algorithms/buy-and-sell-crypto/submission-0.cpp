class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //variable intialization
        int maxProfit;

                                                    //Special Case: vector size of one
        if (prices.size() == 1) {
            maxProfit = 0;
            return maxProfit;
        }
        
        int tempLow = prices[0];
        int tempHigh = prices[prices.size() - 1];
        int tempMax = tempHigh - tempLow;
        maxProfit = 0;
        //Check for the highest possible day you can sell out of the ones you've seen so far, since the others don't matter
                                                    //reverse loop to check highs first and compare with lows
        for (int i = prices.size() - 1; i >= 0; i--) {

                if(prices[i] > tempHigh) {
                    tempHigh = prices[i];
                }

                tempMax = tempHigh - prices[i];

                if (tempMax > maxProfit) {
                    maxProfit = tempMax;
                }

        }

        if (maxProfit < 0) {
            maxProfit = 0;
        }

        return maxProfit;
    }
};