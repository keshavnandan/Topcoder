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
typedef long long ll;
#define mod 1000000007
const int MAXN = 1000;
ll nk[MAXN+1][MAXN+1];
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

void cnk() {
  nk[0][0]=1;
  FOR(k,1,MAXN) nk[0][k]=0;
  FOR(n,1,MAXN) {
    nk[n][0]=1;
    FOR(k,1,MAXN) nk[n][k] = (nk[n-1][k-1]+nk[n-1][k])%mod;
  }
}

class TaroLuckyStrings{ 
        public: 
        int getNumber(int N, int K) {
            cnk();
            int total = N+1;
            for(int a = 1; a <= K; a++){
              for(int t = a; t <= N-a; t++){
                long long p1 = nk[t][a], p2 = nk[N-t][a], p = (p1*p2)%mod;
                total = (total + p)%mod;
              }
            }
            return total;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 128; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 17; int Arg1 = 6; int Arg2 = 130238; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 247; int Arg2 = 839204010; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        TaroLuckyStrings ___test; 
        ___test.run_test(4); 
} 
// END CUT HERE     
