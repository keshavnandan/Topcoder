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

bool isMatch(string a, string b){
    if(a.size() != b.size()) return false;
    //a contains either 0 or 1, b may contain ?
    for(int i = 0; i < a.size(); i++){
        if(b[i] != '?' && b[i] != a[i]) return false;
    }
    return true;
}

class NonDeterministicSubstring{
 
        public: 
        long long ways(string A, string B) {
            int n = A.size(), l = B.size();
            if(n < l) return 0;
            set<string> S;
            for(int i = 0; i+l <= n; i++){
                S.insert(A.substr(i, l));
            }
            int count = 0;
            for(string a : S){
                if(isMatch(a, B)) count++;
            }
            return count;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00010001"; string Arg1 = "??"; long long Arg2 = 3LL; verify_case(0, Arg2, ways(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "00000000"; string Arg1 = "??0??0"; long long Arg2 = 1LL; verify_case(1, Arg2, ways(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "001010101100010111010"; string Arg1 = "???"; long long Arg2 = 8LL; verify_case(2, Arg2, ways(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "00101"; string Arg1 = "??????"; long long Arg2 = 0LL; verify_case(3, Arg2, ways(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "1101010101111010101011111111110001010101"; string Arg1 = "???????????????????????????????????"; long long Arg2 = 6LL; verify_case(4, Arg2, ways(Arg0, Arg1)); }

// END CUT HERE
         
}; 
// BEGIN CUT HERE 
int main(){

        NonDeterministicSubstring ___test; 
        ___test.run_test(-1); 

}
// END CUT HERE 
