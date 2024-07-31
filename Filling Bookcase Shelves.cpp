class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int answer = 0;
        vector<vector<int>> memo(books.size(), vector<int>(shelfWidth + 1));
        answer = recv(books,shelfWidth, memo, 0, shelfWidth, 0);
        return answer;
    }

    int recv(vector<vector<int>>& books, int shelfWidth, 
    vector<vector<int>>& memo, int i, int remainShelfWidth,
    int maxHeight)
    {
        vector<int> currentBook = books[i];
        int maxHeightUpdated = max(maxHeight, currentBook[1]);
        if(i == books.size() - 1)
        {
            if(remainShelfWidth >= currentBook[0]) return maxHeightUpdated;
            return maxHeight + currentBook[1];
        }

        if(memo[i][remainShelfWidth] != 0)
            return memo[i][remainShelfWidth];
        
        int option1Height = maxHeight + recv(books, shelfWidth, memo, i + 1, shelfWidth - currentBook[0], currentBook[1]);
        if(remainShelfWidth >= currentBook[0])
        {
            int option2Height = recv(books, shelfWidth, memo, i + 1, remainShelfWidth - currentBook[0], maxHeightUpdated);
            memo[i][remainShelfWidth] = min(option1Height, option2Height);

            return memo[i][remainShelfWidth];
        }

        memo[i][remainShelfWidth] = option1Height;
        return memo[i][remainShelfWidth];
    }
};