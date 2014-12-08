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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
struct state{
  int x;
  int y;
  int t;
  state(int x, int y, int t) : x(x) , y(y), t(t) {}
};
bool operator<(state a, state b){
    return a.t > b.t;
}

class DungeonEscape{ 
        public: 
        int exitTime(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting) { 
           int m = up.size(), n = up[0].size();
           priority_queue<state> Q;
           Q.push(state(startLevel, startEasting, 0));
           vvi visited(55, vi(55, 0));

           while(!Q.empty()){
              state p = Q.top();
              Q.pop();
              int x = p.x, y = p.y, t = p.t;
              // cout<<x<<" "<<y<<" "<<t<<endl;
              if(x == -1) return t;
              if(visited[x][y]) continue;
              visited[x][y] = 1;
              //move west/left
              if(y > 0 && west[x][y] != 'x'){
                int tt = t+(west[x][y]-'0');
                if(tt < n*(m-x)) Q.push(state(x, y-1, tt));
              }
              //move east/right
              if(y < n-1 && east[x][y] != 'x'){
                int tt = t+(east[x][y]-'0');
                if(tt < n*(m-x)) Q.push(state(x, y+1, tt));
              }
              //move up
              if(up[x][y] != 'x'){
                int tt = t+(up[x][y]-'0');
                if(x == 0 || tt < n*(m-x+1)) Q.push(state(x-1, y, tt));
              }
              //move down
              if(x < m-1 && down[x][y] != 'x'){
                int tt = t+(down[x][y]-'0');
                if(tt < n*(m-x-1)) Q.push(state(x+1, y, tt));
              }
           }
           return -1;

        } 
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"0x4",
 "0x3",
 "0x3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0x9",
 "009",
 "0x9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0x9",
 "1x9",
 "009"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0x9",
 "0x0",
 "009"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 2; int Arg6 = 10; verify_case(0, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_1() { string Arr0[] = {"xxxxxxxxx1",
 "1xxxxxxxxx",
 "xxxxxxxxx1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xxxxxxxxxx",
 "xxxxxxxxxx",
 "xxxxxxxxxx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1111111111",
 "xxxxxxxxxx",
 "1111111111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxxx",
 "1111111111",
 "xxxxxxxxxx"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 0; int Arg6 = 30; verify_case(1, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_2() { string Arr0[] = {"xxxxxxxxx1",
 "xxxx999991",
 "x999999991"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1111111111",
 "1111111111",
 "1111111111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1111122242",
 "2222222241",
 "2111111111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxx1",
 "1111111111",
 "xxxxxxxxx1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 0; int Arg6 = -1; verify_case(2, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
  void test_case_3() { string Arr0[] = {"1x2x3x4x5x6x7x8x9",
 "00000000000000000",
 "98765432223456789",
 "12345678987654321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000000000000000",
 "00000000000000000",
 "00000000000000000",
 "00000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; int Arg5 = 12; int Arg6 = 17; verify_case(3, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        DungeonEscape ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
