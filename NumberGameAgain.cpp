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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef long long ll;
typedef pair<ll, ll> pi;


class NumberGameAgain{ 
        public: 
        long long solve(int k, vector<long long> table) {
          sort(table.begin(), table.end());
          set<pi> S;
           ll r = (1LL << k) - 2;
           // cout<<"r = "<<r<<endl;
           for(ll n : table){
              ll x = log2(n), l = k-x;
             // cout<<n<<" "<<x<<" "<<l<<endl;

              bool done = true;
              for(pi p : S){
                if(n >= p.first && n <= p.second){
                  done = false;
                  break;
                }
              }

              if(done){
                r -= ((1LL << l) - 1);
                ll low = n, high = n;
                S.insert(make_pair(low, high));
                while(--l){
                  high = 2*high+1;
                  low = 2*low;
                 // cout<<"[ "<<low<<" , "<<high<<" ]"<<endl;
                  S.insert(make_pair(low, high));
                }
              }

           }
           return r;
        } 
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 3; long Arr1[] = {2,4,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 5; long Arr1[] = {2,3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 20; long Arr1[] = {88, 138390, 363924, 18595, 148, 179170, 29, 490195, 28, 67, 533, 980413, 1033224, 227290, 652478, 786172, 27, 5, 768}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 561093LL; verify_case(2, Arg2, solve(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 40; long Arr1[] = {2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 549755748288LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }
  void test_case_4() { int Arg0 = 40; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1099511627774LL; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        NumberGameAgain ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
