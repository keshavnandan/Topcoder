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
#define mp make_pair

class MLBRecord{ 
        public:
        string teamStatus(vector <int> wins, int gamesLeft, int N) {
          string r(wins.size(), '.');
          vector<pi> w;
          for(int i=0; i<wins.size(); i++) w.push_back(pi(wins[i],i));
          sort(w.rbegin(),w.rend());
          for(int i=0; i<w.size(); i++) cout << w[i].first << ' ' << w[i].second << endl;
          
          int total = gamesLeft * wins.size() / 2;
          for(int i=0; i<N; i++) {
            int now = w[i].first;
            if (w[N].first + gamesLeft < now ) {
              r[w[i].second] = 'C';
              continue;
            }
            int need=0;
            for(int j = i+1; j<=N; j++) {
              need += now - w[j].first;
            }
            if (need > total) r[w[i].second] = 'C';
          }
          
          for(int i=0; i<w.size(); i++) w[i].first += gamesLeft;
          for(int i=N; i<w.size(); i++) {
            int now = w[i].first;
            if (w[N-1].first - gamesLeft > now ) {
              r[w[i].second] = 'E';
              continue;
            }
            int need = 0;
            for(int j = i-1; j>=N-1; j--) {
              need += w[j].first - now;
            }
            if (need > total) r[w[i].second] = 'E';
          }
          return r;    
        }
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {10,5,7,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; string Arg3 = "C..E"; verify_case(0, Arg3, teamStatus(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arr0[] = {1,1,1,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; string Arg3 = ".....C"; verify_case(1, Arg3, teamStatus(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arr0[] = {26,12,93,31,74,35,59,99,21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; int Arg2 = 4; string Arg3 = ".EC....C."; verify_case(2, Arg3, teamStatus(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arr0[] = {26,12,93,31,74,35,59,99,21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; int Arg2 = 4; string Arg3 = "EECECECCE"; verify_case(3, Arg3, teamStatus(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arr0[] = {10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; string Arg3 = "..."; verify_case(4, Arg3, teamStatus(Arg0, Arg1, Arg2)); }
  void test_case_5() { int Arr0[] = {27, 40, 33, 20, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 2; string Arg3 = "....."; verify_case(5, Arg3, teamStatus(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        MLBRecord ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
