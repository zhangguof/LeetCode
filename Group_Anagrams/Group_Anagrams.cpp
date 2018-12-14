// 49. Group Anagrams
// Medium


// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
    	vector<vector<string> > ret;
    	unordered_map<string,int> str2idx;
        //sort 
        vector<string> keys;
        for(auto i:strs)
        {
        	sort(i.begin(),i.end());
        	keys.push_back(i);
        }
        int n = 0;
        for(int i=0;i<keys.size();++i)
        {
        	auto find_it = str2idx.find(keys[i]);
        	if(find_it==str2idx.end())
        	{
        		ret.push_back(vector<string>());
        		ret[n].push_back(strs[i]);
        		str2idx[keys[i]] = n;
        		++n;
        	}
        	else
        	{
        		int idx = find_it->second;
        		ret[idx].push_back(strs[i]);
        	}
        }
        return ret;
    }
};



int main()
{
	vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution sol;
	auto ret = sol.groupAnagrams(s);
	for(auto i: ret)
	{
		for(auto j:i)
		{
			cout<<j<<",";
		}
		cout<<endl;
	}

	return 0;
}
