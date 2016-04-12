#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int hf(int ax, int ay, int bx, int by){
    return ay+20*ax+by*20*20+bx*20*20*20;
}

int mf(int ax, int ay){
    return ay + 20*ax;
}

class PathFinding {
        public:
        int minTurns(vector <string> board)
        {
            int v[20*20*20*20+20];
            fill(v, v+20*20*20*20+20, 0);

            vector<pi> M = { {0,0}, {0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
            vs s = board;
            queue<pi> Q;

            int n = s.size(), m = s[0].size();
            int sax, say, sbx, sby;
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(s[i][j] == 'A'){
                    sax = i; say = j;
                }
                if(s[i][j] == 'B'){
                    sbx = i; sby = j;
                }
            }
            int ss = hf(sax, say, sbx, sby), st = hf(sbx, sby, sax, say);
            if(ss == st) return 0;
            Q.push(make_pair(ss, 0));
            v[ss] = 1;

            while(!Q.empty()){

                int p = (Q.front()).first;
                int l = (Q.front()).second;
                Q.pop();

                int ax = -1, ay = -1, bx = -1, by = -1;
                ay = p%20; p /= 20;
                ax = p%20; p /= 20;
                by = p%20; p /= 20;
                bx = p%20;

                for(pi x : M)
                for(pi y : M){

                    int ai = x.first, aj = x.second;
                    int bi = y.first, bj = y.second;
                    int ax1 = ax+ai, ay1 = ay+aj;
                    int bx1 = bx+bi, by1 = by+bj;
                    int q = hf(ax1, ay1, bx1, by1);
                    int ah = mf(ax, ay), bh = mf(bx, by), a1h = mf(ax1, ay1), b1h = mf(bx1, by1);
                    #define valid(a, b) ( 0 <= (a) && (a) < (n) && 0 <= (b) && (b) < (m) )
                    if( valid(ax1, ay1) && valid(bx1, by1)
                        && q != p && (a1h != b1h) && !(ah == b1h && bh == a1h) && v[q] == 0){

                        if(q == st) return l+1;

                        if(s[ax1][ay1] != 'X' && s[bx1][by1] != 'X'){
                            v[q] = 1;
                            Q.push(make_pair(q, l+1));
                        }
                    }
                }
            }

            return -1;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 ".A..",
 "..B.",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTurns(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXXXXXXXX",
 "A...X...B",
 "XXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minTurns(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minTurns(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXX.XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, minTurns(Arg0)); }
	void test_case_4() { string Arr0[] = {"...A.XXXXX.....",
 ".....XXXXX.....",
 "...............",
 ".....XXXXX.B...",
 ".....XXXXX....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minTurns(Arg0)); }
	void test_case_5() { string Arr0[] = {"AB.................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "...................X",
 ".XXXXXXXXXXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 379; verify_case(5, Arg1, minTurns(Arg0)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        PathFinding ___test;
        ___test.run_test(-1);

}
// END CUT HERE
