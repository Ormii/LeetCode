class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int newBottles = numBottles, emptyBottles = 0;
        while(newBottles + emptyBottles >= numExchange)
        {
            int drinkBottles = newBottles;
            ans += drinkBottles;
            emptyBottles += drinkBottles;

            newBottles = emptyBottles/numExchange;
            emptyBottles = emptyBottles%numExchange;
        }

        ans += newBottles;

        return ans;
    }
};