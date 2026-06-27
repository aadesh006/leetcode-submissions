class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftTrav(n);
        vector<int> rightTrav(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            leftTrav[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            rightTrav[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> area(n);
        for (int i = 0; i < n; ++i) {
            int width = rightTrav[i] - leftTrav[i] - 1;
            area[i] = heights[i] * width;
        }

        return *max_element(area.begin(), area.end());
    }
};
