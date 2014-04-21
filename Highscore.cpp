#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Highscore
        { 
        public: 
        int getRank(vector <int> scores, int newscore, int places) 
            {

            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,90,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; int Arg2 = 10; int Arg3 = 2; verify_case(0, Arg3, getRank(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 50; int Arg3 = 1; verify_case(1, Arg3, getRank(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 10; int Arg3 = -1; verify_case(2, Arg3, getRank(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, 9, 8, 7, 6, 5, 4, 3, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; verify_case(3, Arg3, getRank(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {2000000000, 19539, 19466, 19146, 17441, 17002, 16348, 16343,
15981, 15346, 14748, 14594, 13752, 13684, 13336, 13290, 12939,
12208, 12163, 12133, 11621, 11119, 10872, 10710, 10390, 9934,
9296, 8844, 8662, 8653, 8168, 7914, 7529, 7354, 6016, 5428,
5302, 5158, 4853, 4538, 4328, 3443, 3222, 2107, 2107, 1337,
951, 586, 424, 31}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1337; int Arg2 = 50; int Arg3 = 46; verify_case(4, Arg3, getRank(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        }; 

// BEGIN CUT HERE
     int main()
     {
        Highscore ___test; 
        ___test.run_test(-1); 
     }  
// END CUT HERE
