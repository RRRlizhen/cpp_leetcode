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
#include <algorithm>
#include <sstream>
#include <list>
#include <stdio.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x=0): val(x),next(nullptr) {}
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

class TrieNode{
public:
    ///init
    TrieNode *vnext[26];
    int value;
    TrieNode(){
        memset(vnext,0,sizeof(nullptr)*26);
        value = -1;
    }
};

class Trie{
public:
    TrieNode *root;
public:
    Trie(){
       root = new TrieNode;
    }
    ~Trie(){
        ///
    }

    ///insert
    void insert(string s){
        TrieNode *tnode = root;
        int i = 0;
        int n = s.size();
        while(i<n){
            if(tnode->vnext[s[i]-'a'] != nullptr){
                tnode = tnode->vnext[s[i]-'a'];
                i++;
            }else{
                break;
            }
        }

        while(i<n){
            tnode->vnext[s[i]-'a'] = new TrieNode();
            tnode = tnode->vnext[s[i]-'a'];
            i = i+1;
        }
        tnode->value = 1;
    }

    ///returns if the word is in the trie
    bool search(string key){
        TrieNode *tnode = root;
        int n = key.size();
        for(int i = 0;i<n;i++){
            if(tnode->vnext[key[i]-'a'] == nullptr){
                return false;
            }else{
                tnode = tnode->vnext[key[i]-'a'];
            }
        }
        if(tnode->value > 0){
            return true;
        }else{
            return false;
        }
    }

