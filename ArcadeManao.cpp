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
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
#define sz size()
#define mp(x, y) make_pair(x, y)
#define ri(a, b) for(int i=((int)(a)); i < ((int)(b)); i++)                // i -> [a, b)
#define rie(a, b) for(int i=((int)(a)); i <= ((int)(b)); i++)            // i -> [a, b]
#define rj(a, b) for(int j=((int)(a)); j < ((int)(b)); j++)               // j -> [a, b)
#define rje(a, b) for(int j=((int)(a)); j <= ((int)(b)); j++)           // j -> [a, b]
#define rk(a, b) for(int k=((int)(a)); k < ((int)(b)); k++)           // k -> [a, b)
#define rke(a, b) for(int k=((int)(a)); k <= ((int)(b)); k++)       // k -> [a, b]
#define fi(b) for(int i=0; i < ((int)(b)); i++)                             // i -> [0, b)
#define fie(b) for(int i=0; i <= ((int)(b)); i++)                         // i -> [0, b]
#define fj(b) for(int j=0; j < ((int)(b)); j++)                            // j -> [0, b)
#define fje(b) for(int j=0; j <= ((int)(b)); j++)                        // j -> [0, b]
#define fk(b) for(int k=0; k < ((int)(b)); k++)                        // k -> [0, b)
#define fke(b) for(int k=0; k < ((int)(b)); k++)                      // k -> [0, b]
#define fle(b) for(int l=0; l <= ((int)(b)); l++)                        // l -> [0, b]
vs M;
int visited[55][55];
int n, m;
#define valid(x, y) ( (x) >= 0 && (x) < n && (y) >= 0 && (y) < m && !visited[(x)][(y)] && M[(x)][(y)] == 'X')


class ArcadeManao{ 
        public: 
        int shortestLadder(vector <string> level, int coinRow, int coinColumn){ 
            M = level;
            n = M.size();
            m = M[0].size();
            vi move(2);
            move[0] = -1; move[1] = 1;

            for(int l = 0; l < n; l++){
                // cout<<"level = "<<l<<endl;
                fi(n) fj(m) visited[i][j] = 0;
                queue<pi> Q;
                Q.push(mp(n-1, m-1));
                visited[n-1][m-1] = 1;
                while(!Q.empty()){
                    pi p = Q.front();
                    Q.pop();
                    int x = p.first, y = p.second;
                    // cout<<x<<" "<<y<<endl;
                    if(x+1 == coinRow && y+1 == coinColumn) return l;
                    //Move horizontally
                    for(int k : move){
                        if(valid(x, y+k)){
                         Q.push(mp(x, y+k));
                         visited[x][y+k] = 1;
                        }
                    }
                    //Move vertically
                    for(int i = 1; i <= l; i++){
                        for(int k : move){
                            if(valid(x+k*i, y)){
                             visited[x+k*i][y] = 1;
                             Q.push(mp(x+k*i, y));
                            }
                        }
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
	void test_case_0() { string Arr0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"XXXX",
 "...X",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(4, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       ArcadeManao ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
