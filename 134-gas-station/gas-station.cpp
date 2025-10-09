class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n;) {
            if (gas[i] < cost[i]) {
                i++;
                continue;
            } else {
                int curr = 0;

                for (int j = 0; j < n; j++) {
                    curr += gas[(j + i) % n] - cost[(j + i) % n];

                    if (curr < 0) {
                        i = j + i + 1;
                        break;
                    }
                }

                if (curr >= 0)
                    return i;
            }
        }
        return -1;
    }
};