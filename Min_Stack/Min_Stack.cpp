// Min Stack
//   Go to Discuss
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stack>
#include <unordered_map>

using namespace std;



class MinStack {
public:
	//min heap
	#define LEFT(idx) (2*idx+1)
	#define RIGHT(idx) (2*idx+2)
	#define PARENT(idx) ((idx-1)/2)

	class Heap
	{
	public:
		unordered_map<int,int> val2idx;
		vector<std::pair<int,int> > data;
		int n;
		Heap(){n=0;}
		void push(int val)
		{
			//return idx;
			auto find_it = val2idx.find(val);
			int idx;
			// printf("cur n :%d,%d,%d\n",n,val,val2idx[val]);
			if(find_it == val2idx.end() || find_it->second==-1)
			{
				val2idx[val] = n;
				if(n>=data.size())
				{
					data.push_back(std::make_pair(val,1));
				}
				else
				{
					data[n] = std::make_pair(val,1);
				}
				++n;
				idx = n-1;
				// printf("new push:%d,%d\n",idx,val);
			}
			else
			{
				idx = find_it->second;
				data[idx].second++;
				// printf("add push:%d,%d\n",val,idx);

			}
			// val2idx[val] = n-1;
			up(idx);
			// for(auto i:data)
			// {
			// 	printf("%d,", i);
			// }
			// printf("\n");
		}
		int top()
		{
			return data[0].first;
		}
		void pop(int val)
		{

			auto idx = val2idx[val];
			// auto it = data[idx];
			data[idx].second--;
			// --n;
			// printf("do pop:%d,%d,%d\n",idx,data[idx].first,data[idx].second);
			if(data[idx].second>0) return;

			--n;
			// if(n==0) return;

			// printf("n:%d\n",n);
			auto tmp = data[n].first;
			// auto s = val2idx.erase(val);
			val2idx[val] = -1;
			// printf("===%d,%d\n",val,val2idx[val]);
			if(n==0 || n==idx) return;
			// printf("do_erase:%d,%d\n",val,s);

			swap(data[idx],data[n]);
			val2idx[data[idx].first] = idx;
			// adjust(idx);
			// printf("do pop:%d,%d\n",idx,val);
			if(val < tmp)
			{
				down(idx);
			}
			else if(val > tmp)
			{
				up(idx);
			}
		} 
		void up(int idx)
		{
			auto p = PARENT(idx);
			if(p>=0 && data[p].first>data[idx].first)
			{
				swap(data[p],data[idx]);
				val2idx[data[p].first] = p;
				val2idx[data[idx].first] = idx;
				up(p);
			}
		}
		void down(int idx)
		{
			auto l = LEFT(idx);
			auto r = RIGHT(idx);
			auto t = idx;
			if(l<n && data[l].first<data[t].first)
			{
				t = l;
			}
			if(r<n && data[r].first<data[t].first)
			{
				t = r;
			}
			if(t!=idx)
			{
				swap(data[idx],data[t]);
				val2idx[data[idx].first] = idx;
				val2idx[data[t].first] = t; 
				down(t);
			}
		}
		// void adjust(int idx)
		// {

		// }
	};
public:
    /** initialize your data structure here. */
    stack<int> st;
    Heap heap;

    // int min_val;
    MinStack() {
        // min_val = 0x80000000;
    }
    
    void push(int x) {
        st.push(x);
        heap.push(x);
 
    }
    
    void pop() {
    	int val = st.top();
    	heap.pop(val);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return heap.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
	// MinStack::Heap h;
	// int a[] = {5,4,3,1,2};
	// for(auto i:a)
	// {
	// 	h.push(i);
	// 	printf("%d\n",h.data[0]);
	// }
	MinStack m;
	m.push(2147483646);
	m.push(2147483646);
	m.push(2147483647);
	printf("%d\n",m.top());
	m.pop();
	printf("%d\n",m.getMin());
	m.pop();
	printf("%d\n",m.getMin());
	m.pop();
	m.push(2147483647);
	printf("%d\n",m.top());
	printf("%d\n",m.getMin());//error

	m.push(-2147483648);
	printf("%d\n",m.top());
	printf("%d\n",m.getMin());
	m.pop();
	printf("%d\n",m.getMin());





	return 0;
}
