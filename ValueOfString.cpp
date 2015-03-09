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

class ValueOfString{ 
        public: 
        int findValue(string s){ 
            int n = s.size(), res = 0;
            for(int i  = 0; i < n; i++){
                int k = 0;
                for(int j = 0; j < n; j++) if(s[j] <= s[i]) k++;
                res += k * (s[i] - 'a' + 1);
            }
            return res;
        } 
        
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "babca"; int Arg1 = 35; verify_case(0, Arg1, findValue(Arg0)); }
	void test_case_1() { string Arg0 = "zz"; int Arg1 = 104; verify_case(1, Arg1, findValue(Arg0)); }
	void test_case_2() { string Arg0 = "y"; int Arg1 = 25; verify_case(2, Arg1, findValue(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbc"; int Arg1 = 47; verify_case(3, Arg1, findValue(Arg0)); }
	void test_case_4() { string Arg0 = "topcoder"; int Arg1 = 558; verify_case(4, Arg1, findValue(Arg0)); }
	void test_case_5() { string Arg0 = "thequickbrownfoxjumpsoverthelazydog"; int Arg1 = 11187; verify_case(5, Arg1, findValue(Arg0)); }
	void test_case_6() { string Arg0 = "zyxwvutsrqponmlkjihgfedcba"; int Arg1 = 6201; verify_case(6, Arg1, findValue(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       ValueOfString ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
