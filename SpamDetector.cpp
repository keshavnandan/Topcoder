#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class SpamDetector {
        public:
        vs split(string s){
            vs r;
            int i = 0, n = s.size();
            while(i < n){
                string t;
                char c = s[i];
                while(i < n && s[i] == c){
                    t.push_back(c);
                    i++;
                }
                r.push_back(t);
            }
            return r;
        }
        int match(string a, string b){
            for(char &c : a) c = tolower(c);
            for(char &c : b) c = tolower(c);
            vs g1 = split(a), g2 = split(b);
            int ok = 1;
            int n1 = g1.size(), n2 = g2.size();
            if(n1 != n2) return 0;
            for(int i = 0; i < n1; i++){
                string a1 = g1[i], a2 = g2[i];
                if(a1[0] != a2[0] || a1.size() < a2.size()) ok = 0;
            }
            return ok;
        }
        int countKeywords(string subjectLine, vector <string> keywords)
        {
            stringstream ss(subjectLine);
            string a;
            int r = 0;
            while(ss>>a){
                for(string b : keywords){
                    if(match(a, b)){
                        r++;
                        break;
                    }
                }
            }
            return r;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LoooW INTEREST RATES available dont BE slow"; string Arr1[] = {"interest","rates","loan","available","LOW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "Dear Richard Get Rich Quick            no risk"; string Arr1[] = {"rich","risk","Quicken","wealth","SAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "in debbtt againn and aAgain and AGAaiIN"; string Arr1[] = {"AGAIN","again","Again","again"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "PlAyy ThEE Lottto     get Loottoo feever"; string Arr1[] = {"play","lotto","lottery","looser"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, countKeywords(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "                                   "; string Arr1[] = {"empty","space","does","not","match"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countKeywords(Arg0, Arg1)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        SpamDetector ___test;
        ___test.run_test(-1);

}
// END CUT HERE
