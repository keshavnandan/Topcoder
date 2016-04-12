#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

class SmartWordToy
        {
        public:

        int encode(string s){
            int a = s[3], b = s[2], c = s[1], d = s[0];
            int r = a + (b<<5) + (c<<10) + (d<<15);
//            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<r<<endl;
            return r;
        }

        int* dist = new int[1 + encode("zzzz")];
        int* que = new int[1 + encode("zzzz")];

        void gen(vector<string> v){

            if(v.empty()) return ;
            sort(v.begin(), v.end());
            v = vector<string>(v.begin(), unique(v.begin(), v.end()));
            for(int i = 0; i < v.size(); i++){
                string a, b, c, d;
                stringstream ss(v[i]);
                ss>>a>>b>>c>>d;
                for(int x = 0; x < a.size(); x++)
                    for(int y = 0; y < b.size(); y++)
                        for(int z = 0; z < c.size(); z++)
                            for(int w = 0; w < d.size(); w++)
                                {
                                    string s(4, 'x');
                                    s[0] = a[x];
                                    s[1] = b[y];
                                    s[2] = c[z];
                                    s[3] = d[w];
                                    dist[encode(s)] = -10;
//                                    cout<<s<<endl;
                                }
            }
        }
//{"xrym", "oxyu", {"q qr xtmbowg xfpugcd", "fagrwco wqhcvoagfm p lyxuir", "pndlieywcs fbph yfmwi teipcwsdm", "blpjiqy cwvnha pfyl lwdpicb"}}
//{"zzzz", "aaaa", {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkm abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkn abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijko abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkp abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkq abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijks abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkt abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijku abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkv abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkw abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkx abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijky abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkz abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijnl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijol abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijpl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijql abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijrl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijsl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijtl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijul abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijvl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijwl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijxl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijyl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijzl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghinkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiokl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghipkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiqkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghirkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiskl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghitkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiukl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghivkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiwkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghixkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiykl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghizkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghnjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghojkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghpjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghqjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghrjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghsjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghtjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghujkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghvjkl abcdefghijkl abcdefghijkl abcdefghijk"}}
        int minPresses(string start, string finish, vector <string> forbid)
            {

                for(int i = 0; i <= encode("zzzz"); i++) dist[i] = -1;
//                memset(dist, '0', (encode('zzzz')+1)*sizeof(int));
                gen(forbid);
                if(dist[encode(finish)] == -10) return -1;
//                cout<<"done boss....:)"<<endl;
                queue<string> Q;
                string p = start;
                Q.push(p);
                dist[encode(p)] = 0;
                string s, t;
                int i = 0, j = 0, k = 0, l = 0;

                while(!Q.empty()){
                    s = Q.front();
                    int l = encode(s);
                    if(s == finish) {
//                        cout<<"yes!!!..."<<s<<endl;
                        return dist[l];
                    }
                    Q.pop();
                    k++;
//                    cout<<s<<"\t"<<dist[l]<<"\t"<<k<<endl;

                    for(i = 0; i < 4; i++){
                        t = s;
                        t[i] = (s[i] == 'z' ? 'a' : s[i]+1);
                        j = encode(t);
                        if(dist[j] == -1){
                            Q.push(t);
                            dist[j] = dist[l] + 1;
                        }
                        t[i] = (s[i] == 'a' ? 'z' : s[i]-1);
                        j = encode(t);
                        if(dist[j] == -1){
                            Q.push(t);
                            dist[j] = dist[l] + 1;
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
	void test_case_6() { string Arg0 = "zzzz"; string Arg1 = "aaaa"; string Arr2[] = {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkm abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkn abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijko abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkp abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkq abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijks abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkt abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijku abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkv abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkw abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkx abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijky abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijkz abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijnl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijol abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijpl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijql abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijrl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijsl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijtl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijul abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijvl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijwl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijxl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijyl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghijzl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghinkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiokl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghipkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiqkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghirkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiskl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghitkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiukl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghivkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiwkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghixkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghiykl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghizkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghnjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghojkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghpjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghqjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghrjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghsjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghtjkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghujkl abcdefghijkl abcdefghijkl abcdefghijk", "abcdefghvjkl abcdefghijkl abcdefghijkl abcdefghijk"};
  vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, minPresses(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        SmartWordToy ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
