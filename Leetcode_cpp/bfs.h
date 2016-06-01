/**********************************************
*Project:
*
*Author:lizhen
*email:lizhen_ok@aliyun.com
*
***********************************************/
#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct state_t {
	string word;
	int level;
	state_t() {
		word = "";
		level = 0;
		}
	state_t(const string &word,int level) {
		this->word = word;
		this->level = level;
		}

	bool operator==(const state_t &other) const {
		return this->word  == other.word;
		}
	};
namespace std {
	template<>
	struct hash<state_t> {
		public:
			size_t operator()(const state_t &s)const {
				return str_hash(s.word);
				}
		private:
			std::hash<std::string> str_hash;
		};
	}

class A{
public:
    int ladderLength(const string &start,const string &end,
        const unordered_set<string> &dict){
        queue<state_t> q;
        unordered_set<state_t> visited;

        auto state_is_valid = [&](const state_t &s){
            return dict.find(s.word)!=dict.end()||s.word==end;
        };

        auto state_is_target = [&](const state_t &s){
            return s.word == end;
        };
        auto state_extend = [&](const state_t &s){
            unordered_set<state_t> result;

            for(size_t i = 0;i<s.word.size();i++){
                state_t new_state(s.word,s.level+1);
                for(char c = 'a';c<= 'z';c++){
                    ///
                    if(c == new_state.word[i]) continue;
                    swap(c,new_state.word[i]);
                    if(state_is_valid(new_state) &&
                        visited.find(new_state)==visited.end()){
                        result.insert(new_state);
                    }
                    swap(c,new_state.word[i]);
                }
            }
            return result;
        };

        state_t start_state(start,0);
        q.push(start_state);
        visited.insert(start_state);
        while(!q.empty()){
            const auto state = q.front();
            q.pop();

            if(state_is_target(state)){
                return state.level+1;
            }

            const auto &new_states = state_extend(state);
            for(const auto &new_state: new_states){
                q.push(new_state);
                visited.insert(new_state);
            }
        }
        return 0;
    }
};

struct huge_data{
    char *content;
    unsigned sz;
    huge_data():content(0),sz(0){
        cout<<this<<"->huge_data()"<<endl;
    }

    huge_data(unsigned sz):content(new char[sz]),sz(sz){
        cout<<this<<"->huge_data("<<sz<<")"<<endl;
    }

    huge_data(huge_data const &h):content(new char[h.sz]),sz(h.sz){
        copy(h.content,h.content+sz,content);
        cout<<this<<"->huge_data("<<&h<<")"<<endl;
    }

    huge_data &operator=(huge_data const &h){
        if(&h == this) return *this;
        if(content) delete[] content;

        content = new char[h.sz];
        copy(h.content,h.content+sz,content);
        sz = h.sz;
        cout<<this<<"->operator=("<<&h<<")"<<endl;
        return *this;
    }

    ///move-copy constructor
    ///move-assignment constructor
    huge_data(huge_data &&r):content(0),sz(0){
        swap(r);
        cout<<this<<"->huge_data("<<&r<<")rr"<<endl;
    }
    huge_data& operator=(huge_data &&r){
        if(content) delete[] content;
        sz = 0;
        swap(r);
        cout<<this<<"->operator=("<<&r<<")rr"<<endl;
        return *this;
    }

    void swap(huge_data &r){
        using std::swap;
        swap(content,r.content);
        swap(sz,r.sz);
    }

    ~huge_data(){
        if(content){
            delete[] content;
        }
    }
};

huge_data prepare_data(unsigned sz){
    huge_data h(sz);
    memset(h.content,'a',sizeof(char)*sz);
    return h;
}


#define MAX_NUM_NODE 10
class MatrixUDG{
public:
    char mVexs[MAX_NUM_NODE];
    int mVexNum;///number of node
    int mEdgNum;///number of edge
    int mMatrix[MAX_NUM_NODE][MAX_NUM_NODE];
    int prev[MAX_NUM_NODE];
    int dist[MAX_NUM_NODE];
    int source;
    int target;

    ///create the Graph by the hand
    MatrixUDG(){
        init();
        cout<<"The MAX node number is 10"<<endl;
        cout<<"input vertex number,->";
        cin>>mVexNum;
        cout<<"input edge number,->";
        cin>>mEdgNum;

        if(mVexNum<1 || mEdgNum<1 || (mEdgNum>(mVexNum*(mVexNum)))){
            cout<<"input error: invalid parameter!"<<endl;
            return;
        }

        ///init the node
        for(int i = 0;i<mVexNum;i++){
            cout<<"vextex("<<i<<")->";
            mVexs[i] = readChar();
        }
        cout<<"ok,Now initalized the node. Done"<<endl;

        ///init the edges
        for(int i = 0;i<mEdgNum;i++){
            cout<<"edge("<<i<<")->";
            char ch1 = readChar();
            char ch2 = readChar();
            int p1 = getPosition(ch1);
            int p2 = getPosition(ch2);

            if(p1==-1 || p2==-1){
                cout<<"input error: invalid edge!"<<endl;
                return ;
            }

            mMatrix[p1][p2] = 1;
            //mMatrix[p2][p1] = 1;
        }
        cout<<"ok,Now initalized the edges. Done"<<endl;
    }