    ///returns if there is any word in the trie
    ///that starts with the given prefix
    bool startsWith(string prefix){
        TrieNode *tnode = root;
        int n = prefix.length();
        for(int i = 0;i<n;i++){
            if(tnode->vnext[prefix[i]-'a'] ==nullptr){
                return false;
            }else{
                tnode = tnode->vnext[prefix[i] - 'a'];
            }
        }
        return true;
    }
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
        for(int i = 1;i<(int)nums.size();i++){
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
        for(int i = 0;i<(int)nums.size();i++){
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
        for(int i = 0;i<(int)dp.size();i++){
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
    int minCost1(string s1,string s2){
        if(s1.empty()) return s2.size();
        if(s2.empty()) return s1.size();
        int m = s1.size();
        int n = s2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<m+1;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j<n+1;j++){
            dp[0][j] = j;
        }

        for(int i = 1;i<m+1;i++){
            for(int j = 1;j<n+1;j++){
                /**
                    s1 yyyyd
                    s2 xxxx
                    ---------
                    s1 yyyy
                    s2 xxxxi
                    ---------
                    s1 yyyyr
                    s2 xxxxr
                    ---------
                    s1 yyyyo
                    s2 xxxxo
                */
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int a1 = dp[i-1][j];
                    int a2 = dp[i-1][j-1];
                    int a3 =  dp[i][j-1];
                    dp[i][j] = min(min(a1,a2),a3)+1;
                }///if-else
            }
        }///
        return dp[m][n];
    }


    ///
    void help_combinationSum(vector<int> &c,const int t,vector<vector<int>> &re,vector<int> &path,
                int i){
        ///

        int sum = accumulate(path.begin(),path.end(),0);
        if(t == sum){
            sort(path.begin(),path.end());
            re.push_back(path);
            return;
        }
        if(t < sum){
            return;
        }

        if(i>=(int)c.size()) return ;
        ///not select the c[i]
        help_combinationSum(c,t,re,path,i+1);
        path.push_back(c[i]);
        help_combinationSum(c,t,re,path,i+1);
        path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> re;
        vector<int> path;
        sort(c.begin(),c.end());///this is very import!!!!!

        if(c.empty()) return re;
        help_combinationSum(c,t,re,path,0);
        for(auto i:re){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<endl;
        }
        return re;
    }



    ///
    void help_c(vector<int> &c,vector<vector<int>> &re,vector<int> &path,int gap,size_t i){
        if(gap==0){
            re.push_back(path);
            return;
        }

        int prev = -1;
        for(;i<c.size();i++){
            if(c[i]==prev){
                continue;
            }
            if(gap<c[i]) return;
            prev = c[i];
            path.push_back(c[i]);
            help_c(c,re,path,gap-c[i],i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> re;
        vector<int> path;
        sort(c.begin(),c.end());

        if(c.empty()) return re;
        help_c(c,re,path,t,0);
        for(auto i:re){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<endl;
        }
        return re;
    }

    ///
    void help_g(const int n,string &path,vector<string> &re,
                   int l,int r){
        if(l==n){
            string s(path);
            re.push_back(s.append(n-r,')'));
            return;
        }

        path.push_back('(');
        help_g(n,path,re,l+1,r);
        path.pop_back();

        if(r<l){
            path.push_back(')');
            help_g(n,path,re,l,r+1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> re;
        string path;
        if(n>0) help_g(n,path,re,0,0);
        for(auto i:re){
            cout<<i<<"\n";
        }
        return re;
    }


    ///
    void help_res(string s,vector<string> &re,vector<string> &path,size_t start){
        if(path.size() == 4 && start ==s.size()){
            ///find a solution
            re.push_back(path[0]+'.'+path[1]+'.'+path[2]+'.'+path[3]);
            return;
        }
        if(s.size() - start > (4-path.size())*3){
            return ;///s:xxxsss sss sss sss
                    ///p:p0,
        }
        if(s.size() - start < (4-path.size())){
            return;
        }

        int num = 0;
        for(size_t i = start;i<start+3;i++){
            num = num*10+(s[i]-'0');

            if(num<0 || num>255) continue;
            path.push_back(s.substr(start,i-start+1));
            help_res(s,re,path,i+1);
            path.pop_back();

            if(num==0) break;///don't have 012.12.12.12 , but have 0.0.0.0
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> re;
        vector<string> path;/// store the immediate result
        help_res(s,re,path,0);
        for(auto i: re){
            cout<<i<<"\n";
        }
        return re;
    }


    ///
    bool isPalindrome(int x) {
        if(x==0) return true;

        string str;
        ostringstream os;
        if(os << x){
            str = os.str();
        }
        int r = str.size()-1;
        int l = 0;
        while(l<r){
            if(str[l++]==str[r--]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }


    ///
    void help_partition(string s,vector<vector<string>> &re,vector<string> &path,int start){
        if(start==(int)s.size()){
            re.push_back(path);
            return;
        }
        for(int i = start;i<(int)s.size();i++){
            if(is_palindrome(s,start,i)){
                string t = s.substr(start,i-start+1);
                path.push_back(t);
                help_partition(s,re,path,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> _partition(string s){
        vector<vector<string>> re;
        vector<string> path;
        if(!s.empty()){
            help_partition(s,re,path,0);
        }
        for(auto i:re){
            for(auto j: i){
                cout<<j<<" ";
            }cout<<"\n";
        }
        return re;
    }



    ///
    bool is_palindrome(string &s,int l,int r){
        while(l<r){
            if(s[l++]==s[r--]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        /**
            dp[i] = min{dp[j+1]+1, i<=j && j<n && s[i,j] is a palindrome }
        */
        if(s.empty()) return 0;
        int n = s.size();
        int dp[n+1];
        bool pa[n][n];
        memset(pa,0,sizeof(pa));
        memset(dp,false,sizeof(dp));

        dp[n] = -1;
        for(int i=n-1;i>=0;i--){
            dp[i] = INT_MAX;
            for(int j = i;j<n;j++){
                if(s[i]==s[j] && ((j-i<2) || pa[i+1][j-1])){
                    pa[i][j] = true;
                    dp[i] = min(dp[i],dp[j+1]+1);
                }
            }
        }///for-for
        return dp[0];
    }

    void test_memset(){
        ///============
        int *d;
        d = new int[10];
        memset(d,-1,sizeof(int)*10);
        for(int i = 0;i<10;i++){
            cout<<d[i]<<" ";
        }cout<<endl;
        delete[] d;
        ///==============
        int **a;
        a = new int*[10];
        for(int i = 0;i<10;i++){
            a[i] = new int[5];
            memset(a[i],-1,sizeof(int)*5);
        }
        for(int i = 0;i<10;i++){
            for(int j = 0;j<5;j++){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
        for(int i = 0;i<10;i++){
            delete[] a[i];
        }
        delete[] a;

        ///====================
        int ***c;
        c = new int**[10];
        for(int i = 0;i<10;i++){
           c[i] = new int*[7];
           for(int j = 0;j<7;j++){
             c[i][j] = new int[5];
             memset(c[i][j],-1,sizeof(int)*5);
           }
        }

        for(int i = 0;i<10;i++){
            for(int j = 0;j<7;j++){
                for(int k = 0;k<5;k++){
                    cout<<"i-j-k"<<i<<j<<k<<"~"<<c[i][j][k]<<" ";
                }cout<<endl;
            }cout<<endl<<endl;
        }
        ///===========

        for(int i = 0;i<10;i++){
            for(int j = 0;j<7;j++){
                delete[] c[i][j];
            }
            delete[] c[i];
        }
        delete[] c;
        cout<<"destoryed done!"<<endl;
    }


    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> candTimes;
        vector<int> re;
        for(int i = 0;i<n;i++){
           if(candTimes.find(nums[i])!=candTimes.end()){
                candTimes[nums[i]]++;
           }else{
                if(candTimes.size()<3){
                    candTimes[nums[i]]++;
                }else if(candTimes.size()==3){
                    for(unordered_map<int,int>::iterator mit = candTimes.begin();
                        mit!=candTimes.end();mit++){
                        if(mit->second==1){
                            candTimes.erase(mit);
                        }else{
                            mit->second--;
                        }
                    }
                }
           }///if-else
        }///for

        ///verify the solution
        for(unordered_map<int,int>::iterator mit = candTimes.begin();
            mit!=candTimes.end();mit++){
            mit->second = 0;
        }

        for(int i = 0;i<n;i++){
            if(candTimes.find(nums[i])!=candTimes.end()){
                candTimes[nums[i]]++;
            }
        }


        for(unordered_map<int,int>::iterator mit = candTimes.begin();
            mit!=candTimes.end();mit++){
            if(mit->second>(n/3)){
                re.push_back(mit->first);
            }
        }
        return re;
    }

    void test(ListNode *head){
        cout<<"begin test...\n";
        ListNode n1(6),n2(2),n3(4),n4(3),n5(5),n6(1);
        n1.next = &n2;n2.next = &n3;n3.next = &n4;n4.next = &n5;n5.next = &n6;
        //ListNode *head2 = &n1;
        //vector<int> c = {1,2,0,4,5,0,6,7,8,9,9,9,9,9,9,0,0,0,0,0};
        vector<int> c = {1,1,1,3,3,2,2,2};
        cout<<"c.size()="<<c.size()<<endl;
        vector<int> re;
        re = majorityElement(c);
        for(auto i:re){
            cout<<i<<" ";
        }cout<<endl;

        cout<<endl<<"end test...\n";
    }
};

#endif // MYDP_H_INCLUDED
