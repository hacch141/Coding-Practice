// 3072. Distribute Elements Into Two Arrays II

// OrderedMultiset
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> struct ordered_multiset {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void insert(T val) {
        ost.insert(make_pair(val, ++freq[val]));
    }

    void erase(T val) {
        ost.erase(make_pair(val, freq[val]--));
    }

    int order_of_key(T val) {  // get index of val
        return ost.order_of_key(make_pair(val, -1));
    }

    T find_by_order(T val) {  // get element at index
        return ost.find_by_order(val)->first;
    }

    T bisect_left(T val) {  // return lower bound
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    T bisect_right(T val) {  // return upper bound
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() {
        return ost.size();
    }

    bool empty() {
        return ost.empty();
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        ordered_multiset<int> o1, o2;
        vector<int> v1, v2;
        o1.insert(nums[0]);
        v1.push_back(nums[0]);
        o2.insert(nums[1]);
        v2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            int a = o1.size() - o1.bisect_right(nums[i]);
            int b = o2.size() - o2.bisect_right(nums[i]);
            if(a > b) {
                o1.insert(nums[i]);
                v1.push_back(nums[i]);
            }
            else if(a < b) {
                o2.insert(nums[i]);
                v2.push_back(nums[i]);
            }
            else if(v1.size() <= v2.size()){
                o1.insert(nums[i]);
                v1.push_back(nums[i]);
            }
            else {
                o2.insert(nums[i]);
                v2.push_back(nums[i]);
            }
        }
        for(auto i : v2) v1.push_back(i);
        return v1;
    }
};
