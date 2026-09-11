class Solution {
public:
    int valid_count = 0;
    void backtrack(vector<int>& available, vector<int>& current) {
        if (current.size()==3) {
            if (current[2]% 2==0) valid_count++;
            return;
        }

        for (int digit = 0; digit <= 9; ++digit) {
            if (current.empty() && digit == 0) continue;

            if (available[digit] > 0) {
                available[digit]--;
                current.push_back(digit);

                backtrack(available, current);

                current.pop_back();
                available[digit]++;
            }
        }
    }

    int totalNumbers(std::vector<int>& digits) {
        vector<int> available(10, 0);
        for (int d : digits) available[d]++;

        vector<int> current;
        valid_count = 0;
        backtrack(available, current);
        
        return valid_count;
    }
};

