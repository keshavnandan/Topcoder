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
int num[15];
int dp[15][15][105];
int go(int i, int j, int sum){
    if(dp[i][j][sum] != -1) return dp[i][j][sum];
    int mina = 1000000, s = 0;
    for(int k = i; k <= j; k++) s = (10*s + num[k]);
    if(s == sum) return 0;

    for(int t = 0; t <= sum; t++){
        for(int k = i; k < j; k++){
            int a = go(i, k, t) + go(k+1, j, sum-t) + 1;
            mina = min(mina, a);
        }
    }
    dp[i][j][sum] = mina;
    return dp[i][j][sum];
}

class QuickSums{
        public: 
        int minSums(string numbers, int sum) { 
           for(int i = 0; i <= 10; i++)
            for(int j = 0; j <= 10; j++)
                for(int k = 0; k <= 100; k++)
                    dp[i][j][k] = -1;
           int n = numbers.size();
           for(int i = 0; i < n; i++) num[i] = (numbers[i]-'0');
           int val = go(0, n-1, sum);
           if(val == 1000000) return -1;
           return val;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "99999"; int Arg1 = 45; int Arg2 = 4; verify_case(0, Arg2, minSums(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1110"; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, minSums(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0123456789"; int Arg1 = 45; int Arg2 = 8; verify_case(2, Arg2, minSums(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999"; int Arg1 = 100; int Arg2 = -1; verify_case(3, Arg2, minSums(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "382834"; int Arg1 = 100; int Arg2 = 2; verify_case(4, Arg2, minSums(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "9230560001"; int Arg1 = 71; int Arg2 = 4; verify_case(5, Arg2, minSums(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        QuickSums ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
