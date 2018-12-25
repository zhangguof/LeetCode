// Top K Frequent Elements
//   Go to Discuss
// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
	struct Node
	{
		int val;
		int freq;
		Node(){val=-1;freq=-1;}
		Node(int v,int f)
		{
			val = v;
			freq = f;
		}
		bool operator<(const Node&  a) const{
			return freq<a.freq;
		}
	};
	struct Heap
	{
		//min heap
		vector<Node> data;
		// unordered_map<int,int> val2idx;
		int max_size;
		int size;
		Heap(int n){
			data.resize(n);
			max_size = n;
			size = 0;
		}
		//min head, max down
		void do_down(int i)
		{
			int L = 2*i+1;
			int R = 2*i+2;
			int min_i = i;
			if(L<size && data[L] < data[min_i])
			{
				min_i = L;
			}
			if(R<size && data[R] < data[min_i])
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

		void push(int v,int f)
		{
			// auto it = val2idx.find(v);
			// // printf("push %d,%d\n",v,f);
			// if(it!=val2idx.end() && it->second!=-1)
			// {
				
			// 	int i = it->second;
			// 	int tf = data[i].freq;
			// 	// printf("find idx:%d\n",i);
			// 	// data[i].val = v;
			// 	data[i].freq = f;
			// 	// printf("freq updata:%d,%d,%d->%d\n",v,i,tf,f);
			// 	assert(f>tf);
			// 	if(f>tf)
			// 	{
			// 		do_down(i);
			// 	}
			// 	return;
			// }
			if(size >= max_size)
			{
				if(data[0].freq < f)
				{
					// val2idx[data[0].val] = -1;
					data[0].val = v;
					data[0].freq = f;
					// val2idx[v] = 0;
					do_down(0);
					// printf("change eletem:%d,%d,%d\n",v,f,val2idx[v]);
				}
			}
			else
			{
				// data.push_back(Node(v,f));
				data[size++] = Node(v,f);
				// size++;
				// printf("new eletem %d,%d\n",v,f);
				// val2idx[v] = size-1;
				do_up(size-1);
				// printf("new eletem:%d,%d,%d\n",v,f,val2idx[v]);
			}
		}
		vector<int> make_sort()
		{
			vector<int> a(max_size);
			// a.push_back(data[0].val);
			int n = size;

			for(int i=n-1;i>=0;--i)
			{
				// a.push_back(data[0].val);
				a[i] = data[0].val;
				swap(data[0],data[size-1]);
				// data.pop_back();
				size--;
				do_down(0);
			}
			return a;
		}
		void print()
		{
			for(int i=0;i<size;++i)
			{
				printf("(%d,%d) ",data[i].val,data[i].freq);
			}
			printf("\n");
		}
	};

    vector<int> topKFrequent(vector<int>& nums, int k) {
    	std::unordered_map<int,int> freq;
    	int n = nums.size();
    	Heap heap(k);
    	for(int i=0;i<n;++i)
    	{
    		auto iter = freq.find(nums[i]);
    		if(iter  == freq.end())
    		{
    			freq[nums[i]] = 1;
    		}
    		else
    		{
    			freq[nums[i]]++;
    		}
    		// heap.push(nums[i],freq[nums[i]]);
    	}
    	for(auto it:freq)
    	{
    		heap.push(it.first,it.second);
    	}
    	// heap.print();
    	return heap.make_sort();
       

        // return topk;
        
    }
};



int main()
{
	Solution sol;
	vector<int> nums = {1,1,1,2,2,3};
	// vector<int> nums =  {4,1,-1,2,-1,2,3};

	auto r = sol.topKFrequent(nums,2);
	for(auto i:r)
	{
		printf("%d,",i);
	}
	printf("\n");

	return 0;
}
