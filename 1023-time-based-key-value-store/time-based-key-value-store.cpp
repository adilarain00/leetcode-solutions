class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end())
            return "";

        auto& arr = store[key];
        int left = 0, right = arr.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first <= timestamp) {
                res = arr[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
