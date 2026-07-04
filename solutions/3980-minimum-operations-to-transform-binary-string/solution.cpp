class Solution {
public:
    int minOperations(string s1, string s2) {
        int n= s1.size();
        if(n==1){
            if(s1==s2) return 0;
            if(s1[0]=='1'&&s2[0]=='0') return -1;
            return 1;
        }
        int ops =0;
        int i=0;
        while(i<n){
            if(s1[i]=='0'&&s2[i]=='1'){
                ops+=1;
                i++;
            } else if(s1[i]=='1'&&s2[i]=='0'){
                int k=i;
                while(k<n&&s1[k]=='1'&&s2[k]=='0')k++;
                int x=k-i;
                ops+=(x%2==0) ? x/2 :(x+3)/2;
                i =k;
            } else i++;
        }
        return ops;
    }
};
