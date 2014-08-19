#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef set<int> si;
int maxv = 1000000;

class Fifteen {
        public:
        //P plays maxv means P lose and win otherwise
        int fp(si D, si P, si X){
            int minv  = maxv;
            for(int c : X)
                for(int a : P)
                    for(int b : P)
                        if(a != b && a+b+c == 15) minv = min(minv, c);
            if(X.size() == 1) return maxv;
            si XX = X;
            for(int c : X){
                P.insert(c);
                XX.erase(c);
                if(fd(D, P, XX) == 0) minv = min(minv, c);
                P.erase(c);
                XX.insert(c);
            }
            if(minv != maxv) return minv;
            return maxv;
        }
        //D plays maxv means D wins and 0 means D lose
        int fd(si D, si P, si X){
//            if(X.size() == 1) return maxv;
            for(int c : X)
                for(int a : D)
                    for(int b : D)
                        if(a != b && a+b+c == 15) return maxv;
            si XX = X;
            for(int c : X){
                D.insert(c);
                XX.erase(c);
                if(fp(D, P, XX) == maxv) return maxv;
                D.erase(c);
                XX.insert(c);
            }
            return 0;
        }

        string outcome(vector <int> moves)
        {
            si D, P;
            vi v = {1,2,3,4,5,6,7,8,9};
            si X(v.begin(), v.end());
            for(int i = 0; i < moves.size(); i++){
                int k = moves[i];
                X.erase(k);
                if(i%2) P.insert(k);
                else D.insert(k);
            }
            int r = fp(D, P, X);
            if(r == maxv) return "LOSE";
            return "WIN "+to_string(r);
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 5, 9, 6, 8, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 4"; verify_case(0, Arg1, outcome(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 8, 6, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, outcome(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 4, 7, 6, 9, 8, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 1"; verify_case(2, Arg1, outcome(Arg0)); }
	void test_case_3() { int Arr0[] = {9, 2, 1, 6, 3, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 5"; verify_case(3, Arg1, outcome(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, outcome(Arg0)); }
	void test_case_5() { int Arr0[] = {6, 3, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 2"; verify_case(5, Arg1, outcome(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        Fifteen ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
