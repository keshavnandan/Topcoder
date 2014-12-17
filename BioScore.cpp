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
typedef pair<int, int> pi;
typedef pair<char, char> pc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class BioScore{ 
        public: 

        double maxAvg(vector <string> knownSet) {
          
          vi ex(10);
          int n = knownSet.size();
          map<pc, int> P, D;
          P[make_pair('A', 'C')] = P[make_pair('C', 'A')] = 0;
          P[make_pair('A', 'T')] = P[make_pair('T', 'A')] = 1;
          P[make_pair('A', 'G')] = P[make_pair('G', 'A')] = 2;
          P[make_pair('T', 'C')] = P[make_pair('C', 'T')] = 3;
          P[make_pair('G', 'C')] = P[make_pair('C', 'G')] = 4;
          P[make_pair('G', 'T')] = P[make_pair('T', 'G')] = 5;
          
          P[make_pair('A', 'A')] = 6;
          P[make_pair('C', 'C')] = 7;
          P[make_pair('T', 'T')] = 8;
          P[make_pair('G', 'G')] = 9;

          for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++){
              string s = knownSet[i], t = knownSet[j];
              for(int k = 0; k < s.size(); k++)
                ex[P[make_pair(s[k], t[k])]]++;
            }

          sort(ex.begin(), ex.begin()+6);

          int ret = -1000000000;
          for(int i = 1; i <= 10; i++)
            for(int j = 1; j <= 10; j++)
              for(int k = 1; k <= 10; k++)
                for(int l = 1; l <= 10; l++)
                  if((i+j+k+l)%2 == 0){
                    int t = 10-(i+j+k+l)/2;
                    int v = (-10*ex[0]-10*ex[1]-10*ex[2]+t*ex[3]+10*ex[4]+10*ex[5]) + i*ex[6]+j*ex[7]+k*ex[8]+l*ex[9];
                    ret = max(ret, v);
                  }

          return (2*(double)ret)/(n*(n-1));
        }
        
// BEGIN CUT HERE
  public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
  private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"AAA","AAA","AAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 30.0; verify_case(0, Arg1, maxAvg(Arg0)); }
  void test_case_1() { string Arr0[] = {"ACTGACTGACTG","GACTTGACCTGA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -4.0; verify_case(1, Arg1, maxAvg(Arg0)); }
  void test_case_2() { string Arr0[] = {"ACTAGAGAC","AAAAAAAAA","TAGTCATAC","GCAGCATTC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 50.5; verify_case(2, Arg1, maxAvg(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        BioScore ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
