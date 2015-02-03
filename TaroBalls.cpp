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

class TaroBalls{ 
        public: 
        string getWinner(int R, int B) { 
          if(R == B) return "Friend";
          return "Taro";  
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; string Arg2 = "Taro"; verify_case(0, Arg2, getWinner(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Friend"; verify_case(1, Arg2, getWinner(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 7; string Arg2 = "Taro"; verify_case(2, Arg2, getWinner(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        TaroBalls ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
