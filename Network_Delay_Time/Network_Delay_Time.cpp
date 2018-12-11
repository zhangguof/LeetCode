// 743. Network Delay Time
// Easy

// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

// Note:
// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>


using namespace std;

class Solution {
public:
	struct Node
	{
		int num;
		int time;
		Node(int n,int t):num(n),time(t){}
		bool operator<(Node const& n) const{
			return time < n.time;
		}
	};
	//min heap
	class pri_queue
	{
	public:
		std::vector<Node> v;
		std::vector<int> num2idx;
		int n;
		pri_queue(int max_n){
			n = 0;
			num2idx.resize(max_n);
		}
		void up_adjust(int i)
		{
			if(i==0) return;
			int P = (i-1)/2;
			while(v[i] < v[P] && i!=0)
			{
				auto t = v[P];
				v[P] = v[i];
				v[i] = t;

				num2idx[v[P].num] = P;
				num2idx[v[i].num] = i;

				i = P;
				P = (i-1)/2;
			}
		}
		void down_adjust(int i)
		{
			int L;
			int R;
			int min_i;
			while(1)
			{
				L = 2*i + 1;
				R = 2*i + 2;
				min_i = i;
				if(L<n && v[L] < v[min_i]) min_i = L;
				if(R<n && v[R] < v[min_i]) min_i = R;
				if(min_i == i) break;
				auto t = v[min_i];
				v[min_i] = v[i];
				v[i] = t;

				num2idx[v[min_i].num] = min_i;
				num2idx[v[i].num] = i;

				i = min_i;
			}
		}
		void push(Node node)
		{
			v.push_back(node);
			++n;
			num2idx[node.num] = n-1;
			up_adjust(n-1);
		}
		Node top()
		{
			return v[0];
		}
		Node extrac_min()
		{
			auto node = v[0];
			v[0] = v[n-1];
			num2idx[v[0].num] = 0;

			v.pop_back();
			n--;
			down_adjust(0);
			return node;
		}
		void decrease(int i,int t)
		{
			v[i].time = t;
			up_adjust(i);
		}
		void increase(int i,int t)
		{
			v[i].time = t;
			down_adjust(i);
		}
		void modify(int i,int t)
		{
			if(v[i].time < t)
			{
				increase(i,t);
			}
			if(v[i].time > t)
			{
				decrease(i,t);
			}
		}
		int get_idx(int num)
		{
			return num2idx[num];
		}
		bool empty(){return n==0;}
		
		void print()
		{
			for(auto it:v)
			{
				printf("%d ",it.time);
			}
			printf("\n");
		}


	};
	int dijkstra(vector<vector<Node> >& g,int n,int k)
	{
		std::vector<int> dist(n+1,-1);
		dist[0]=0;
		// std::vector<bool> acc_mark(n+1,false);
		dist[k] = 0;
		pri_queue pqueue(n+1);
		for(int i=1;i<=n;++i)
		{
			if(i==k)
			{
				pqueue.push(Node(k,0));
			}
			else
			{
				pqueue.push(Node(i,9999999));
			}
		}
		
		while(1)
		{
			//extrac min
			// int min_i = -1;
			// int min_v = -1;
			// for(int i=1;i<=n;++i)
			// {
			// 	if(acc_mark[i]||dist[i]==-1) continue;
			// 	if(min_v==-1 || min_v>dist[i])
			// 	{
			// 		min_i = i;
			// 		min_v = dist[i];
			// 	}
			// }
			// if(min_i == -1) break;
			if(pqueue.empty()) break;
			auto min_n = pqueue.extrac_min();
			int min_i = min_n.num;
			int min_v = min_n.time;

			// acc_mark[min_i] = true;
			for(auto it:g[min_i])
			{
				int d = min_v + it.time;
				if(dist[it.num]==-1 || d<dist[it.num])
				{
					dist[it.num] = d;
					auto idx = pqueue.get_idx(it.num);
					pqueue.modify(idx,d);
				}
			}
		}
		int max_time = -1;
		for(auto it:dist)
		{
			if(it==-1)
			{

				return -1;
			}
			if(it>max_time) max_time =it;
		}

		return max_time;

	}
	int breadth_search(int n,vector<vector<Node> >& g,int k)
	{
		std::vector<int> times(n+1,-1);
		int max_time = 0;
		queue<int> q;
		q.push(k);
		times[k] = 0;
		times[0] = 0;

		while(!q.empty())
		{

			int cur_num = q.front();
			q.pop();
			for(auto it:g[cur_num])
			{
				int t = times[cur_num] + it.time;
				if(times[it.num] == -1 || times[it.num] > t)
				{
					times[it.num] = t;
					q.push(it.num);
				}
			}


		}
		for(auto it:times)
		{
			if(it==-1)
			{

				return -1;
			}

			if(it>max_time) max_time =it;
		}

		return max_time;
	}
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {

    	std::vector<std::vector<Node> > g(N+1);

    	for(auto v:times)
    	{
    		g[v[0]].push_back(Node(v[1],v[2]));

    	}
    	// int t = breadth_search(N,g,K);
    	int t = dijkstra(g,N,K);

        return t;
    }
};

int main()
{
	Solution sol;
	std::vector<std::vector<int> > times = {
		// {1,2,1}

		// {2,1,1},
		// {2,3,1},
		// {3,4,1}

		// {1,2,1},
		// {2,3,2},
		// {1,3,4}

		// {1,2,1},
		// {2,1,3}

		{3,5,78},{2,1,1},{1,3,0},
		{4,3,59},{5,3,85},{5,2,22},
		{2,4,23},{1,4,43},{4,5,75},
		{5,1,15},{1,5,91},{4,1,16},
		{3,2,98},{3,4,22},{5,4,31},
		{1,2,0},{2,5,4},{4,2,51},
		{3,1,36},{2,3,59}
	};
	int n = 5;
	int k = 5;
	printf("%d\n",sol.networkDelayTime(times,n,k));

	//test heap
	// std::vector<int> v={4,3,2,5,6,8};
	// Solution::pri_queue pqueue;
	// for(auto it:v)
	// {
	// 	pqueue.push(Solution::Node(0,it));
	// }
	// pqueue.print();
	// auto t = pqueue.extrac_min();
	// printf("%d\n",t.time);
	// printf("%d\n",pqueue.extrac_min().time);
	// pqueue.print();
	// pqueue.modify(1,1);
	// pqueue.print();


	return 0;
}