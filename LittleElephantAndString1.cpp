// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LittleElephantAndString
        {
        public:
        void calPos(string A, string B, int pos[]){
            bool done[51];
            fill(done, done+51, false);
            int k = 0, n = A.size();
            while(k < n){
                for(int j = 0; j < n; j++){
                    if(A[j] == B[k] && !done[j]){
                        done[j] = true;
                        pos[j] = k;
                        break;
                    }
                }
                k++;
            }
            for(int i = 0; i < n; i++) cout<<pos[i]<<" ";
            cout<<endl;
        }

        int getNumber(string A, string B)
            {
                int a[26], b[26];
                fill(a, a+26, 0);
                fill(b, b+26, 0);
                int n = A.size();
                for(int i = 0; i < n; i++){
                    a[A[i]-'A']++;
                    b[B[i]-'A']++;
                }
                bool ret = true;
                for(int i = 0; ret && i < 26; i++) if(a[i] != b[i]) ret = false;
                if(!ret) return -1;
                int c = 0;
                int p1=0, p2=n, pos[51];
                calPos(A, B, pos);
                while(pos[p1] != n-1) p1++;
                while(A != B){

                    if(p1+1 < p2){
                        while(p1+1 < p2){
                        p1++;
                        int t = p1, tv = 0;
                        for(int k = p1; k < p2; k++) if(pos[k] > tv){ tv = pos[k]; t = k; }
                        A = A.substr(t, 1) + A.substr(0, t) + A.substr(t+1);
                        c++;
                        cout<<"A = "<<A<<endl;
                        calPos(A, B, pos);
                        cout<<"c = "<<c<<endl;
                        }
                    }
                    else if(p1 > p2){
                        c++;
                        A = A.substr(p1, 1) + A.substr(0, p1) + A.substr(p1+1);
                        cout<<"A = "<<A<<endl;
                        calPos(A, B, pos);
                        cout<<"c = "<<c<<endl;
                    }
                    int k = n; p1 = 0, p2 = 1;
                    while(p1+1 == p2){
                        k--;
                        for(int i = 0; i < n; i++)
                            if(pos[i] == k-1) p1 = i;
                            else if(pos[i] == k) p2 = i;
                    }
                }
                return c;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABABABAB"; string Arg1 = "BBAABBAA"; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "FXTLSGYPSFADPOOEFXZBCOEJUVPVAB"; string Arg1 = "PAFOVEUSCOJBADSELXBGVTFXPZPOFY"; int Arg2 = 28; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAABBB"; string Arg1 = "BBBAAA"; int Arg2 = 3; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "IAIHHIDIDHBAHDEJGFB"; string Arg1 = "IAIDHJAHHIBDGFIBDHE"; int Arg2 = 16; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "KASVWSR"; string Arg1 = "AVSRSKW"; int Arg2 = 5; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZAAAAAAAAAAAAAAAAAAA"; string Arg1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZ"; int Arg2 = 19; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        LittleElephantAndString ___test;
        ___test.run_test(3);
        return 0;
        }
    // END CUT HERE
