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

 int high = prices[1];

 int highIndex = 1;

  

int low = prices[0];

int lowIndex = 0;

maxProfit = high - low;

  

 int tempLow;

int tempHigh;

int tempMax;

  
  

 //loop finds low

 for (int i = 0; i < prices.size(); i++) {

tempLow = prices[i];

  

 for (int j = i; j < prices.size(); j++) {

tempHigh = prices[j];

tempMax = tempHigh - tempLow;

  

if(tempMax > maxProfit && j > i) {

 maxProfit = tempMax;

}

 }

 }

  

if (maxProfit < 0) {

 maxProfit = 0;

 }

  

 return maxProfit;

 }

};
