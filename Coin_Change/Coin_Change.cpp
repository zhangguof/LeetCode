
// Coin Change
//   Go to Discuss
// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>


using namespace std;

class Solution {
public:
	int do_change(unordered_map<int,int>&H,vector<int>& coins,int amount)
	{
		assert(amount > 0);
		// printf("change %d\n",amount);
		auto find_it = H.find(amount);
		if(find_it!=H.end())
		{
			return find_it->second;
		}
		int min_val = -1;
		int ret;
		for(int i=0;i<coins.size();++i)
		{
			if(amount % coins[i] == 0 && min_val == -1)
			{
				int k = amount/coins[i];
				if(min_val>k)
				{
					min_val = k;
					// printf("amount:%d,min_val:%d,coins:%d\n",amount,min_val,i);
					continue;
				}
			}
			int remain = amount - coins[i];
			// if(remain == 0)
			// {
			// 	min_val = 1;
			// 	break;
			// }
			if(remain < 0) continue;
			ret = do_change(H,coins,remain);
			if(ret == -1) continue;
			if(min_val == -1 || ret+1 < min_val)
			{
				// printf("updata min:amount=%d,remain=%d,min_val=%d,ret=%d\n",
				// amount,remain,min_val,ret);
				min_val = ret + 1;
			}

		}
		// printf("change %d\n",amount);
		// if(min_val != -1)
		// {
		// 	H[amount] = min_val;
		// 	return min_val;
		// }
		H[amount] = min_val;
		return min_val;
	}
    int coinChange(vector<int>& coins, int amount) {
    	if(amount == 0) return 0;
    	sort(coins.begin(),coins.end(),std::greater<int>());

    	unordered_map<int,int> H;
    	int n = coins.size();
    	for(int i=0;i<n;++i)
    	{
    		H[coins[i]] = 1;
    	}

    	int ret =  do_change(H,coins,amount);
    	// for(auto i:H)
    	// {
    	// 	printf("H[%d]=%d\n",i.first,i.second);
    	// }

    	return ret;
    	
        
    }
};


int main()
{
	Solution sol;
	// vector<int> coins = {
	// 	186,419,83,408
	// 	// 1,2,5
	// };
	// int amount=6249;

	std::vector<int> coins  = {
		2147483647
	};
	int amount = 2;
	// int amount = 11;
	printf("%d\n",sol.coinChange(coins,amount));


	return 0;
}
