#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
using namespace std;

class SmartWordToy
        {
        public:
        struct node{
            string s;
            int level;
            node(string s = "", int l = 0): s(s), level(l){}
            bool operator<(node &b){
                return s < b.s;
            }
        };
        set<string> gen(vector<string> v){

            sort(v.begin(), v.end());
            v = vector<string>(v.begin(), unique(v.begin(), v.end()));
            if(v.empty()) return set<string>();

            if(v.size() > 1){
                set<string> s1 = gen(vector<string>(v.begin(), v.begin()+1));
                set<string> s2 = gen(vector<string>(v.begin()+1, v.end()));
                s1.insert(s2.begin(), s2.end());
                return s1;
            }

            if(v[0].size() == 7){

                set<string> S;
                string st(4, 'x');
                st[0] = v[0][0]; st[1] = v[0][2]; st[2] = v[0][4]; st[3] = v[0][6];
//                cout<<st<<endl;
                S.insert(st);
                return S;
            }

            string a[4], b[4];
            stringstream ss(v[0]);
            int i = 0;
            string s;
            bool done = false;
            while(ss>>s){
                if(s.size() == 1 || done){
                    a[i] = b[i] = s;
                }
                else if(!done){
                    a[i] = s.substr(0, 1);
                    b[i] = s.substr(1);
                    done = true;
                }
                i++;
            }
            vector<string> v1, v2;
            v1.push_back(a[0]+" "+a[1]+" "+a[2]+" "+a[3]);
            v2.push_back(b[0]+" "+b[1]+" "+b[2]+" "+b[3]);
            set<string> s1 = gen(v1);
            set<string> s2 = gen(v2);
            s1.insert(s2.begin(), s2.end());
            return s1;
        }

        int minPresses(string start, string finish, vector <string> forbid)
            {
                int k = 0;
                set<string> S = gen(forbid);
                if(S.find(finish) != S.end()) return -1;
                cout<<"done boss....:)"<<endl;
                queue<node> Q;
                node p = node(start, 0);
                Q.push(p);
                string s, t;
                while(!Q.empty()){
                    p = Q.front();

                    if(p.s == finish) return p.level;
                    Q.pop();
                    if(S.find(p.s) == S.end()){
                        k++;
//                        cout<<p.s<<"\t"<<p.level<<"\t"<<k<<endl;
                        S.insert(p.s);
                        s = p.s;
                        for(int i = 0; i < 4; i++){
                            t = s;
                            t[i] = (s[i] == 'z' ? 'a' : s[i]+1);
                            Q.push(node(t, p.level+1));
                            t[i] = (s[i] == 'a' ? 'z' : s[i]-1);
                            Q.push(node(t, p.level+1));
                        }
                    }
                }
                return -1;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "mmnn"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; verify_case(2, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"bz a a a", "a bz a a", "a a bz a", "a a a bz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaa"; string Arg1 = "zzzz"; string Arr2[] = {"cdefghijklmnopqrstuvwxyz a a a",
 "a cdefghijklmnopqrstuvwxyz a a",
 "a a cdefghijklmnopqrstuvwxyz a",
 "a a a cdefghijklmnopqrstuvwxyz"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(4, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "aaaa"; string Arg1 = "bbbb"; string Arr2[] = {"b b b b"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(5, Arg3, minPresses(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "zzzz"; string Arg1 = "aaaa"; string Arr2[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",
 "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, minPresses(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        SmartWordToy ___test;
        ___test.run_test(2);
        ___test.run_test(6);
     }
// END CUT HERE

