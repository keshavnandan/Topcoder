#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class SnowClearing
        { 
        public: 
        int unreachable(vector <string> citymap, int row, int column) 
            {

            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"+-+-+-+-+-+-+"
,"| | | | | | |"
,"+-+ +-+ +-+ +"
,"|   |   |    "
,"+-+-+-+-+-+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 7; int Arg3 = 2; verify_case(0, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"+-+"
,"| |"
,"+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"+-+-+"
,"| | |"
,"+-+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"+-+-+"
,"|   |"
,"+-+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; verify_case(3, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"+ +-+ +-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+-+-+ +"
,"| |   | |     |   |   |         |     | |     | |"
,"+ +-+-+-+ +-+-+-+ +-+ +-+-+-+-+ +-+-+-+ +-+ +-+-+"
,"| | |       |   | |   |   |   |   |     | |   |  "
,"+ +-+-+ +-+-+ +-+-+-+-+-+-+-+ +-+ +-+ +-+ +-+ +-+"
,"|     | | | | |   |             |     |   | |   |"
,"+-+-+ +-+-+-+ +-+ +-+ + +-+-+-+-+-+ +-+-+ +-+-+-+"
,"|       | |     |     |   |         |   | |     |"
,"+-+-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+-+-+-+"
,"      |   | |     |   | |     | | |   | |       |"
,"+ +-+-+-+-+ + +-+ +-+ +-+ +-+-+ +-+-+-+-+-+ +-+-+"
,"| |   | |     |   |         |   | | |     |   | |"
,"+-+-+-+-+-+ +-+-+ +-+-+-+ +-+-+ +-+-+ +-+-+ +-+-+"
,"          |   |   |   |   | |                    "
,"+-+-+-+-+-+-+ +-+-+-+ + +-+-+ +-+ +-+-+-+ +-+-+ +"
,"|                     | |     |   |   | |   | | |"
,"+ +-+-+-+-+-+-+ + +-+-+-+-+-+-+-+-+ +-+-+-+ + +-+"
,"| |     |   | | |   | | | |       | |   | | | | |"
,"+-+-+-+ +-+-+-+-+ +-+ + +-+ +-+-+-+ +-+-+ +-+ +-+"
,"    | |   | | |   |               |   |          "
,"+-+ +-+-+-+-+-+ +-+ + +-+-+-+-+-+-+ + + +-+-+ +-+"
,"  | | |         | | | |   |   | | | | | | | | |  "
,"+-+-+ + +-+ +-+ +-+-+-+-+ + + + +-+-+ +-+-+-+-+-+"
,"    | | | | | | |         | | |       |     | |  "
,"+ +-+ + + +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+"
,"| |   | |     | |   |   |   |   |   | |         |"
,"+-+-+ +-+-+-+-+ +-+ + +-+-+-+-+ +-+ +-+-+-+-+-+-+"
,"      | |   | | | |     |       | |         | |  "
,"+-+ + +-+-+-+-+ + +-+-+-+ +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | | |   |   |     | |   |   | |   | | |   |  "
,"+-+-+-+-+-+-+ +-+-+-+-+-+-+ +-+ +-+ +-+ +-+-+ +-+"
,"|     | | |   |     |     |   | | |   |   | | | |"
,"+-+-+-+-+-+-+ + +-+-+-+-+-+ +-+-+-+-+ +-+ + +-+-+"
,"| | | | |   | | |   | |         |     | | | |   |"
,"+ +-+ +-+-+ + + +-+-+ + + +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | |   |     | |     |         |   | |   | | |"
,"+ +-+ +-+-+-+ +-+-+-+-+ +-+-+-+ +-+-+-+ +-+-+ + +"
,"|     | |     |   |           |   | | |   | | |  "
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+ +-+-+ +-+-+ +-+"
,"|         |     |       | |   |       | | | | |  "
,"+-+-+-+ +-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+ +-+-+-+-+"
,"        |   |   | | | | | | | | | | | | | |     |"
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+ +-+-+-+ +-+ + +-+-+ +"
,"      | | | |       | |     | |   |       |   | |"
,"+ +-+-+-+-+-+ +-+ +-+ +-+-+-+ +-+-+-+-+-+ + +-+-+"
,"| | |       | | | |       |     | | | |       | |"
,"+-+-+-+-+-+-+-+ + +-+-+-+ + +-+-+-+-+-+-+-+ +-+ +"
,"      |   |   | |   | |         |     | | | | | |"
,"+-+-+-+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+ + + +-+-+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 12; int Arg3 = 160; verify_case(4, Arg3, unreachable(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        }; 

// BEGIN CUT HERE
     int main()
     {
        SnowClearing ___test; 
        ___test.run_test(-1); 
     }  
// END CUT HERE
