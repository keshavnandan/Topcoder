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
typedef long long ll;

class TheSquareRootDilemma{
 
        public:

        int countPairs(int N, int M){
          int ans = 0;
          for(ll i = 1; i <= N; i++){
            ll a = i, r = 1;
            for(ll j = 1; j <= sqrt(a); j++) if(a%(j*j) == 0) r = j;
            r = a/(r*r);
            for(ll j = 1; j <= sqrt(M); j++) 
              if(r*j*j <= M){
                ans++;
              }
          }
          return ans;
        } 
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 77777; int Arg1 = 3; int Arg2 = 636; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 5; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 310; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        TheSquareRootDilemma ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
