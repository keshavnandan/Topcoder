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

class RockStar{ 
        public: 
        int getNumSongs(int ff, int fs, int sf, int ss) { 
           if(fs > sf)	return ff + 2*sf + ss + 1;
           else if(fs == 0) return ff > 0 ? ff : ss + min(sf, 1);
           else return ff + 2*fs + ss;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; int Arg3 = 200; int Arg4 = 100; verify_case(0, Arg4, getNumSongs(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 200; int Arg4 = 201; verify_case(1, Arg4, getNumSongs(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 5; verify_case(2, Arg4, getNumSongs(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 192; int Arg1 = 279; int Arg2 = 971; int Arg3 = 249; int Arg4 = 999; verify_case(3, Arg4, getNumSongs(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        RockStar ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
