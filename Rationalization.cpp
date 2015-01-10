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
int best;

class Rationalization{ 
        public:
        int w, s;
        vi W;
        vvi S;
        int d;
        int opt[10][15];

        int cal(){

          int tw = w;
          for(int i = 0; i < s; i++)
            for(int t = 0; t <= w; t++)
              opt[i][t] = -1;

          for(int i = 0; i < s; i++){

            int score = 0;
            for(int j = 0; j < w; j++) score += W[j]*S[i][j];
            opt[i][0] = score;
            vector<pi> W1;
            for(int j = 0; j < w; j++) W1.push_back(make_pair(W[j], j));
            sort(W1.begin(), W1.end());
            int j = 0;
            while(j < tw && !W1.empty()){
              int k = W1.back().first;
              int jj = W1.back().second;
              W1.pop_back();
              if(i == d && S[i][jj] < 9){
                j++;
                score += k;
                opt[i][j] = score;
              }
              if(i != d && S[i][jj] > 1){
                j++;
                score -= k;
                opt[i][j] = score;
              }
            }
          }
        }

        void solve(int i, int t){
          if(i == w){
            cal();
            for(int t1 = 0; t1 <= w; t1++){

              int total = t+t1, donei = 0;
              int dscore = opt[d][t1];
              if(dscore == -1) break;
              for(int i = 0; i < s; i++){
                if(i == d) continue;

                for(int t2 = 0; t2 <= w; t2++){
                  int iscore = opt[i][t2];
                  if(iscore == -1) break;
                  if(iscore < dscore){
                    donei++;
                    total += t2;
                    break;
                  }
                }

                if(total >= best) break;
              }

              if(donei == s-1){
               if(best > total) cout<<"best = "<<total<<endl;
               best = min(best, total);
              }
            }
            return;
          }

          int k = W[i];
          solve(i+1, t);
          if(k < 9){
            W[i] = k+1;
            solve(i+1, t+1);
          }
          if(k > 1){
            W[i] = k-1;
            solve(i+1, t+1);
          }
          W[i] = k;
        }
        int minTweaks(vector <int> weights, vector <string> scores, int desired){
          W = weights;
          w = weights.size();
          s = scores.size();
          best = 1000000;
          d = desired;
          S = vvi(s, vi(w));
          for(int i = 0; i < s; i++)
            for(int j = 0; j < w; j++)
              S[i][j] = scores[i][j]-'0';
          solve(0, 0);
          return best == 1000000 ? -1 : best;
        }
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = { 3, 2, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "6354",
  "5532",
  "4626" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
  void test_case_1() { int Arr0[] = { 3, 2, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "6354",
  "5532",
  "4626" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(1, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
  void test_case_2() { int Arr0[] = { 3, 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "555",
  "333" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = -1; verify_case(2, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
  void test_case_3() { int Arr0[] = { 1, 2, 3, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "9234",
  "1334" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 3; verify_case(3, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
  void test_case_4() { int Arr0[] = { 8, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "55",
  "92" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 6; verify_case(4, Arg3, minTweaks(Arg0, Arg1, Arg2)); }
//   void test_case_5() { int Arr0[] = { 2, 8, 7, 3, 6, 5, 2, 4, 7, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "9197287893", "9492555365", "3459972761", "4886112198", "5963616776", 
//   "6325897129", "3248793133", "7984474438", "4518544769", "1592681682" }
// ; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 17; verify_case(5, Arg3, minTweaks(Arg0, Arg1, Arg2)); }

  void test_case_5() { int Arr0[] = {5, 6, 1, 5, 5, 4, 8, 2, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7599175216", "3787782992", "2776166974", "7132523697", "5539346185", "8295358999", "2765989779", "1563646481", "4872499562", "8634217338"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 19; verify_case(5, Arg3, minTweaks(Arg0, Arg1, Arg2)); }


// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Rationalization ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
