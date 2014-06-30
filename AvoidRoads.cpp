#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
int cx[105][105], cy[105][105];
long long t[105][105];
int w, h;

class AvoidRoads {
        public:

        long long numWays(int width, int height, vector <string> bad)
        {
            w = width; h = height;
            memset(cx, 0, sizeof(cx));
            memset(cy, 0, sizeof(cy));
            memset(t,  0, sizeof(t));

            for(int i = 0; i < bad.size(); i++){
                int a, b, aa, bb;
                sscanf(bad[i].c_str(), "%d%d%d%d", &a, &b, &aa, &bb);
//                cout<<a<<b<<aa<<bb<<endl;
                if(a > aa) swap(a, aa);
                if(b > bb) swap(b, bb);
                if(a < aa) cx[a][b] = 1;
                if(b < bb) cy[a][b] = 1;
            }
/*            for(int i = 0; i < ban.size(); i++){
                pi x = ban[i].first, y = ban[i].second;
                cout<<x.first<<" "<<x.second<<"\t"<<y.first<<" "<<y.second<<endl;
            }
*/          if(cx[0][0] == 0) t[1][0] = 1;
            if(cy[0][0] == 0) t[0][1] = 1;

            for(int k = 2; k <= h; k++){
                for(int i = 0, j = k; i <= w && j >= 0; i++, j--){
                    long long sum = 0;
                    if(i > 0 && cx[i-1][j] == 0) sum += t[i-1][j];
                    if(j > 0 && cy[i][j-1] == 0) sum += t[i][j-1];
                    t[i][j] = sum;
//                    cout<<i<<" "<<j<<" = "<<sum<<endl;
                }
            }

            for(int k = 1; k <= w; k++){
                for(int i = k, j = h; i <= w && j >= 0; i++, j--){
                    long long sum = 0;
                    if(i > 0 && cx[i-1][j] == 0) sum += t[i-1][j];
                    if(j > 0 && cy[i][j-1] == 0) sum += t[i][j-1];
                    t[i][j] = sum;
//                    cout<<i<<j<<" = "<<sum<<endl;
                }
            }

//            return tt(w, h);
            return t[w][h];
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 6; string Arr2[] = {"0 0 0 1","6 6 5 6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 252LL; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 35; int Arg1 = 31; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6406484391866534976LL; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 10; string Arr2[] = {"0 2 0 3", "1 2 1 3", "2 2 2 3", "3 2 3 3", "4 2 4 3", "5 2 5 3", "6 2 6 3", "7 2 7 3", "8 2 8 3", "9 2 9 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        AvoidRoads ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
