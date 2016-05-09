#ifndef FIND_MATRIX_H_INCLUDED
#define FIND_MATRIX_H_INCLUDED
#include<iostream>
#include<vector>
using namespace std;

class Offer{
public:
    bool find_matrix(vector<vector<int> > matrix,int target){
        int cloums = matrix.size();//hang shu
        if(cloums ==0){
            return false;
        }
        int rows = matrix[0].size();//lie shu

        int c = 0;
        int r = rows-1;
        while(r>=0 && c<=cloums-1){
            if(matrix[c][r]==target){
                cout<<"matrix["<<c<<"]["<<r<<"]"<<endl;
                return true;
            }
            else if(matrix[c][r] > target) r--;
            else c++;
        }
        return false;
    }
};


#endif // FIND_MATRIX_H_INCLUDED
/*
int main() {
	Offer o;
	vector<vector<int> > vvit = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	vvit.clear();
	for(auto i: vvit){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
	}
	cout<<o.find_matrix(vvit,100)<<endl;
	return 0;
}
*/
