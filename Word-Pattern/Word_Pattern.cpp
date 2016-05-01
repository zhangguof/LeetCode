
// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //string pat_map[26];
        vector<string> pat_map(26,"");
        vector<string> worlds;
        size_t start=0;
        size_t next=str.find(" ",start);
        while (next!=string::npos) {
            worlds.push_back(str.substr(start,next-start));
            start=next+1;
            next=str.find(" ",start);
        }
        worlds.push_back(str.substr(start,str.size()-start));
        
        
        size_t plen = pattern.size();
        string world="";
        char p;
        
        if(plen!=worlds.size())
            return false;
        for(size_t i=0;i<plen;i++)
        {
            p = pattern[i];
            world = worlds[i];
            if(pat_map[p-'a'].empty())
            {
                if(find(pat_map.begin(),pat_map.end(),world)!=pat_map.end())
                    return  false;
                pat_map[p-'a'] = world;
            }
            else if(pat_map[p-'a']!=world)
            {
                return false;
            }
        }
        

        
        return true;
        
    }
};

int main()
{
    Solution sol;
    //cout<<sol.wordPattern("a", "cat")<<endl;
    //cout<<sol.wordPattern("aa", "cat cat")<<endl;
    cout<<sol.wordPattern("aaa", "aa aa aa aa")<<endl;
    cout<<sol.wordPattern("ab", "dog dog")<<endl;
    
    return 0;
}