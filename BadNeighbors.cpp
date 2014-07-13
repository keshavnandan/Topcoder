#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;
int p[1005];
int a[1005];
int b[1005];

class BadNeighbors {
        public:
        int maxDonations(vector <int> d)
        {
            memset(p, 0, sizeof(p));
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            int n = d.size();
            if(n == 2) return max(d[0], d[1]);
            n--;
            a[n] = d[n]; a[n-1] = 0;
            b[n] = 0; b[n-1] = d[n-1];
            p[n] = p[n-1] = -1;
            int maxa = 0, maxb = 0;
            for(int i = n-2; i >= 1; i--){
                maxa = 0, maxb = 0;
                for(int j = i+2; j <= n; j++){
                    if(a[j] > maxa) maxa = a[j];
                    if(b[j] > maxb) maxb = b[j];
                }
                a[i] = d[i] + maxa;
                b[i] = d[i] + maxb;
            }
            maxa = 0; maxb = 0;
            for(int i = 1; i <= n; i++) maxa = max(maxa, a[i]);
            for(int i = 2; i <= n; i++) maxb = max(maxb, b[i]);
            cout<<a[1]<<endl<<b[1]<<endl;
            a[0] = maxa;
            b[0] = max(b[1], maxb+d[0]);
            return max(a[0], b[0]);
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] =  { 10, 3, 2, 5, 7, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxDonations(Arg0)); }
	void test_case_1() { int Arr0[] = { 11, 15 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, maxDonations(Arg0)); }
	void test_case_2() { int Arr0[] = { 7, 7, 7, 7, 7, 7, 7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, maxDonations(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, maxDonations(Arg0)); }
	void test_case_4() { int Arr0[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2926; verify_case(4, Arg1, maxDonations(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        BadNeighbors ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
