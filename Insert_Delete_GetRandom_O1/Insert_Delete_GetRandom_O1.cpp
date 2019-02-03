// Insert Delete GetRandom O(1)
//   Go to Discuss
// Design a data structure that supports all following operations in average O(1) time.

// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
// Example:

// // Init an empty set.
// RandomizedSet randomSet = new RandomizedSet();

// // Inserts 1 to the set. Returns true as 1 was inserted successfully.
// randomSet.insert(1);

// // Returns false as 2 does not exist in the set.
// randomSet.remove(2);

// // Inserts 2 to the set, returns true. Set now contains [1,2].
// randomSet.insert(2);

// // getRandom should return either 1 or 2 randomly.
// randomSet.getRandom();

// // Removes 1 from the set, returns true. Set now contains [2].
// randomSet.remove(1);

// // 2 was already in the set, so return false.
// randomSet.insert(2);

// // Since 2 is the only number in the set, getRandom always return 2.
// randomSet.getRandom();

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    std::unordered_map<int,int> H;//val2indx
    std::vector<int> data; //val
    int size;
    RandomizedSet() {
        H.clear();
        data.clear();
        size = 0;
        srand (time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto find_it = H.find(val);
        if(find_it==H.end())
        {
        	if(size>=data.size())
        	{
        		data.resize(size+10);
        	}
        	data[size] = val;
        	H[val] = size;
        	size++;
        	return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto find_it = H.find(val);
        if(find_it==H.end())
        {
        	return false;
        }
        int idx = find_it->second;
        std::swap(data[idx],data[size-1]);
        H[data[idx]] = idx;
        H.erase(val);
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {

    	int n = rand() % size;
    	// printf("%d\n",rand());
    	return data[n];
    }
    void print()
    {
    	for(int i=0;i<size;++i)
    	{
    		printf("%d,",data[i]);
    	}
    	printf("\n");

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
	RandomizedSet obj;;
	bool p1 = obj.insert(1);
	bool p2 = obj.remove(2);
	bool p3 = obj.insert(2);
	// printf("%d,")
	bool p4 = obj.insert(3);
	int v = obj.getRandom();
	int v2 = obj.getRandom();
	obj.print();
	printf("%d,%d,%d,%d,(%d,%d)\n",p1,p2,p3,p4,v,v2);
	unordered_map<int,int> h;
	for(int i=0;i<1000;++i)
	{
		// printf("%d\n",obj.getRandom());
		h[obj.getRandom()]++;
	}
	for(auto i:h)
	{
		printf("%d:%d,%0.2f\n",i.first,i.second,
		i.second*1.0f / 1000.f);
	}

	return 0;
}
