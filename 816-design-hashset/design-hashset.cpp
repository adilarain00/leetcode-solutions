class MyHashSet {
private:
    vector<bool> hashTable;

public:
    MyHashSet() {
        hashTable.resize(1e6 + 1, false);
    }
    
    void add(int key) {
        hashTable[key] = true;
    }
    
    void remove(int key) {
        hashTable[key] = false;
    }
    
    bool contains(int key) {
        return hashTable[key];
    }
};