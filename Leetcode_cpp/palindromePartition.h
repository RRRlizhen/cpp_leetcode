#ifndef PALINDROMEPARTITION_H_INCLUDED
#define PALINDROMEPARTITION_H_INCLUDED
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<string>> partition(string s){
        vector<vector<string>> result;

        vector<string> path;/// one partition plan
        dfs(s,path,result,0,1);
        return result;
    }

    void dfs(string &s ,vector<string>& path,
        vector<vector<string>> &result, size_t prev, size_t start){

    }
}


#endif // PALINDROMEPARTITION_H_INCLUDED
