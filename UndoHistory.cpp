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
#define sz size()
#define mp(x, y) make_pair(x, y)
#define ri(a, b) for(int i=((int)(a)); i < ((int)(b)); i++)                // i -> [a, b)
#define rie(a, b) for(int i=((int)(a)); i <= ((int)(b)); i++)            // i -> [a, b]
#define rj(a, b) for(int j=((int)(a)); j < ((int)(b)); j++)               // j -> [a, b)
#define rje(a, b) for(int j=((int)(a)); j <= ((int)(b)); j++)           // j -> [a, b]
#define rk(a, b) for(int k=((int)(a)); k < ((int)(b)); k++)           // k -> [a, b)
#define rke(a, b) for(int k=((int)(a)); k <= ((int)(b)); k++)       // k -> [a, b]
#define fi(b) for(int i=0; i < ((int)(b)); i++)                             // i -> [0, b)
#define fie(b) for(int i=0; i <= ((int)(b)); i++)                         // i -> [0, b]
#define fj(b) for(int j=0; j < ((int)(b)); j++)                            // j -> [0, b)
#define fje(b) for(int j=0; j <= ((int)(b)); j++)                        // j -> [0, b]
#define fk(b) for(int k=0; k < ((int)(b)); k++)                        // k -> [0, b)
#define fke(b) for(int k=0; k < ((int)(b)); k++)                      // k -> [0, b]
#define fle(b) for(int l=0; l <= ((int)(b)); l++)                        // l -> [0, b]

class UndoHistory{ 
        public:
        string longestPrefix(string s, set<string> S){
            string maxs;
            for(string t : S)
                if(isPrefix(s, t) && t.size() > maxs.size()) maxs = t;
            return maxs;
        }
        //Returns true if t is substring of s
        bool isPrefix(string s, string t){
            int k = t.size();
            return k <= s.size() && s.substr(0, k) == t;
        }
        int minPresses(vector <string> lines){ 
            string line, buffer;
            set<string> undo;
            int i = 0, n = lines.size(), strokes = 1;
            buffer.push_back(lines[0][0]);
            undo.insert(buffer);
            
            while(i < n){
                string line = lines[i];
                // cout<<"buffer = "<<buffer<<" strokes = "<<strokes<<endl;
                if(buffer == line){
                    strokes++;
                    i++;
                }
                else {
                    string t = longestPrefix(line, undo);
                    if(isPrefix(line, buffer) && t.size() <= buffer.size()+2){
                        int m = buffer.size();
                        buffer.push_back(line[m]);
                        strokes++;
                    }
                    else{
                        buffer = t;
                        strokes += 2;
                    }
                    undo.insert(buffer);
                    // cout<<"buffer = "<<buffer<<" line = "<<line<<endl;
                }
            }
            return strokes;
        }
        
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"tomorrow", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, minPresses(Arg0)); }
    void test_case_1() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minPresses(Arg0)); }
    void test_case_2() { string Arr0[] = {"a", "ab", "abac", "abacus" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minPresses(Arg0)); }
    void test_case_3() { string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(3, Arg1, minPresses(Arg0)); }
    void test_case_4() { string Arr0[] = {"ba","a","a","b","ba"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minPresses(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       UndoHistory ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