    ///create the Craph by default
    ///@param vexs --
    ///@param vSize --
    ///@param edges --
    ///@param eSize --
    MatrixUDG(char vexs[],int vSize,char edges[][2],int eSize){
        init();
        for(int i = 0;i<vSize;i++){
            mVexs[i] = vexs[i];
        }
        mVexNum = vSize;
        mEdgNum = eSize;

        for(int i = 0;i<eSize;i++){
            int p1 = getPosition(edges[i][0]);
            int p2 = getPosition(edges[i][1]);

            mMatrix[p1][p2] = 1;
            //mMatrix[p2][p1] = 1;
        }
        for(int i = 0;i<eSize;i++){
            for(int j = 0;j<eSize;j++){
                if(mMatrix[i][j]!=1){
                    mMatrix[i][j] = INT_MAX;
                }
            }
        }
    }
    void init(){
        memset(mMatrix,0,sizeof(mMatrix));
        memset(dist,0,sizeof(dist));
        memset(prev,0,sizeof(prev));
        memset(mVexs,0,sizeof(mVexs));
    }
    void set_target(int t){
        target = t;
    }
    void set_source(int s){
        source = s;
    }
    ~MatrixUDG(){}

    ///print the udg
    void print(){
        cout<<"\t";
        for(int i = 0;i<mVexNum;i++){
            cout<<mVexs[i]<<"\t";
        }cout<<endl;

        for(int i = 0;i<mVexNum;i++){
            cout<<mVexs[i]<<"\t";
            for(int j = 0;j<mVexNum;j++){
                cout<<mMatrix[i][j]<<"\t";
            }cout<<endl;
        }
    }


    ///read a char
    char readChar(){
        char ch;
        cin>>ch;
        return ch;
    }

    ///return the location of ch in the mMatrix
    int getPosition(char ch){
        for(int i = 0;i<mVexNum;i++){
            if(mVexs[i]==ch) return i;
        }
        return -1;
    }
};
    ///the default data:
    /**
        char vexs[] = {'a','b','c','d','e','f','g'};
        char edges[][2] = {
            {'a','c'},
            {'a','d'},
            {'a','f'},
            {'b','c'},
            {'c','d'},
            {'e','g'},
            {'f','g'}
        };
        int vSize = sizeof(vexs)/sizeof(vex[0]);
        int eSize = sizeof(edges)/sizeof(edges[0])
    */
    /**
        the vSize = 7;
        the eSize = 7;
    */

void Dijkstra(MatrixUDG *g){
    set<int> S,Q;
    g->set_source(0);
    g->set_target(7);///a,b,c,d,e,f,g,h    target = h = 7

    for(int i = 0;i<g->mVexNum;i++){
        g->dist[i] = g->mMatrix[g->source][i];
        g->prev[i] = (g->dist[i]==INT_MAX) ? -1:g->source;
        Q.insert(i);
    }
    g->dist[g->source] = 0;

    for(int i = 0;i<g->mVexNum;i++){
        cout<<g->dist[i]<<"\t";
    }cout<<"-"<<endl;
    for(int i = 0;i<g->mVexNum;i++){
        cout<<g->prev[i]<<"\t";
    }cout<<"--"<<endl;

    while(!Q.empty()){
        int d = INT_MAX;
        int u = 0;
        for(int k = 0;k<g->mVexNum;k++){
            if(Q.find(k)!=Q.end()){
                if(g->dist[u] < d){
                    d = g->dist[k];
                    u = k;
                }
            }
        }///for

        Q.erase(u);
        S.insert(u);

        for(auto it=Q.begin();it!=Q.end();it++){
            int v = *it;
            if((g->mMatrix[u][v]<INT_MAX)
                && (g->dist[u]+g->mMatrix[u][v] < g->dist[v])){
                g->dist[v] = g->dist[u]+g->mMatrix[u][v];
                g->prev[v] = u;
            }
        }///for
    }
    for(int i = 0;i<g->mVexNum;i++){
        cout<<g->dist[i]<<"\t";
    }cout<<endl;
}

class BFS{
public:
    void test(){
        cout<<"begin"<<endl;

        char vexs[] = {'a','b','c','d','e','f','g','h'};
        char edges[][2] = {
            {'a','b'},{'a','d'},{'a','e'},
            {'b','c'},{'b','d'},
            {'c','f'},
            {'d','f'},
            {'e','f'},{'e','g'},
            {'f','h'},
            {'g','h'}
        };
        int vSize = sizeof(vexs)/sizeof(vexs[0]);
        int eSize = sizeof(edges)/sizeof(edges[0]);
        MatrixUDG udg(vexs,vSize,edges,eSize);
        udg.print();
        cout<<"..."<<endl;
        Dijkstra(&udg);

        cout<<"end"<<endl;
    }
};
#endif // BFS_H_INCLUDED
