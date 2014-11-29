#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdio>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define inf 1000000000
int D[20];
int M[20][20];
int n;

struct node{
    
    int state;
    int cost;
    node(int s, int c) : state(s), cost(c) {}
};

bool operator<(node a, node b){
    return a.cost > b.cost;
}

class KiloManX {
        public:

        int leastShots(vs damageChart, vi bossHealth)
        {
            map<int, int> H;
            n = bossHealth.size();
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                    M[i][j] = inf;
            for(int i = 1; i <= n; i++) M[0][i] = bossHealth[i-1];
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++){
                    int k = damageChart[i-1][j-1] - '0';
                    if(k) M[i][j] = (bossHealth[j-1] + k - 1)/k;
              }
            priority_queue<node> Q;
            for(int i = 1; i <= n; i++){
                H[(1<<i)+1] = M[0][i];
                Q.push(node((1<<i)+1, M[0][i]));
            }
            while(!Q.empty()){
                node p = Q.top();
                Q.pop();
                int s = p.state, c = p.cost, m = inf;
                if(s == (1<<(n+1))-1) return c;
                for(int i = 0; i <= n; i++)
                    for(int j = 1; j <= n; j++)
                        if(s&(1<<i) && !(s&(1<<j)) && M[i][j] < inf){

                            m = M[i][j];
                            int t = (s|(1<<j));
                            if(H.count(t) == 0 || H[t] > c+m){
                                H[t] = c+m;
                                //cout<<"node <"<<i<<","<<j<<"> with value "<<m<<" pushed into queue at value "<<c<<endl;
                                Q.push(node(t, c+m));
                            }
                        }
            }            
        }

// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"070","500","140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,150,150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 218; verify_case(0, Arg2, leastShots(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"1542", "7935", "1139", "8882"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,150,150,150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 205; verify_case(1, Arg2, leastShots(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"07", "40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 48; verify_case(2, Arg2, leastShots(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"198573618294842",
 "159819849819205",
 "698849290010992",
 "000000000000000",
 "139581938009384",
 "158919111891911",
 "182731827381787",
 "135788359198718",
 "187587819218927",
 "185783759199192",
 "857819038188122",
 "897387187472737",
 "159938981818247",
 "128974182773177",
 "135885818282838"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {157, 1984, 577, 3001, 2003, 2984, 5988, 190003,
9000, 102930, 5938, 1000000, 1000000, 5892, 38}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 260445; verify_case(3, Arg2, leastShots(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"02111111", "10711111", "11071111", "11104111",
 "41110111", "11111031", "11111107", "11111210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,28,28,28,28,28,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 92; verify_case(4, Arg2, leastShots(Arg0, Arg1)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        KiloManX ___test;
        ___test.run_test(-1);

}
// END CUT HERE
