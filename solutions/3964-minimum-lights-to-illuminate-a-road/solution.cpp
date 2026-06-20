class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>diff(n+1,0);

        for(int i =0; i<n; i++){
            if(lights[i] > 0){
                int leftMost = max(0, i - lights[i]);
                int rightMost = min(n-1, i+lights[i]);

                diff[leftMost]++;
                diff[rightMost+1]--;
            }
        }

        vector<int>visibility(n,0);
        int current =0;
        for(int i =0; i<n; i++){
            current =current+diff[i];
            visibility[i] = (current>0);
        }

        int result =0;
        for(int i=0; i<n; i++){
            if(visibility[i]){
                continue;
            }

            int position = min(i+1, n-1);
            int L = max(0, position-1);
            int R = min(n-1, position+1);

            for(int j =L; j<=R;j++){
                visibility[j] = true;
            }
            result++;
        }

        return result;
    }
};
