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
int dp[105][105];
int d = 0;

int fun(int n, int k){
    if(dp[n][k] != -1) return dp[n][k];
    if(k == 0) return n;
    if(n == 1) return n;
    int minv = 1000000;
    d++;
    string s(d, ' ');
    // cout<<s<<n<<" "<<k<<endl;
    for(int a = 1; a < n; a++){
        int b = n-a;
        for(int j = 0; j < k; j++)
        minv = min(minv, max(fun(a, k-1-j), fun(b, j)) + 1);
    }
    minv = min(minv, fun(n-1, k) + 1);
    dp[n][k] = minv;
    d--;
    string t(d, ' ');
    // cout<<t<<n<<" "<<k<<" "<<minv<<endl;
    return dp[n][k];
}

class CartInSupermarketEasy{ 
        public: 
        int calc(int N, int K) { 
           for(int i = 0; i <= 100; i++)
            for(int j = 0; j <= 100; j++)
                dp[i][j] = -1;
            return fun(N, K);
        } 
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, calc(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, calc(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 7; int Arg1 = 100; int Arg2 = 4; verify_case(3, Arg2, calc(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 45; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, calc(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 8; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        CartInSupermarketEasy ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
