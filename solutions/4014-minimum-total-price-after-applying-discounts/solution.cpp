class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discount) {
        int n=prices.size(), m=discount.size();
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discount.begin(), discount.end(), greater<int>());
        double total=0.0;
        int k=min(m,n);

        for(int i=0; i<n; i++){
            if(i<k) total +=(double)prices[i]*(100-discount[i])/100.0;
            else total +=(double)prices[i];
        }
        return total;
    }
};
