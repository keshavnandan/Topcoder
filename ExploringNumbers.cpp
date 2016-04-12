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
#include <cmath>
using namespace std;

bool primes[1000];

bool isPrime(int n){

	if(n%2 == 0) return false;
	for(int p = 3; p <= sqrt(n); p += 2){
		if(n%p == 0) return false;
	}
	return true;
}

class ExploringNumbers{
 
        public: 
        int numberOfSteps(int n){
            for(int i = 0; i < 1000; i++) primes[i] = true;
        	for (int p = 2; p*p < 1000; p++)
			{
			    if (primes[p])
			    {
			        for (int i = p*2; i < 1000; i += p)
			            primes[i] = false;
			    }
			}
			primes[0] = primes[1] = false;

			if(n < 1000 && primes[n]) return 1;
			if(n >= 1000 && isPrime(n)) return 1;

			int count = 1, prev = n;
			while(true){
				int next = 0, t = prev;
				count++;

				while(t){
					int rem = t%10;
					next += rem*rem;
					t /= 10;
				}
				// cout<<"next is "<<next<<endl;
				if(next == prev || count >= n) return -1;
				if(primes[next]) return count;

				
				prev = next;
			}
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; verify_case(0, Arg1, numberOfSteps(Arg0)); }
	void test_case_1() { int Arg0 = 57; int Arg1 = 4; verify_case(1, Arg1, numberOfSteps(Arg0)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = -1; verify_case(2, Arg1, numberOfSteps(Arg0)); }
	void test_case_3() { int Arg0 = 6498501; int Arg1 = 2; verify_case(3, Arg1, numberOfSteps(Arg0)); }
	void test_case_4() { int Arg0 = 989113; int Arg1 = 6; verify_case(4, Arg1, numberOfSteps(Arg0)); }
	void test_case_5() { int Arg0 = 12366; int Arg1 = -1; verify_case(5, Arg1, numberOfSteps(Arg0)); }

// END CUT HERE
         
}; 
// BEGIN CUT HERE 
int main(){

        ExploringNumbers ___test; 
        ___test.run_test(-1); 

}
// END CUT HERE 
