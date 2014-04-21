// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

 class QuickSums {
        public:
        int dp[11][101];
        int sums(string numbers, int sum, int i){
            int n = numbers.size();
            if(n-1 == i){
                if(numbers[i] == sum) return 0;
                return -1;
            }
            int a0 = (numbers[i]-'0');
            int a1 = (numbers[1+1]-'0');
            if(n-2 == i){
                if(sum == 10*a0+a1)
                    return 0;
                if(sum == a0+a1)
                   return 1;
                return -1;
            }
            int sum1 = 10*a0+a1, sum2 = a0;
            int rsum1, rsum2;
            if(sum1>sum) rsum1 = -1;
            else  rsum1 = dp[i+2][sum-sum1];
            if(sum2>sum) rsum2 = -1;
            else  rsum2 = dp[i+1][sum-sum2];
            if(rsum1 == -2) rsum1 = sums(numbers, sum-sum1, i+2);
            if(rsum2 == -2) rsum2 = sums(numbers, sum-sum2, i+1);
            if(sum1 != 0 && rsum1 != -1) rsum1++;
            if(sum2 != 0 && rsum2 != -1) rsum2++;
            cout<<i<<". rsum1 = "<<rsum1<<", rsum2 = "<<rsum2<<endl;
            if(rsum1 != -1 && rsum2 != -1)
                return min(rsum1, rsum2);
            if(rsum1 != -1)
                return rsum1;
            if(rsum2 != -1)
                return rsum2;
            return -1;
        }
        int minSums(string numbers, int sum) {

        for(int i = 0; i < 11; i++)
            for(int j = 0; j < 101; j++)
                dp[i][j] = -2;
        return sums(numbers, sum, 0);

          }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "99999"; int Arg1 = 45; int Arg2 = 4; verify_case(0, Arg2, minSums(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1110"; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, minSums(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0123456789"; int Arg1 = 45; int Arg2 = 8; verify_case(2, Arg2, minSums(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999"; int Arg1 = 100; int Arg2 = -1; verify_case(3, Arg2, minSums(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "382834"; int Arg1 = 100; int Arg2 = 2; verify_case(4, Arg2, minSums(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "9230560001"; int Arg1 = 71; int Arg2 = 4; verify_case(5, Arg2, minSums(Arg0, Arg1)); }

// END CUT HERE

 };

    // BEGIN CUT HERE
int main(){
        QuickSums ___test;
        ___test.run_test(-1);
}
    // END CUT HERE
