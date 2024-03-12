class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (st.size() && temperatures[st.top()] < temperatures[i]) {
                int top = st.top();
                answer[top] = i - top;
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};
