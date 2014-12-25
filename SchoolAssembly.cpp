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

class SchoolAssembly{ 
        public: 
        int getBeans(int k, int q) {
           int x = 0, p = 0;
           int a[5] = {0, 0, 0, 0, 0};
           while(true){
            ++x;
            int total = 20;
            for(int i = 0; i < 5; i++){
              int j = (p+i)%5;
              int a1 = a[j]%q;
              if(i == 4){
                p = j;
                a[j] += total;
              }
              else{
                if(total == 0) continue;
                int a2 = min(total, q-1-a1);
                a[j] += a2;
                total -= a2;
              }
            }
            int n = 0;
            for(int i = 0; i < 5; i++) n += a[i]/q;
            if(n >= k) return x;
           }
        } 
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 2; verify_case(0, Arg2, getBeans(Arg0, Arg1)); }
  void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, getBeans(Arg0, Arg1)); }
  void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; verify_case(2, Arg2, getBeans(Arg0, Arg1)); }
  void test_case_3() { int Arg0 = 223; int Arg1 = 15; int Arg2 = 171; verify_case(3, Arg2, getBeans(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        SchoolAssembly ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
