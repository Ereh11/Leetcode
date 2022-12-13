/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        long long st = 1, en = INT_MAX, mid, pike;
        
        while(st <= en)
        {
            mid = ((st + en) >> 1), pike = guess(mid);;
            if(!pike) break;
            else if(pike > 0) st = mid + 1;
            else en = mid - 1;
        }
        return mid;
    }
};