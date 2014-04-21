#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int m, n;
class AlienAndGame
        {
        public:
        int fun(vector<string> b, int x, int y, int s){

            if(x + s - 1 >= m || y + s - 1 >= n) return 0;
            for(int i = x; i < x + s; i++)
                for(int j = y; j < y + s; j++)
                    if(b[i][j] != b[i][y]) return 0;
            return s*s;
        }
        int getNumber(vector <string> board)
            {
                m = board.size(), n = board[0].size();
                if(m == 1 || n == 1) return 1;
                int best = 1;
                for(int i = 0; i < m; i++)
                    for(int j = 0; j < n; j++)
                        for(int s = 1; s <= max(m, n); s++)
                            best  = max(best, fun(board, i, j, s));
                return best;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBB",
 "WBBB",
 "WWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"W",
 "B",
 "W",
 "W",
 "W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        AlienAndGame ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
