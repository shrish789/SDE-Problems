/*

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

class LRUCache {
public:
    list<int> l;
    unordered_map<int,pair<int,list<int>::iterator>> mymap1;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mymap1.find(key)!=mymap1.end()){
            l.erase(mymap1[key].second);
            l.push_front(key);
            mymap1[key]={mymap1[key].first,l.begin()};
            return mymap1[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mymap1.find(key)!=mymap1.end()){
            l.erase(mymap1[key].second);
        }
        else{
            if(l.size()==n){
                mymap1.erase(l.back());
                l.pop_back();
            }
        }
        l.push_front(key);
        mymap1[key]={value, l.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
