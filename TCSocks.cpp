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
#include <stack>
#include <queue>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;

int maxp = 0, n = 0;
int city[10][105];
int C[10][10], T[10][10];
vi money;

void solve(vi v){
  vi uv;
  int curr = 0, t = 0, p = 0;
  v.push_back(0);
  for(int i : v){
    t += T[curr][i];
    p -= C[curr][i];
    p += money[i]/city[i][t];
    curr = i;
  }
  maxp = max(p, maxp);
  v.pop_back();
  for(int i = 1; i < n; i++) 
    if(find(v.begin(), v.end(), i) == v.end()) 
      uv.push_back(i);

  for(int i : uv){
    v.push_back(i);
    solve(v);
    v.pop_back();
  }
}

class TCSocks{
        public:
        int earnMoney(vector <int> _money, vector <string> cost, vector <string> time, vector <string> competitors) { 
          
          money = _money;
          n = money.size();
          maxp = 0;
          for(int i = 0; i < 10; i++)
            for(int j = 0; j < 105; j++)
              city[i][j] = 1;
          
           for(int i = 0; i < n; i++){
            stringstream ss(cost[i]), st(time[i]);
            for(int j = 0; j < n; j++){
              int k;
              ss>>k;
              C[i][j] = k;
              st>>k;
              T[i][j] = k;
            }
          }
          
          for(string s : competitors){
            stringstream ss(s);
            int t = 0, j = 0, i = 0;
            while(ss>>j){
              t += T[i][j];
              for(int k = t; k <= 100; k++) city[j][k] *= 2;
              i = j;
            }
          }

          for(int i = 1; i < n; i++){
            vi s(1, i);
            solve(s);
          }

          return maxp;
        }
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {0, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 50 50 200", "0 0 50 200", "0 10 0 200", "0 0 0 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 1 1", "1 0 1 1", "1 1 0 1", "1 1 1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 140; verify_case(0, Arg4, earnMoney(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_1() { int Arr0[] = {0, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 50 50 200", "0 0 50 200", "0 10 0 200", "0 0 0 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 1 1", "1 0 1 1", "1 1 0 1", "1 1 1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"3", "2 3 1", "2 1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 50; verify_case(1, Arg4, earnMoney(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_2() { int Arr0[] = {0, 100, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 20 10", "10 0 20", "20 10 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 5", "1 0 1", "1 1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2", "2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 240; verify_case(2, Arg4, earnMoney(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_3() { int Arr0[] = {0, 40, 40, 40, 40, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 25 25 25 25 25", "25 0 25 25 25 25", "25 25 0 25 25 25", 
 "25 25 25 0 25 25", "25 25 25 25 0 25", "25 25 25 25 25 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 1 1 1 1", "1 0 1 1 1 1", "1 1 0 1 1 1", "1 1 1 0 1 1", "1 1 1 1 0 1", "1 1 1 1 1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1", "2", "3", "4", "5"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(3, Arg4, earnMoney(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_4() { int Arr0[] = {0, 70, 70, 70, 70, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 25 25 25 25 25", "25 0 25 25 25 25", "25 25 0 25 25 25", 
 "25 25 25 0 25 25", "25 25 25 25 0 25", "25 25 25 25 25 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 1 1 1 1", "1 0 1 1 1 1", "1 1 0 1 1 1", "1 1 1 0 1 1", "1 1 1 1 0 1", "1 1 1 1 1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1", "2", "3", "4", "5"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 25; verify_case(4, Arg4, earnMoney(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_5() { int Arr0[] = {0,457,434,382,818,403,265,449,214}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 204 600 800 885 542 439 823 913",
 "32 0 813 687 242 129 34 447 862",
 "56 462 0 727 71 309 461 867 200",
 "656 96 334 0 178 650 108 477 547",
 "89 856 922 495 0 821 374 100 651",
 "634 810 319 947 322 0 283 227 286",
 "446 416 272 551 243 880 0 47 878",
 "390 315 221 765 938 732 747 0 435",
 "902 616 166 830 223 406 736 712 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 10 6 5 5 4 7 6",
 "5 0 2 7 3 2 1 4 2",
 "1 9 0 8 6 1 3 9 9",
 "2 8 8 0 1 9 10 4 5",
 "8 8 2 7 0 5 3 9 1",
 "6 8 9 9 3 0 7 4 7",
 "10 8 9 10 7 1 0 9 4",
 "8 6 5 1 6 6 5 0 4",
 "3 8 4 4 6 10 10 3 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 8 2 5 4 7 6","6 2 4","8 7"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 785; verify_case(5, Arg4, earnMoney(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        TCSocks ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
