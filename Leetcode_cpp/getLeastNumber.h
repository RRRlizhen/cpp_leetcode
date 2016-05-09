#ifndef GETLEASTNUMBER_H_INCLUDED
#define GETLEASTNUMBER_H_INCLUDED
#include<vector>
#include<set>
using namespace std;

class Offer{
public:
    typedef std::multiset<int,greater<int> > intset;
    typedef std::multiset<int,greater<int> >::iterator iteratorset;

    void getLeastNumber(vector<int> nums,intset& leastNumber,int k){
        int length = nums.size();

        leastNumber.clear();
        if(length <k) return;
        for(auto i:nums){
            if(leastNumber.size()<(unsigned int)k){
                leastNumber.insert(i);
            }else{
                iteratorset itset = leastNumber.begin();
                if(i<*itset){
                    leastNumber.insert(i);
                    leastNumber.erase(leastNumber.begin());
                }
            }///if-else
        }///for
    }///end-function

    int findGreatestSumOfSubArray(int *data,int length){
        /**
            f(i):
        */
        if(data==nullptr || length<=0){
            return 0;
        }
        int fi = data[0];
        int Greatest = data[0];
        for(int i = 1;i<length;i++){
            if(fi>0){
                fi = fi+data[i];
            }else{
                fi = data[i];
            }
            Greatest = fi>Greatest? fi:Greatest;
        }
        return Greatest;
    }///end-function
};


#endif // GETLEASTNUMBER_H_INCLUDED
