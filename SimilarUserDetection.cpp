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
using namespace std;
typedef pair<int,int> pi;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;

map<char, char> M, N;

class SimilarUserDetection{
 
        public:
        bool isSimilar(string s, string t){
            if(s.size() != t.size()) return false;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != t[i]){
                    if(M.count(s[i]) && M[s[i]] == t[i]) continue;
                    if(N.count(s[i]) && N[s[i]] == t[i]) continue;
                    return false;
                }
            }
            return true;
        }
        string haveSimilar(vector <string> handles) { 
            int n = handles.size();

            M['0'] = 'O';
            M['O'] = '0';
            M['1'] = 'l';
            M['l'] = '1';
            N['1'] = 'I';
            M['I'] = '1';
            N['l'] = 'I';
            N['I'] = 'l';

            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++)
                    if(isSimilar(handles[i], handles[j])) return "Similar handles found";
            }
            return "Similar handles not found";
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"top", "coder", "TOPCODER", "TOPC0DER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles found"; verify_case(0, Arg1, haveSimilar(Arg0)); }
	void test_case_1() { string Arr0[] = {"Topcoder", "topcoder", "t0pcoder", "topcOder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles not found"; verify_case(1, Arg1, haveSimilar(Arg0)); }
	void test_case_2() { string Arr0[] = {"same", "same", "same", "different"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles found"; verify_case(2, Arg1, haveSimilar(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles found"; verify_case(3, Arg1, haveSimilar(Arg0)); }
	void test_case_4() { string Arr0[] = {"i23", "123", "456", "789", "000", "o", "O"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Similar handles not found"; verify_case(4, Arg1, haveSimilar(Arg0)); }

// END CUT HERE
         
}; 
// BEGIN CUT HERE 
int main(){

        SimilarUserDetection ___test; 
        ___test.run_test(-1); 

}
// END CUT HERE 
