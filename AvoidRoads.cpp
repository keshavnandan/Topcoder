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
#define mp make_pair
ll dp[105][105];
set<pair<pi, pi> > S;

class AvoidRoads{ 
        public: 
        long long numWays(int width, int height, vector <string> bad) {
           for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                dp[i][j] = 0;
            S.clear();
            for(string s : bad){
                int x1, x2, y1, y2;
                sscanf(s.c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
                S.insert(mp(mp(x1, y1), mp(x2, y2)));
                S.insert(mp(mp(x2, y2), mp(x1, y1)));
            }
            dp[0][0] = 1;
            for(int i = 0; i <= width; i++)
                for(int j = 0; j <= height; j++){
                    if(S.count(mp( mp(i, j), mp(i+1, j) )) == 0) dp[i+1][j] += dp[i][j];
                    if(S.count(mp( mp(i, j), mp(i, j+1) )) == 0) dp[i][j+1] += dp[i][j];
                }
            return dp[width][height];
        }
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 6; int Arg1 = 6; string Arr2[] = {"0 0 0 1","6 6 5 6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 252LL; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 35; int Arg1 = 31; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6406484391866534976LL; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        AvoidRoads ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
