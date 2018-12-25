// Merge Intervals
//   Go to Discuss
// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	// struct Comp
	// {

	// };
	static bool cmp(Interval& a,Interval& b)
	{
		if(a.start == b.start) return a.end < b.end;
		return a.start < b.start;
	}
    vector<Interval> merge(vector<Interval>& intervals) {
    	sort(intervals.begin(),intervals.end(),cmp);
    	// for(auto i:intervals)
    	// {
    	// 	printf("(%d,%d) ",i.start,i.end);
    	// }
    	// printf("\n");

        vector<Interval> r;
        int n = intervals.size();
        if(n==0) return r;
        auto a = intervals[0];
        int i = 1;
        while(i<n)
        {
        	if(intervals[i].end <=a.end)
        	{
        		++i;
        		continue;
        	}
        	
        	if(a.end>=intervals[i].start && a.end<=intervals[i].end)
        	{
        		a.end = intervals[i].end;
        	}
        	else
        	{
        		r.push_back(a);
        		a = intervals[i];
        	}
        	// if(i==n-1)
        	// {
        	// 	r.push_back(a);
        	// }
        	++i;
        }
        r.push_back(a);

        return r;
    }
};

int main()
{
	Solution sol;
	vector<Interval> a = {
		{1,4},
		{2,3}
		// {1,3},
		// {1,2},
		// {8,10},
		// {15,18}
	};
	auto r = sol.merge(a);
	for(auto i:r)
	{
		printf("(%d,%d) ",i.start,i.end);
	}
	printf("\n");

	return 0;
}
