/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int answer = 0;
        int len = strlen(buf);
        int count = 0;
        while((count = read4(buf)) != 0)
        {
            buf += count;
            answer += count;
        }

        return min(answer,n);
    }
};