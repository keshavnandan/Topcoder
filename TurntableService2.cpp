
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;
int memo[32768][16];
class TurntableService
        {
        public:
         int entree[15],n;

  int go(int done, int pos)
  {
    if (done==(1<<n)-1) return 0;

    int &best=memo[done][pos];
    if (best>=0) return best;
    best=999999999;

    for(int rot=0;rot<n;rot++) {
      int rtime=0;
      if (rot>0) rtime=1+min(rot, n-rot);
      int npos=(pos+rot)%n;

      int d=done;
      for(int i=0;i<n;i++) {
        int dish=(npos+i)%n;
        if ((1<<dish)&entree[i])
          d |= (1<<i);
      }
      if (d!=done) {
        int t=go(d,(pos+rot)%n)+rtime+15;
        if (t<best) best=t;
      }
    }

    return best;
  }

  int calculateTime(vector <string> favorites) {
    n=favorites.size();
    for(int i=0;i<n;i++) {
      int m=0,j, k;
      istringstream ss(favorites[i]);
      string s;
      while(ss >> s){
        int k = 0;
        while(k < s.size() && s[k] == '0') k++;
        s = s.substr(k);
        istringstream st(s);
        if(!s.empty()) st >> j;
        else j = 0;
//        cout<<s<<" : "<<j<<endl;
        m |= (1<<j);
      }
//      while (ss >> j) m |= (1<<j);
      entree[i]=m;
    }

    memset(memo,-1,sizeof(memo));
    return go(0,0);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 2", "1", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, calculateTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2 3", "0 1 2", "0 1", "2 0000000000000000000000000000000000000000000002"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(1, Arg1, calculateTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"4", "1", "2", "3", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(2, Arg1, calculateTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 35; verify_case(3, Arg1, calculateTime(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        TurntableService ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
