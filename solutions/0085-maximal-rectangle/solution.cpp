class Solution {
private:
    int maxAreaHelper(vector<int>& heights){
        stack<int> st;
        int maxArea =0;
        int n =heights.size();
        
        for (int i = 0; i <=n; i++) {
            int currentHeight;
            if (i == n) currentHeight =0;
            else currentHeight =heights[i];
            
            while (!st.empty() && heights[st.top()] >currentHeight) {
                int h = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) width =i;
                else width = i -st.top() -1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxArea =0;
        vector<int>heights(cols, 0);

        for(int i=0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(matrix[i][j] == '1') heights[j] +=1;
                else heights[j] =0;
            }
            maxArea= max(maxArea, maxAreaHelper(heights));
        }
        return maxArea;
    }
};
