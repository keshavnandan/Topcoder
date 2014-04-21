#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
long long mod = 1000000007;
int fac[2000005];
int ifac[1000005];

class VocaloidsAndSongs
        {
        public:
        int inv(int a) {
            long long newv = 1, old = 0, q = mod, r, h;
            int pos = 0;
            while (a > 0) {
                r = q%a;
                q = q/a;
                h = q*newv + old;
                old = newv;
                newv = h;
                q = a;
                a = r;
                pos = !pos;
            }
        //    int ans = pos ? old : (mod - old);
        //    return ans > 0 ? ans : -ans;
            return pos ? old : (mod - old);
        }

        int count(int S, int gumi, int ia, int mayu)
        {
            int sol = 0;
            fac[0] = fac[1] = 1;
            ifac[0] = ifac[1] = 1;
            for(int i = 2; i <= 1000000; i++){
          //      cout<<i<<endl;
                long long x = i, y = fac[i-1];
                fac[i] = (x*y)%mod;
                x = inv(i), y = ifac[i-1];
                ifac[i] = (x*y)%mod;
            }

            for(int i = 1000001; i <= 2000000; i++){
        //        cout<<i<<endl;
                long long x = i, y = fac[i-1];
                fac[i] = (x*y)%mod;
            }

            for(int n1 = 1; n1 <= 50; n1++){
                for(int n2 = 1; n2 <= 50; n2++){
                    for(int n3 = 1; n3 <= 50; n3++){
                        int C1 = n1+n2+n3, C2 = n1, C3 = n2, C4 = n3;
                        int A = gumi, B = ia, C = mayu;
                        int n5 = S - A + C2 - C1;
                        int n6 = S - B + C3 - C1;
                        int n4 = S - C + C4 - C1;
                        int n7 = S - (n4+n5+n6) - C1;
                        if(n4 > 0 && n5 > 0 && n6 > 0 && n7 > 0)
                        sol = (sol + fac[S]/(ifac[n1]*ifac[n2]*ifac[n3]*ifac[n4]*ifac[n5]*ifac[n6]*ifac[n7]))%mod;
                    }
                }
            }
            return sol;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 9; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 12; int Arg2 = 8; int Arg3 = 9; int Arg4 = 81451692; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 198591037; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        VocaloidsAndSongs ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
