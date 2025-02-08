// 2349. Design a Number Container System

class NumberContainers {
public:

    map<int,int> mp;
    map<int, priority_queue<int, vector<int>, greater<int>>> mp2;
    NumberContainers() {}
    
    void change(int index, int number) {
        mp[index] = number;
        mp2[number].push(index);
    }
    
    int find(int number) {
        while(!mp2[number].empty() && mp[mp2[number].top()] != number) {
            mp2[number].pop();
        }
        return !mp2[number].empty() ? mp2[number].top() : -1;
    }
};
