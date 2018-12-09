// 853. Car Fleet
// Medium
// N cars are going to the same destination along a one lane road.  The destination is target miles away.

// Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.

// A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.

// The distance between these two cars is ignored - they are assumed to have the same position.

// A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.

// If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.


// How many car fleets will arrive at the destination?

 

// Example 1:

// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
// Output: 3
// Explanation:
// The cars starting at 10 and 8 become a fleet, meeting each other at 12.
// The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
// The cars starting at 5 and 3 become a fleet, meeting each other at 6.
// Note that no other cars meet these fleets before the destination, so the answer is 3.

// Note:

// 0 <= N <= 10 ^ 4
// 0 < target <= 10 ^ 6
// 0 < speed[i] <= 10 ^ 6
// 0 <= position[i] < target
// All initial positions are different.

#include <iostream>
#include <algorithm>
#include <vector>


#include <stdlib.h>

#include <stack>

using namespace std;




class Solution {
public:
	struct Node {
		int pos;
		int speed;
		int cost;
		Node(int p,int s):pos(p),speed(s){cost=-1;}
		bool operator<(Node const& b) const
		{
			return pos<b.pos;
		}
	};
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    std::vector<Node> nodes;
    int n = position.size();
    if(n==0) return 0;
    for(int i=0;i<n;++i)
    {
    	nodes.push_back(Node(position[i],speed[i]));

    }
    sort(nodes.begin(),nodes.end());
    int arrive = 1;
    int last_speed = nodes[n-1].speed;
    int last_pos = nodes[n-1].pos;
    double last_cost = double(target - last_pos) / last_speed;
    // printf("cost:%f\n",last_cost);

//use the slower car as the car fleet's speed.
    for(int i=n-2;i>=0;i--)
    {
    	double c = double(target - nodes[i].pos) / nodes[i].speed;
    	// printf("cost:%f\n",c);
    	if(c<=last_cost)
    	{
    		continue;
    	}
    	last_cost = c;
    	arrive++;

    }
    // for(auto it:nodes)
    // {
    // 	printf("(%d,%d) ",it.pos,it.speed);
    // }
    // printf("\n");
    // std::stack<int> st;

     return arrive;   
    }
};

int main()
{
	// int t = 12;
	// std::vector<int> pos = {10,8,0,5,3};
	// std::vector<int> speed = {2,4,1,1,3};

	int t = 10;
	std::vector<int> pos = {6,8};
	std::vector<int> speed = {3,2};

	Solution sol;
	printf("%d\n",sol.carFleet(t,pos,speed));
	return 0;
}



