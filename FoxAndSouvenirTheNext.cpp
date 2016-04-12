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
#include <numeric>
using namespace std;
typedef pair<int,int> pi;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
int dp[55][55][2555];

class FoxAndSouvenirTheNext{ 
        public: 
        string ableToSplit(vector <int> value){ 
            int n = value.size(), total = accumulate(value.begin(), value.end(), 0);
            if(n%2 || total%2) return "Impossible";
            total = total/2;
            // n = n/2;
            int s[55];
            s[0] = value[0];
            for(int i = 1; i < n; i++) s[i] = s[i-1] + value[i];

            for(int i = 0; i <= 50; i++){
                dp[i][0][0] = 1;
            }
            for(int i = 0; i < n; i++){
                dp[i][1][value[i]] = 1;
                for(int j = 1; j <= i+1; j++)
                    for(int k = 0; k <= s[i]; k++){
                        int x = 0;
                        if(i > 0 && j > 1 && k >= value[i] && dp[i-1][j-1][k-value[i]]) x++;
                        if(i > 0 && dp[i-1][j][k]) x++;
                        if(x > 0) dp[i][j][k] = 1;
                        // cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k]<<endl;
                    }
            }
            return dp[n-1][n/2][total] ? "Possible" : "Impossible";
        }
        
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, ableToSplit(Arg0)); }
    void test_case_1() { int Arr0[] = {1,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, ableToSplit(Arg0)); }
    void test_case_2() { int Arr0[] = {1,1,2,3,5,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, ableToSplit(Arg0)); }
    void test_case_3() { int Arr0[] = {2,3,5,7,11,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(3, Arg1, ableToSplit(Arg0)); }
    void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(4, Arg1, ableToSplit(Arg0)); }
    void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(5, Arg1, ableToSplit(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       FoxAndSouvenirTheNext ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
