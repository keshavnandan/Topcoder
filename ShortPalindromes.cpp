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
string dp[50][50];

class ShortPalindromes{ 
        public:
        string shortest(string s) { 
            int n = s.size(), strokes = 0;
            if(n == 1) return s;
            for(int i = 0; i < n; i++){
                dp[i][i] = s.substr(i, 1);
            }
            for(int l = 2; l <= n; l++){
                for(int i = 0; i+l <= n; i++){
                    int j = i+l-1;
                    string res = string(50, 'z');
                    // cout<<s.substr(i, l)<<" ";
                    if(s[i] == s[j]){
                        string t = dp[i+1][j-1];
                        t.insert(t.begin(), s[i]);
                        t.insert(t.end(), s[j]);
                        if(t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
                        // cout<<t<<" ";
                    }
                    string t = dp[i+1][j];
                    t.insert(t.begin(), s[i]);
                    t.insert(t.end(), s[i]);
                    // cout<<t<<" ";
                    if(t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
                    t = dp[i][j-1];
                    t.insert(t.begin(), s[j]);
                    t.insert(t.end(), s[j]);
                    // cout<<t<<" ";
                    if(t.size() < res.size() || (t.size() == res.size() && t < res)) res = t;
                    dp[i][j] = res;
                    // cout<<dp[i][j]<<endl;
                }
            }
            return dp[0][n-1];
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RACE"; string Arg1 = "ECARACE"; verify_case(0, Arg1, shortest(Arg0)); }
	void test_case_1() { string Arg0 = "TOPCODER"; string Arg1 = "REDTOCPCOTDER"; verify_case(1, Arg1, shortest(Arg0)); }
	void test_case_2() { string Arg0 = "Q"; string Arg1 = "Q"; verify_case(2, Arg1, shortest(Arg0)); }
	void test_case_3() { string Arg0 = "MADAMIMADAM"; string Arg1 = "MADAMIMADAM"; verify_case(3, Arg1, shortest(Arg0)); }
	void test_case_4() { string Arg0 = "ALRCAGOEUAOEURGCOEUOOIGFA"; string Arg1 = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"; verify_case(4, Arg1, shortest(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        ShortPalindromes ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE