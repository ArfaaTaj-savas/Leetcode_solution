class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;

        int candies = 1;
        int up = 0, down = 0, peak = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up + 1;
                down = 0;
                candies += peak;
            }
            else if (ratings[i] == ratings[i - 1]) {
                up = down = 0;
                peak = 1;
                candies += 1;
            }
            else {
                up = 0;
                down++;
                candies += down;

                if (down >= peak)
                    candies++;
            }
        }

        return candies;
    }
};