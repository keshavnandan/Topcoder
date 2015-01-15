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
        int rank(vi v, int i){
          int count = 0;
          int val = v[i];
          for(int j = 0; j < v.size(); j++)
            if(v[j] > val) count++;
          return count;
        }
        string teamStatus(vector <int> wins, int gamesLeft, int N) {
          int n = wins.size();
          int total =  (n*gamesLeft)/2;
          string ans(n, '.');
          for(int i = 0; i < n; i++){
            //Best Case
            int totaRank = 0;
            queue<pair<vi, int> > Q;
            vi team = wins;
            team[i] += gamesLeft;
            Q.push(mp(team, total-gamesLeft));

            while(!Q.empty()){

              auto p = Q.front();
              Q.pop();
              vi team = p.first, minv = team;
              int totalWin = p.second, minRank = 1000, minj = 0;
              if(totalWin == 0){
                totaRank = rank(team, i);
                break;
              }

              for(int j = 0; j < n; j++){
                if(i == j) continue;
                vi next = team;
                next[j]++;
                if(next[j]-wins[j] > gamesLeft) continue;
                int r = rank(next, i);
                if(r < minRank){
                  minRank = r;
                  minv = next;
                  minj = j;
                }
                else if(r == minRank && (next[minj]-wins[minj] > next[j]-wins[j])){
                  minv = next;
                  minj = j;        
                }
              }
              Q.push(mp(minv, totalWin-1));
            }
            if(totaRank >= N){
              ans[i] = 'E';
              continue;
            }
            int done = 0;
            //Worst Case
                  {

                      int totaRank = 0;
                      vi rest;

                      for(int j = 0; j < n; j++){
                        if(i == j || wins[j] > wins[i]) continue;
                        rest.push_back(wins[j]);
                      }
                      int rank = n-(rest.size());
                      sort(rest.rbegin(), rest.rend());
                      int totalWin = total, score = wins[i];
                      for(int t : rest){
                        int x = min(totalWin, min(score-t, gamesLeft));
                        t += x;
                        if(t >= score) rank++;
                        totalWin -= x;
                      }
                      if(rank <= N){
                       ans[i] = 'C';
                       done = 1;
                     }
                  }

            if(!done) ans[i] = '.';

          }
          return ans;
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
