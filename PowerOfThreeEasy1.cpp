#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
using namespace std;

class PowerOfThreeEasy
        {
        public:
        int log3(int x){
            int y = 0;
            if(x < 3) return 0;
            while(x >= 3){
                x /= 3;
                y++;
            }
            return y;
        }
        string ableToGet(int x, int y)
        {
            if(x == 0 && y == 0) return "Possible";
//            if((x == 0 && y != 3) || (y == 0 && x != 3)) return "Impossible";
            cout<<log3(10)<<" "<<log3(1000000000)<<endl;
            int n = max(log3(x), log3(y));
            int k = 1<<(n+1);
            cout<<pow(3, 10)<<endl;
            cout<<"k = "<<k<<endl;
            for(int i = 1; i <= k; i++){
                int a = 0, b = 0;
                for(int j = 0; j <= n; j++){
                    if(((1<<j)&(i))) a += pow(3, j);
                    else b += pow(3, j);
//                    if(i == k)
//                    cout<<a<<" "<<b<<endl;
                }
                if((x == a && y == b) || (x == b && y == a)){
                    cout<<"i = "<<i<<endl;
                    return "Possible";
                }
            }
            return "Impossible";
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 88573; int Arg1 = 0; string Arg2 = "Possible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 10; string Arg2 = "Possible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1093; int Arg1 = 2187; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        PowerOfThreeEasy ___test;
        ___test.run_test(-1);
     }
// END CUT HERE

