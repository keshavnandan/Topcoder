#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;
int memo[1<<15][15];
int fav[15];
int n;
class TurntableService
{
//  persons who are finished are masked in done and
//  the dish in front of person 0 is pos
    int go(int done, int pos){
        // return zero if all the persons are finished
        if(done == (1<<n)-1) return 0;
        int best = memo[done][pos];
        //if the function is already computed for go(done, pos) return the value
        // DP in action here
        if(best >= 0) return best;
        best = 999999999;
        // observe the cases corresponding to each possible rotation
        for(int rot = 0; rot < n; rot++){
            //cost incurred for rotation of rot
            int cost = (rot == 0) ? 0 : min(rot, n-rot) + 1;
            //dish in front of person 0 after the table is rotated by rot is cpos
            int cpos = (pos+rot)%n;
            int d = done;
            for(int i = 0; i < n; i++){
            // dish in front of person i is dish
                int dish = (cpos+i)%n;
                if((1<<dish) & fav[i]) d |= (1<<i);
                if(d != done)
                best = min(best, go(d, cpos)+ cost + 15);
            }
        }
        return best;
    }

    int calculateTime(vector <string> favorites) {
        n = favorites.size();
        int d = 0;
        for(int i = 0; i < favorites.size(); i++){
            fav[i] = 0;
            stringstream ss(favorites[i]);
            string s;
            int d = 0;
            while(ss>>s){
                int j = 0;
                while(j < s.size() && s[j] == '0') j++;
                s = s.substr(j);
                if(s.empty()) j = 0;
                else{
                    stringstream st(s);
                    st>>j;
                }
                fav[i] |= (1<<j);
            }
        }
//        for(int i = 0; i < n; i++) cout<<fav[i]<<endl;
        memset(&memo, -1, sizeof(memo));
        return go(0, 0);
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
