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
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define inf 1000000;
struct  node
{
  int x;
  int y;
  int d[6];
  node(int xx = 0, int yy = 0) : x(xx), y(yy) {
    for(int i = 0; i < 6; i++) d[i] = -1;
  }
};

int mx[6] = {0, 1, 1, 0, -1, -1};
int my[6] = {1, 0, -1, -1, 0, 1};

class RoboCourier{
        public: 
        int timeToDeliver(vector <string> path){
            node R[505];
            map<pi, int> M;
            string total = "";
            for(string s : path) total += s;
            M[make_pair(0, 0)] = 0;
            R[0] = node(0, 0);
            int i = 0, j = 0, n = 0, k = 0, dest = 0;
            int dir = 0;

            while(k < total.length()){
              node s = R[i];
              char c = total[k++];
              if(c == 'L')  dir = (dir+5)%6;
              if(c == 'R')  dir = (dir+1)%6;
              if(c == 'F'){
                  int xx = s.x+mx[dir], yy = s.y+my[dir];
                  if(M.count(make_pair(xx, yy)) == 0){
                    M[make_pair(xx, yy)] = ++n;
                    R[n] = node(xx, yy);
                  }
                  j = M[make_pair(xx, yy)];
                  node p = R[j];
//                  cout<<i<<") "<<s.x<<" "<<s.y<<" "<<dir<<" "<<p.x<<" "<<p.y<<endl;
                  s.d[dir] = j;
                  p.d[(dir+3)%6] = i;
                  R[i] = s;
                  R[j] = p;
                  i = j;
              }
            }
            dest = i;
//            cout<<"dest = "<<i<<endl;
            int D[4000], visited[4000];
            for(int i = 0; i < 4000; i++){
              D[i] = inf;
              visited[i] = 0;
            }
            set<pi> Q;
            Q.insert(make_pair(0, 0));
            D[0] = 0;

            while(1){
              int m = 3999;
              for(int i = 0; i <= 3050; i++) if(!visited[i] && D[i] < D[m]) m = i;
              if(m > 3050) exit(1);
              visited[m] = 1;
              int c =  D[m];
              int pos = m/6, dir = m%6;
              if(pos == dest) return c;
              node p = R[pos];
              if(D[pos*6 + (dir+1)%6] > c+3) D[pos*6 + (dir+1)%6] = c+3;
              if(D[pos*6 + (dir+5)%6] > c+3) D[pos*6 + (dir+5)%6] = c+3;
              int steps = 0;
              while(p.d[dir] >= 0){
                steps++;
                int q = p.d[dir], cost = 0;
//                cout<<"q = "<<q<<" steps = "<<steps<<endl;
                if(steps > 1) cost = (steps-2)*2 + 8;
                else cost = steps*4;
                if(D[q*6 + dir] > c+cost){
                 D[q*6 + dir] = c+cost;
//                 cout<<"D["<<q*6 + dir<<"] = "<<c+cost<<endl;
                }
                p = R[q];
              }
            }
        } 
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = { "FRRFLLFLLFRRFLF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, timeToDeliver(Arg0)); }
  void test_case_1() { string Arr0[] = { "RFLLF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(1, Arg1, timeToDeliver(Arg0)); }
  void test_case_2() { string Arr0[] = { "FLFRRFRFRRFLLFRRF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, timeToDeliver(Arg0)); }
  void test_case_3() { string Arr0[] = { "FFFFFFFFFRRFFFFFFRRFFFFF",
  "FLLFFFFFFLLFFFFFFRRFFFF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, timeToDeliver(Arg0)); }
  void test_case_4() { string Arr0[] = { "RFLLFLFLFRFRRFFFRFFRFFRRFLFFRLRRFFLFFLFLLFRFLFLRFF",
  "RFFLFLFFRFFLLFLLFRFRFLRLFLRRFLRFLFFLFFFLFLFFRLFRLF",
  "LLFLFLRLRRFLFLFRLFRF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, timeToDeliver(Arg0)); }
  void test_case_5() { string Arr0[] = { "LLFLFRLRRLRFFLRRRRFFFLRFFRRRLLFLFLLRLRFFLFRRFFFLFL",
  "RLFFRRLRLRRFFFLLLRFRLLRFFLFRLFRRFRRRFRLRLRLFFLLFLF",
  "FRFLRFRRLLLRFFRRRLRFLFRRFLFFRLFLFLFRLLLLFRLLRFLLLF",
  "FFLFRFRRFLLFFLLLFFRLLFLRRFRLFFFRRFFFLLRFFLRFRRRLLR",
  "FFFRRLLFLLRLFRRLRLLFFFLFLRFFRLRLLFLRLFFLLFFLLFFFRR",
  "LRFRRFLRRLRRLRFFFLLLLRRLRFFLFRFFRLLRFLFRRFLFLFFLFR",
  "RFRRLRRFLFFFLLRFLFRRFRFLRLRLLLLFLFFFLFRLLRFRLFRLFR",
  "LLFLFRLFFFFFFFRRLRLRLLRFLRLRRRRRRRRLFLFLFLRFLFRLFF",
  "RLFRRLLRRRRFFFRRRLLLLRRLFFLLLLLRFFFFRFRRLRRRFFFLLF",
  "FFFFLRRLRFLLRRLRLRFRRRRLFLLRFLRRFFFRFRLFFRLLFFRRLL" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 169; verify_case(5, Arg1, timeToDeliver(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        RoboCourier ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     