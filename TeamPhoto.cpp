#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <climits>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
int c, a1, a2;

class TeamPhoto {
        public:

        int findMin(vi b, int a, int z){

            int x1[4] = { b[0], b[a-1], b[a-1], b[0] };
            int y1[4] = { b[a-1], b[0], b[0], b[a-1] };
            int x2[4] = { b[z-1], b[z-1], b[a], b[a] };
            int y2[4] = { b[a], b[a], b[z-1], b[z-1] };
            int d1 = 0, d2 = 0;
            d1 = b[a-1]-b[0]; d2 = b[z-1]-b[a];
            int minv = 1000000;

            for(int i = 0; i < 4; i++){
                minv = min(minv,  min( abs(a1-x1[i]) + abs(a2-x2[i]), abs(a1-x2[i]) + abs(a2-x1[i]) ) + d1 + d2 + abs(c-y1[i]) + abs(c-y2[i]));
            }
            return minv;
        }

        int minDiff(vector <int> h)
        {
            c = h[0], a1 = h[1], a2 = h[2];
            h.erase(h.begin(), h.begin()+3);
            sort(h.begin(), h.end());
            int k = h.size();
            if(k%2 == 0) return findMin(h, k/2, k);
            return min(findMin(h, k/2, k), findMin(h, k/2+1, k));
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {80,82,81,50,90,65}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 79; verify_case(0, Arg1, minDiff(Arg0)); }
	void test_case_1() { int Arr0[] = {70,82,91,50,50,50,50,50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 113; verify_case(1, Arg1, minDiff(Arg0)); }
	void test_case_2() { int Arr0[] = {13, 17, 11, 12, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minDiff(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        TeamPhoto ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
