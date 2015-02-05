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
map<char, int> M;

class Scoreboard{ 
        public: 
        int getScore(string events) { 
           M['B'] = 1000;
           M['b'] = 250;
           M['R'] = 50;
           M['J'] = 10000;
           M['D'] = 20000;
           int total = 0;
           for(char c : events) total += M[c];
            return total;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBB"; int Arg1 = 3000; verify_case(0, Arg1, getScore(Arg0)); }
	void test_case_1() { string Arg0 = "BbRJD"; int Arg1 = 31300; verify_case(1, Arg1, getScore(Arg0)); }
	void test_case_2() { string Arg0 = ""; int Arg1 = 0; verify_case(2, Arg1, getScore(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Scoreboard ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
