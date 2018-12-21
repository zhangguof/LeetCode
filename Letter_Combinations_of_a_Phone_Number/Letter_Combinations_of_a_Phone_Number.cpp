// Letter Combinations of a Phone Number
//   Go to Discuss
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	vector<string > nums;
	Solution(){
		nums.push_back("");
		nums.push_back("");
		char* s[] = {
			"abc","def","ghi",
			"jkl","mno","pqrs",
			"tuv","wxyz"
		};
		for(int i=2;i<=9;++i)
		{
			nums.push_back(s[i-2]);
		}
	}
	void get_letter(vector<string>& v,string& digits,int cur_i,string pre_ans)
	{
		//cur_i = '2',cur_j = 'b'
		string s = nums[digits[cur_i] - '0'];//like 'abc'
		int m = s.size();
		for(int i=0;i<m;++i)
		{
			string new_ans = pre_ans + s[i];
			if(cur_i==digits.size()-1)
			{
				v.push_back(new_ans);
			}
			else
			{
				get_letter(v,digits,cur_i+1,new_ans);
			}
		}

	}
    vector<string> letterCombinations(string digits) {
    	vector<string> v;

    	get_letter(v,digits,0,"");
    	return v;
    }
};

int main()
{
	string s = "232";
	Solution sol;
	auto v = sol.letterCombinations(s);
	for(auto i:v)
	{
		cout<<i<<",";
	}
	cout<<endl;
	printf("%d\n",v.size());


	return 0;
}
