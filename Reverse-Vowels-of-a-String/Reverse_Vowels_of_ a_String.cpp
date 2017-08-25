
// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:
// Given s = "hello", return "holle".

// Example 2:
// Given s = "leetcode", return "leotcede".

#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
    	string vowels = "aeiouAEIOU";
    	string a = "";
    	string b = "";
        int i,j;
        i = 0;
        j = s.size()-1;
        if (i==j)
        {
            return s;
        }
        while (i<j)
        {
            
            while(vowels.find(s[i])==string::npos && i<j)
            {
                a.push_back(s[i++]);
            }
            while(vowels.find(s[j])==string::npos && i<j)
            {
                b.push_back(s[j--]);
            }
            if(i<j)
            {
                a.push_back(s[j--]);
                b.push_back(s[i++]);
            }
            
        }
        if(i==j)
        {
            a.push_back(s[i]);
        }
        reverse(b.begin(),b.end());
        return a+b;
        
    }

};

int testmain1(){
	Solution sol;
    cout<<sol.reverseVowels("leetcode")<<endl;
    cout<<sol.reverseVowels("hEllo")<<endl;
    cout<<sol.reverseVowels("a a")<<endl;
    cout<<sol.reverseVowels("a.")<<endl;
    
	return 0;
}

