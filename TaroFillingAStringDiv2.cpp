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
class TaroFillingAStringDiv2{ 
        public: 
        int getNumber(string S){ 
            int n = S.size();
            int res = 0;
            for(int i = 0; i < n; i++){
              if(S[i] == '?'){
                  int j = i;
                for(j = i; j < n && S[j] == '?'; j++);
                if(i == 0 || j == n){
                  i = j-1;
                  continue;
                }
                int k = j-i;
                if(S[i-1] == S[j] && k%2 == 0) res++;
                if(S[i-1] != S[j] && k%2 == 1) res++;
                i = j-1;
              }
              else if(i+1 < n && S[i] == S[i+1]) res++;
            }
            return res;
        } 
        
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABAA"; int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "??"; int Arg1 = 0; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "A?A"; int Arg1 = 0; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "A??B???AAB?A???A"; int Arg1 = 3; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"; int Arg1 = 10; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       TaroFillingAStringDiv2 ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
