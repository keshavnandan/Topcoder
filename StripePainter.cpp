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

class StripePainter{ 
        public: 
        int minStrokes(string s) {
            int n = s.size(), strokes = 0;
            string t(n, '#');
            int dp[55][55] = {0};
            for(int i = 0; i < n; i++)
                dp[i][i] = 1;
            for(int l = 2; l <= n; l++){
                for(int i = 0; i+l <= n; i++){
                    int minv = 1000, j = i+l-1;
                    for(int k = i; k < j; k++){
                        int v = dp[i][k] + dp[k+1][j];
                        if(s[i] == s[k+1]) v--;
                        minv = min(v, minv);
                    }
                    dp[i][j] = minv;
                    // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
                }
            }

            strokes = dp[0][n-1];
            return strokes;
        }
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "RGBGR"; int Arg1 = 3; verify_case(0, Arg1, minStrokes(Arg0)); }
    void test_case_1() { string Arg0 = "RGRG"; int Arg1 = 3; verify_case(1, Arg1, minStrokes(Arg0)); }
    void test_case_2() { string Arg0 = "ABACADA"; int Arg1 = 4; verify_case(2, Arg1, minStrokes(Arg0)); }
    void test_case_3() { string Arg0 = "AABBCCDDCCBBAABBCCDD"; int Arg1 = 7; verify_case(3, Arg1, minStrokes(Arg0)); }
    void test_case_4() { string Arg0 = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"; int Arg1 = 26; verify_case(4, Arg1, minStrokes(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        StripePainter ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
