#ifndef LENGTHOFLONGESTSUBSTRING_H_INCLUDED
#define LENGTHOFLONGESTSUBSTRING_H_INCLUDED
#include <vector>
using namespace std;
class Solution{
/**
    "abcabcbb"-->"abc" length =3
    "bbbbb"-->"b" length = 1

    0 1 2 3 4 5 6 7
    q p x r j x k l
        ^     ^
    ^start    i
*/
public:
    int lengthOfLongestSubstring(string s){
        int length = s.size();
        vector<int> record(255,-1);
        int start = 0;//record the start location of current string

        int max_len = 0;
        for(int i = 0;i<length;i++){
            if(record[s[i]] >= start){
                max_len = max(max_len,i-start);
                start = record[s[i]]+1;
            }
            record[s[i]] = i;
        }///for

        return max(max_len,length-start);
    }
};


#endif // LENGTHOFLONGESTSUBSTRING_H_INCLUDED
