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
map<char, int> mx, my;


class RobotOnMoonEasy{ 
        public: 
        string isSafeCommand(vector <string> board, string S){ 
            int n = board.size(), m = board[0].size();
            int sx, sy;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(board[i][j] == 'S'){
                        sx = i;
                        sy = j;
                    }
            mx['U'] = -1; mx['D'] = 1; mx['L'] = 0; mx['R'] = 0;
            my['U'] = 0; my['D'] = 0; my['L'] = -1; my['R'] = 1;
            board[sx][sy] = '.';

            for(char c : S){
                int x = sx+mx[c], y = sy+my[c];
                if(x < 0 || x >= n || y < 0 || y >= m) return "Dead";
                if(board[x][y] == '#') continue;
                sx = x;
                sy = y;
            }
            return "Alive";
        } 
        
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".###.",
 "..S#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Alive"; verify_case(0, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Dead"; verify_case(1, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURU"; string Arg2 = "Alive"; verify_case(2, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Alive"; verify_case(3, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Dead"; verify_case(4, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R"; string Arg2 = "Dead"; verify_case(5, Arg2, isSafeCommand(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       RobotOnMoonEasy ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
