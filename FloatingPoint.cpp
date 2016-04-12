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
#include <cmath>
using namespace std;
typedef pair<int,int> pi;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

class FloatingPoint{ 
        public: 
        int representations(int number, int mantissa, int exponent) { 
           int first = 0, last = log2(number);
           while(!( (1<<first) & number )) first++;
           cout<<first<<" "<<last<<endl;
           int total = 0;
           while(first >= 0){
            if((last - first + 1) <= mantissa && first < (1<<exponent)) total++;
            first--;
           }
           return total;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 24; int Arg1 = 4; int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, representations(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 3; int Arg3 = 1; verify_case(1, Arg3, representations(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 3; int Arg3 = 3; verify_case(2, Arg3, representations(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 5; int Arg2 = 2; int Arg3 = 4; verify_case(3, Arg3, representations(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 17408; int Arg1 = 10; int Arg2 = 10; int Arg3 = 6; verify_case(4, Arg3, representations(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        FloatingPoint ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
