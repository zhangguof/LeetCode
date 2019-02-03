//  Factorial Trailing Zeroes
//   Go to Discuss
// Given an integer n, return the number of trailing zeroes in n!.

// Example 1:

// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Note: Your solution should be in logarithmic time complexity.


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Solution {
public:

    int get_fact(int n,int k)
    {
        vector<int> fac_num;
        int s = k;
        int sum = 0;
        int pre_s = 0;
        while(s<=n)
        {
        	// printf("%d,%d\n",n,s);
        	fac_num.push_back(n/s);
        	pre_s = s;
        	s *= k;
        	//over flow
        	if(s<=0 || s/k!=pre_s)
        	{
        		break;
        	}
        }

        sum = 0;
        if(fac_num.size()==0) return 0;
        for(int i = 0;i<fac_num.size()-1;++i)
        {
        	sum += (fac_num[i]-fac_num[i+1])*(i+1);
        }
        sum+=(fac_num.back() * fac_num.size());

        return sum;
    }
    int trailingZeroes(int n) {
        

        // init_prime_num(n);
        int n2=get_fact(n,2);
        int n5=get_fact(n,5);

        return n2<n5?n2:n5;
    }
};

int main()
{
	Solution sol;
	printf("%d\n",sol.trailingZeroes(3));
	printf("%d\n",sol.trailingZeroes(1808548329));
	// printf("size:%d\n",sol.prime_num.size());
	return 0;
}
