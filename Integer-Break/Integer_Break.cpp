// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

// Note: you may assume that n is not less than 2.

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
//        if(n==4)
//            return 4;
        int m = n/3;
        int r = n%3;
        int s;
        if(r==1)
        {
            s=int(pow(3,m-1))*2*2;
        }
        else if(r==2)
        {
            s=int(pow(3,m))*2;
        }
        else if(r==0)
        {
            s=int(pow(3, m));
        }
        
        return s;
        
    }
};

int main()
{
    Solution sol;
    cout<<sol.integerBreak(10)<<endl;
    cout<<sol.integerBreak(6)<<endl;
    cout<<sol.integerBreak(2)<<endl;
    
    cout<<sol.integerBreak(8)<<endl;
    cout<<sol.integerBreak(4)<<endl;
    return 0;
}