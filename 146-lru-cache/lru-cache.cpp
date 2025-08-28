class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        auto node = cache[key];
        int val = node->second;
        dll.erase(node);
        dll.push_front({key, val});
        cache[key] = dll.begin();
        return val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dll.erase(cache[key]);
        } else if (dll.size() == capacity) {
            auto last = dll.back();
            cache.erase(last.first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};
