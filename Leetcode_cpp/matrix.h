#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

/**********************************************
*Project:
*
*Author:lizhen
*email:lizhen_ok@aliyun.com
*
***********************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <climits>
#include <algorithm>
#include <bitset>
#include <queue>
#include <fstream>
using namespace std;

class A{
public:
    ofstream out;
    A(){
        out.open("out.xml");
    }
    ~A(){
        out.close();
    }
    /**
    1 2 3
    4 5 6
    7 8 9

    123 6 987 4
    */
    vector<int> _spiralOrder(vector<vector<int>>& matrix) {
        vector<int> re;
        if(matrix.size()==0)return re;
        help_sO(matrix,0,0,matrix.size(),matrix[0].size(),re);
        for(auto i:re) cout<<i<<" ";
        cout<<endl;
        return re;
    }
    void help_sO(vector<vector<int>>& m,int x,int y,int rows,int cloms,vector<int> &re){
        if(rows<=0 || cloms<=0) return ;

        ///first line
        for(int i = 0;i<cloms;i++){
            re.push_back(m[x][y+i]);
        }

        ///right colum
        for(int i = 1;i<rows-1;i++){
            re.push_back(m[x+i][y+cloms-1]);
        }

        ///down row
        if(rows>1){
            for(int i = cloms-1;i>=0;i--){
                re.push_back(m[x+rows-1][y+i]);
            }
        }

        ///left colum. Go up
        if(cloms>1){
            for(int i = rows-2;i>0;i--){
                re.push_back(m[x+i][y]);
            }
        }
        help_sO(m,x+1,y+1,rows-2,cloms-2,re);
    }

    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return vector<vector<int>>();
        vector<vector<int>> re(n,vector<int>(n,0));
        help_gM(re,0,n,n,1);
        for(auto i: re){
            for(auto j:i)cout<<j<<" ";
            cout<<endl;
        }
        cout<<endl;
        return re;
    }

    void help_gM(vector<vector<int>> &re,int level,int rows,int cols,int start){
        if(rows<=0 || cols<=0) return;

        for(int i = 0;i<cols;i++){
            re[level][level+i] = start++;
        }

        for(int i = 1;i<rows-1;i++){
            re[level+i][level+cols-1] = start++;
        }


        if(rows>1){
            for(int i = cols-1;i>=0;i--){
                re[level+rows-1][level+i] = start++;
            }
        }

        if(cols>1){
            for(int i = rows-2;i>0;i--){
                re[level+i][level] = start++;
            }
        }
        help_gM(re,level+1,rows-2,cols-2,start);
    }

    void setZeroes(vector<vector<int>> &m){
        int c_len = m.size();
        int r_len = m[0].size();
        vector<bool> a(c_len,false);
        vector<bool> b(r_len,false);

        for(int i = 0;i<c_len;i++){
            for(int j = 0;j<r_len;j++){
                if(m[i][j]==0){
                    a[i] = true;
                    b[j] = true;
                }
            }
        }///for

        for(int i = 0;i<c_len;i++){
            if(a[i]){
                for(int k = 0;k<r_len;k++) m[i][k] = 0;
            }
        }
        for(int j = 0;j<r_len;j++){
            if(b[j]){
                for(int k = 0;k<c_len;k++) m[k][j] = 0;
            }
        }
    }

    bool _searchMatrix(vector<vector<int>>& m, int t) {
        if(m.empty() || m[0][0]>t)return false;
        int rows = m.size();
        int colums = m[0].size();
        if(m[rows-1][colums-1]<t) return false;
        int low = 0;
        int high = rows-1;

        int mid = (low+high)/2;
        while(low<=high){
            if(m[mid][0]>t){
                high = mid-1;
            }else if(m[mid][0]<t){
                low = mid+1;
            }else{
                return true;
            }
            mid = (low+high)/2;
        }
        cout<<"-mid:"<<mid<<endl;

        low = 0;
        high = colums-1;
        int mmid = (low+high)/2;
        while(low<=high){
            if(m[mid][mmid]>t) high = mmid-1;
            else if(m[mid][mmid]<t) low=mmid+1;
            else return true;

            mmid = (low+high)/2;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& m, int t) {
        if(m.empty() || m[0][0]>t) return false;
        int row = m.size();
        int colum = m[0].size();
        if(m[row-1][colum-1]<t) return false;
        int i = row-1;
        int j = 0;
        while(i>=0 && j<colum){
            if(t > m[i][j]) j++;
            else if(t < m[i][j]) i--;
            else return true;
        }
        return false;
    }

    void gameOfLife(vector<vector<int>>& b) {
        if(b.empty()) return ;
        int row = b.size();
        int colum = b[0].size();
        vector<vector<int>> tmp(row,vector<int>(colum,0));
        copy(b.begin(),b.end(),tmp.begin());
        for(int i = 0;i<row;i++){
            for(int j = 0;j<colum;j++){
               int live = 0;
               if(j>0 && tmp[i][j-1]) live++;
               if(j<colum-1 && tmp[i][j+1]) live++;

               if(i>0 && tmp[i-1][j]) live++;
               if(i<row-1 && tmp[i+1][j]) live++;

               if(i>0 && j>0 && tmp[i-1][j-1]) live++;
               if(i>0 && j<colum-1 && tmp[i-1][j+1]) live++;

               if(i<row-1 && j>0 && tmp[i+1][j-1])  live++;
               if(i<row-1 && j<colum-1 && tmp[i+1][j+1]) live++;

               bool state = tmp[i][j]==1?true:false;
               if(state && live<2){
                    b[i][j] = 0;
               }else if(state && (live==2 || live==3)){
                    b[i][j] = 1;
               }else if(state && live>3){
                    b[i][j] = 0;
               }else if(!state && live==3){
                    b[i][j] = 1;
               }
            }
        }///for
    }


    ///
    string doubleConverToString(double d){
        ostringstream os;
        if(os << d) return os.str();
        return "invalid conversion";
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> re;
        if(nums.empty()) return re;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            string s = doubleConverToString(nums[i])+"->";
            int j = i+1;
            while(j<n && nums[j-1]==nums[j]){
                j++;
            }
        }
    }


    /**
    012 3 4567
    701 2 3456
    670 1 2345
    567 0 1234
    456 7 0123
    345 6 7012
    234 5 6701
    123 4 5670

    可以看到数组旋转的各种情况，mid将数组分为左右两部分

nums[mid]<nums[right]，那么右边的部分是有序的

　　因为右边部分有序，那么我可以在有序的部分判断：是否存在target值;如果有序的部分不存在target，那么在数组的左边部分寻找。

　　　　我觉得这左右两部分的判断条件是不等价的，我们只能用排除法，现在有把握的部分搜索，这部分能找到更好。不能找到呢，换成另外的部分。

如果nums[mid] > nums[left]，那么左边的部分是有序的。

　　我们再在有序的部分寻找。。。。。
    */

    int search(const vector<int> &nums,int target){
        if(nums.size()==0)return -1;
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<nums[right]){
                ///the right part is sorted
                if(nums[mid]<target && nums[right]>=target)
                    left = mid+1;
                else
                    right = mid-1;
            }else{
                ///the left part is sorted
                if(nums[mid]>target && nums[left]<=target)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }///while
        return -1;
    }


    /**
    1. 1.. 1... 2 3 4 5
    5 1. 1.. 1... 2 3 4
    4 5 1. 1.. 1... 2 3
    3 4 5 1. 1.. 1... 2
    2 3 4 5 1. 1.. 1...
    1... 2 3 4 5 1. 1..
    1.. 1... 2 3 4 5 1.
    */
    bool search_2(vector<int> &nums,int target){
        if(nums.size()==0) return false;
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<nums[right]){
                if(nums[mid]<target && target <=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }else if(nums[mid]>nums[right]){
                if(target >=nums[left] && target<=nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }else{
                right--;
            }
        }
        return false;
    }


    int findMin_1(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int left = 0;
        int right = nums.size()-1;
        int mark = right;
        while(left<=right){
            if(left+1==right){
                mark = nums[left]<nums[mark]?left:mark;
                mark = nums[right]<nums[mark]?right:mark;
                break;
            }
            int mid = (left+right)/2;
            if(nums[mid]<nums[right]){
                if(nums[mid]<nums[mark])
                    mark = mid;
                right = mid-1;
            }else{
                if(nums[left]<nums[mark])
                    mark = mid;
                left = mid+1;
            }
        }///while
        return nums[mark];
    }


    int findMin_2(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int left = 0;
        int right = nums.size()-1;
        int mark = right;
        while(left<=right){
            if(left+1==right){
                mark = nums[left]<nums[mark]?left:mark;
                mark = nums[right]<nums[mark]?right:mark;
                break;
            }
            int mid = (left+right)/2;
            if(nums[mid]<nums[right]){
                if(nums[mid]<nums[mark])
                    mark = mid;
                right = mid-1;
            }else if(nums[mid]>nums[right]){
                if(nums[left]<nums[mark])
                    mark = mid;
                left = mid+1;
            }else{
                right--;
            }
        }///while

        if(left<(int)nums.size())
            mark = nums[left]<nums[mark]?left:mark;
        if(right>0)
            mark = nums[right]<nums[mark]?right:mark;
        return nums[mark];
    }


    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<nums[mid+1])
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }

     int findPeakElement_1(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }

    ///
    void degui(int n){
        out<<"<degui>"<<endl;
        if(n>0){
            n--;
            degui(n);
        }
        out<<"</degui>"<<endl;
    }

    ///
    int ladderLength(string beginWord, string endWord,
                unordered_set<string>& wordList) {
        unordered_map<string,int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while(!q.empty()){
            string word = q.front();
            q.pop();
            for(int i = 0;i<(int)word.size();i++){
                string newWord = word;
                for(char ch = 'a';ch<='z';++ch){
                    newWord[i] = ch;
                    if(newWord==endWord) return m[word]+1;
                    if(wordList.find(newWord)!=wordList.end() &&
                        m.find(newWord)==m.end()){
                        cout<<"q.size()="<<q.size()<<endl;
                        cout<<"word->"<<word<<endl;
                        cout<<"newWord->"<<newWord<<endl<<endl;
                        q.push(newWord);
                        m[newWord] = m[word]+1;
                    }
                }///for
            }///for
        }
        return 0;
    }


    ///
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        dict.insert(end);
        vector<string> p;
        p.push_back(start);
        queue<vector<string> > paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = path.size();
                if (level > minLevel) break;
            }
            string last = path.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (dict.find(newLast) != dict.end()) {
                        words.insert(newLast);
                        vector<string> nextPath = path;
                        nextPath.push_back(newLast);
                        if (newLast == end) {
                            res.push_back(nextPath);
                            minLevel = level;
                        } else paths.push(nextPath);
                    }
                }
            }
        }
        return res;
    }



    ///
    void help_sub2(vector<vector<int>> &re,vector<int> &path,
            vector<int> &nums,vector<int>::iterator beg){
        if(beg < nums.end())
            out<<"<help_sub2 :"<<*beg<<">"<<endl;
        re.push_back(path);
        for(auto i = beg;i < nums.end();i++){
            if(i!=beg && *i==*(i-1))continue;
            path.push_back(*i);
            help_sub2(re,path,nums,i+1);
            path.pop_back();
        }
        if(beg < nums.end())
            out<<"</help_sub2 :"<<*beg<<">"<<endl;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<vector<int>> re;
        help_sub2(re,path,nums,nums.begin());
        for(auto i:re){
            for(auto j:i)cout<<j<<" ";
            cout<<"-"<<endl;
        }
        return re;
    }


    ///
    void test(){
        cout<<"begin"<<endl;
        vector<int> c = {1,2,2};
        vector<vector<int>> re = subsetsWithDup(c);
        cout<<endl<<"end"<<endl;
    }
};

#endif // MATRIX_H_INCLUDED
