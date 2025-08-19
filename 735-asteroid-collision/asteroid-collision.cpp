class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool alive = true;

            while (alive && a < 0 && !st.empty() && st.top() > 0) {
                if (st.top() < -a) {
                    st.pop();
                    continue;
                } else if (st.top() == -a) {
                    st.pop();
                }

                alive = false;
            }
            if (alive)
                st.push(a);
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
