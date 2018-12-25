// 215. Kth Largest Element in an Array
// Medium

// 1499

// 146

// Favorite

// Share
// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	struct Heap
	{
		//min heap
		vector<int> data;
		int max_size;
		Heap(int n){max_size = n;}
		//min head, max down
		void do_down(int i)
		{
			int L = 2*i+1;
			int R = 2*i+2;
			int min_i = i;
			if(L<data.size() && data[L] < data[min_i])
			{
				min_i = L;
			}
			if(R<data.size() && data[R] < data[min_i])
			{
				min_i = R;
			}

			if(min_i!=i)
			{
				swap(data[i],data[min_i]);
				// val2idx[data[i].val] = i;
				// val2idx[data[min_i].val] = min_i;
				do_down(min_i);
			}

		}
		//min head , min up!
		void do_up(int i)
		{
			if(i==0) return;
			//i>0,p>=0
			int p = (i-1)/2;
			if(data[i]<data[p])
			{
				std::swap(data[p],data[i]);
				// val2idx[data[p].val] = p;
				// val2idx[data[i].val] = i;
				do_up(p);
			}
		}
		void push(int v)
		{
			if(data.size()>=max_size)
			{
				if(v > data[0])
				{
					data[0] = v;
					do_down(0);
				}
			}

			else
			{
				data.push_back(v);
				do_up(data.size()-1);
			}
		}
		void print()
		{
			for(auto i:data)
			{
				printf("%d,",i);
			}
			printf("\n");
		}
		int get_max()
		{
			int max = -1;
			for(auto i:data)
			{
				if(max==-1 || i>max)
				{
					max = i;
				}
			}
			return max;
		}
		int get_min()
		{
			return data[0];
		}
	};
	// class Comp
	// {
	// public:
	// 	bool operator()(const int a,const int b)
	// 	{
	// 		return a<b;
	// 	}
	// };
    int findKthLargest(vector<int>& nums, int k) {
    	// Heap heap(k);
    	// for(auto a:nums)
    	// {
    	// 	heap.push(a);
    	// }
    	// // heap.print();
    	// return heap.get_min();

    	priority_queue<int,vector<int>,std::greater<int> > pq;
    	// priority_queue<int,vector<int>,Comp> pq;
    	for(auto a:nums)
    	{
    		if(pq.size()<k)
    		{
    			pq.push(a);
    		}
    		else
    		{
    			auto top = pq.top();
    			if(a>top)
    			{
    				pq.pop();
    				pq.push(a);
    			}
    		}
    	}
    	return pq.top();

      }
};

int main()
{
	std::vector<int> v = {3,2,1,5,6,4};
	Solution sol;
	printf("%d\n",sol.findKthLargest(v,2));
	return 0;
}
