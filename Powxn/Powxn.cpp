// Pow(x, n)
//   Go to Discuss
// Implement pow(x, n), which calculates x raised to the power n (xn).

// Example 1:

// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:

// Input: 2.10000, 3
// Output: 9.26100
// Example 3:

// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
// Note:

// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double sum = 1.0;
        if(n==0) return 1.0;
        bool is_neg = false;
        if(n<0)
        {
            n = -n;
            is_neg = true;
            if(n<0)
            {
            	n = 0-(n+1);
            	sum = x;
            }
        }
        printf("n:%d,%d\n",n,is_neg);
        while(n>0)
        {
            int i = 1;
            int pre_i = i;
            double s = x;
            while(1)
            {
                i = pre_i*2;
                // printf("%d\n",i);
                if(i>n || i<=0) break;
                pre_i = i;
                s = s*s;  
            }
            // printf("%d,%d,%f\n",pre_i,n,s);
            sum *= s;
            n -= pre_i;
        }
        return is_neg?1.0/sum:sum;
        
    }
};

int main()
{
	Solution sol;
	printf("%f\n",sol.myPow(2.000,2147483647));
	printf("%f\n",sol.myPow(2.000,-2147483648));

	return 0;
}
