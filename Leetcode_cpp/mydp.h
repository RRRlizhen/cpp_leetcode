#ifndef MYDP_H_INCLUDED
#define MYDP_H_INCLUDED

/**********************************************
*Project:TinyThreadPool
*
*Author:lizhen
*email:lizhen_ok@aliyun.com
*
***********************************************/
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr) {}
};
struct RandomListNode{
        int label;
        RandomListNode *next,*random;
        RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class NumArray {
public:
    NumArray(vector<int> &nums):data(nums){}

    int sumRange(int i, int j) {
        int re = 0;
        while(i<=j){
            re += data[i++];
        }
        return re;
    }
    vector<int> data;
};


class DP{
public:
    void showList(ListNode *head)
    {
        while(head)
        {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    void showList(RandomListNode *head){
        while(head){
            cout<<head->label<<" ";
            head = head->next;
        }cout<<endl;
    }

    ///
    void showTree(TreeNode *root){
        if(root){
            cout<<root->val<<" ";
            showTree(root->left);
            showTree(root->right);
        }
    }
    void showTreeInorder(TreeNode *root){
        if(root->left) showTreeInorder(root->left);
        cout<<root->val<<" ";
        if(root->right) showTreeInorder(root->right);

    }


    ///
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int ret = 1;
        while(n>4){
            ret *= 3;
            n -= 3;
        }
        return ret*n;
    }

    ///
    vector<int> countBits(int num) {
        vector<int> re;
        for(int i = 0;i<=num;i++){
            int c = 0;
            unsigned int k = 1;
            while(k){
                if(k&i) c++;
                k = k<<1;
            }
            re.push_back(c);
        }
        return re;
    }

    ///
    int dp_coinChange(vector<int> & coins,int amount){
        if(amount==0) return 0;
        vector<int> re;
        int n = amount;///
        int m = coins.size();

        ///we need n+1 rows as the table is constructed in bottom up manner
        /// using the base case 0 value case (n=0)
        int table[n+1][m];

        ///fill the enteries for 0 value case (n = 0)
        for(int i = 0;i<m;i++){
            table[0][i] = 1;
        }

        ///fill rest the table enteries in bottom up manner
        for(int i = 1;i< n+1;i++){
            for(int j = 0;j<m;j++){
                ///count of solutions including S[j]
                int x = (i-coins[j] >=0)? table[i-coins[j]][j]:0;
                ///count of solutions excluding S[j]
                int y = (j >= 1)?table[i][j-1]:0;
                ///total count
                table[i][j] = x+y;
            }cout<<endl;
        }
        return table[n][m-1]==0? -1:table[n][m-1];
    }


    ///
    bool isPalindrome(const string &s, int start, int end){
        while(start<end && s[start]==s[end]){
            ++start;
            --end;
        }
        return start >= end;
    }
    void dfs(string &s,vector<string> &path,
        vector<vector<string>> &re,size_t prev,size_t start){
        if(start == s.size()){
            if(isPalindrome(s,prev,start-1)){
                path.push_back(s.substr(prev,start-prev));
                re.push_back(path);
                path.pop_back();
            }
            return;
        }

        ///don't cut
        dfs(s,path,re,prev,start+1);
        if(isPalindrome(s,prev,start-1)){
            path.push_back(s.substr(prev,start-prev));
            dfs(s,path,re,start,start+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s){
        vector<vector<string>> re;
        vector<string> path;///
        dfs(s,path,re,0,1);

        return re;
    }


    ///
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        int maxd[nums.size()] = {1};
        int mind[nums.size()] = {1};
        maxd[0] = nums[0];
        mind[0] = nums[0];
        int re = INT_MIN;
        for(int i = 1;i<(int)nums.size();i++){
            int a = max(max(maxd[i-1]*nums[i],mind[i-1]*nums[i]),nums[i]);
            int b = min(min(maxd[i-1]*nums[i],mind[i-1]*nums[i]),nums[i]);
            maxd[i] = a;
            mind[i] = b;
        }

        for(int i = 0;i<(int)nums.size();i++){
            if(re<maxd[i]) re = maxd[i];
        }
        return re;
    }


    ///returns the count of ways we can sum s[0..m-1] coins to get sum n
    void help_DFS_coinChange(vector<int>& s,int m,int n,vector<int> re,int &small){
        /// if n is 0 then this is 1 solution (do not include any coin)
        if(n==0){
            ///for(auto i: re){cout<<i<<" ";}cout<<"-"<<endl;
            small = (int)re.size()<small? re.size() :small;
            return;
        }
        /// if n is less than 0 then no solution exists
        if(n<0) return;
        /// if there are no coins and n is greater than 0, there no solution exist
        //if(m=0 && n>=1) return ;
        if(m<=0) return ;
        ///(i) excluding S[m-1] (ii) including S[m-1]

        help_DFS_coinChange(s,m-1,n,re,small);
        re.push_back(s[m-1]);
        help_DFS_coinChange(s,m,n-s[m-1],re,small);
    }

    int _coinChange(vector<int>& coins, int amount){
        if(amount==0) return 0;
        vector<int> re;
        int small = INT_MAX;
        help_DFS_coinChange(coins,coins.size(),amount,re,small);
        return small==INT_MAX? -1 :small;
    }


    ///
    int  coinChange(vector<int>& coins, int amount){
        ///dp[i] = min{dp[i-c1],dp[i-c2],dp[i-c3],dp[i-c4]...}+1
        if(amount == 0) return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<amount+1;i++){
            for(int j = 0;j<(int)coins.size();j++){
                if(i-coins[j]>=0){
                    dp[i] = min(dp[i],dp[i-coins[j]]);
                }
            }
            int tmp = (dp[i]==INT_MAX)? INT_MAX: dp[i]+1;
            dp[i] = tmp;
        }
        return dp[amount]==INT_MAX? -1: dp[amount];
    }

    int lengthOfLIS(vector<int>& nums) {
        ///dp[i] = max{dp[j]+1 | dp[j]<dp[i], 0<= j <i}  or 1
        if(nums.empty()){
            return 0;
        }
        vector<int> dp(nums.size());
        dp[0] = 1;
        for(int i = 1;i<nums.size();i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int re = INT_MIN;
        for(auto i: dp){
            re = i>re? i: re;
        }
        return re;
    }

    ///
    void getLIS(vector<int> &nums,vector<int> &dp){
        dp[0] = 1;///dp.size>=1
        for(int i = 0;i<nums.size();i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
    }
    void generateLIS(vector<int> &nums){
        vector<int> re;
        if(nums.empty()) return;
        vector<int> dp(nums.size());
        getLIS(nums,dp);
        int m = 0;
        for(int i = 0;i<dp.size();i++){
            m = dp[i]>dp[m]? i:m;
        }
        re.push_back(nums[m]);
        for(int i = m-1;i>=0;i--){
            if(nums[i]<nums[m] && dp[i]==(dp[m]-1)){
                re.push_back(nums[i]);
                m = i;
            }
        }
        reverse(re.begin(),re.end());
        for(auto i:re){
            cout<<i<<" ";
        }cout<<endl;
    }

    int uniquePaths(int m,int n){
        if(m==0 || n==0) return 0;
        int dp[m][n];
        for(int i = 0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j = 0;j<n;j++){
            dp[0][j] = 1;
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        return dp[m-1][n-1];
    }



    ///
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        if(ob.empty()) return 0;
        int m = ob.size();
        int n = ob[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<m;i++){
            if(ob[i][0]==1){
                break;
            }
            dp[i][0] = 1;
        }
        for(int j = 0;j<n;j++){
            if(ob[0][j]==1){
                break;
            }
            dp[0][j] = 1;
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(ob[i][j]==1){
                    continue;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }



    ///
    void test(ListNode *head){
        cout<<"begin test...\n";
        ListNode n1(6),n2(2),n3(4),n4(3),n5(5),n6(1);
        n1.next = &n2;n2.next = &n3;n3.next = &n4;n4.next = &n5;n5.next = &n6;
        ListNode *head2 = &n1;
        showList(head2);cout<<endl;
        vector<vector<int>> c = {
                                {0,0,0},
                                {0,1,0},
                                {0,0,0}};
        cout<<uniquePathsWithObstacles(c);


        cout<<endl<<"end test...\n";
    }
};

#endif // MYDP_H_INCLUDED
