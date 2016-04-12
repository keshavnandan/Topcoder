#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

class RevolvingDoors
        {
        typedef pair<int, int> pi;
        public:
        bool check(vector<string> v, pi p){
            int n = v.size(), m = v[0].size();
            int move[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
            for(int i = 0; i < 4; i++){
                int a = p.first+move[i][0], b = p.second+move[i][1];
                if(0 <= a && a < n && 0 <= b && b < m && (v[a][b] == ' ')) return true;
            }
            return false;
            }

        vector<string> visit(vector<string> v){
//            cout<<"visit"<<endl;
            int n = v.size();
            int m = v[0].size();
            pi s;
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(v[i][j] == 'S') s = make_pair(i, j);

            int move[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
            queue<pi> Q;
            Q.push(s);
            v[s.first][s.second] = 'x';
            while(!Q.empty()){
                pi t = Q.front();
                Q.pop();
//                print(v);
                int x = t.first, y = t.second;
//                cout<<x<<" "<<y<<endl;
                    if(v[x][y] == 'E'){
                        cout<<"E found"<<endl;
//                        print(v);
                    }
                    if(v[x][y] != 'x'){
                        cout<<"caught "<<x<<" "<<y<<" "<<v[x][y]<<endl;
                        print(v);
                        exit(0);
                    }
//                    v[x][y] = 'x';
                    for(int i = 0; i < 4; i++){
                        int a = x+move[i][0], b = y+move[i][1];
                        if(0 <= a && a < n && 0 <= b && b < m && (v[a][b] == ' ' || v[a][b] == 'E')){
                        Q.push(make_pair(a, b));
                        v[a][b] = 'x';
                        }
                    }
/*
                    Q.push(make_pair(x-1, y));
                    Q.push(make_pair(x+1, y));
                    Q.push(make_pair(x, y-1));
                    Q.push(make_pair(x, y+1));
*/
                }
            return v;
        }
        vector<vector<string> > flip(vector<string> u, vector<string> v, pi p){
            vector<vector<string> > r;
            int x = p.first, y = p.second;
            if(u[x-1][y] == '|'){
                if(u[x-1][y-1] == 'x' || u[x-1][y+1] == 'x'){
                    v[x][y-1] = v[x][y+1] = '-';
                    v[x-1][y] = 'S';
                    v[x+1][y] = ' ';
                    r.push_back(v);
                    v[x-1][y] = ' ';
                }
                if(u[x+1][y-1] == 'x' || u[x+1][y+1] == 'x'){
                    v[x][y-1] = v[x][y+1] = '-';
                    v[x+1][y] = 'S';
                    v[x-1][y] = ' ';
                    r.push_back(v);
                    v[x+1][y] = ' ';
                }
            }
            else{
                if(u[x-1][y-1] == 'x' || u[x+1][y-1] == 'x'){
                    v[x-1][y] = v[x+1][y] = '|';
                    v[x][y-1] = 'S';
                    v[x][y+1] = ' ';
                    r.push_back(v);
                    v[x][y-1] = ' ';
                }
                if(u[x-1][y+1] == 'x' || u[x+1][y+1] == 'x'){
                    v[x-1][y] = v[x+1][y] = '|';
                    v[x][y+1] = 'S';
                    v[x][y-1] = ' ';
                    r.push_back(v);
                    v[x][y+1] = ' ';
                }
            }
            return r;
        }
        void print(vector<string> v){
            int n = v.size();
            int m = v[0].size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++)
                    cout<<v[i][j];
                cout<<endl;
            }
            cout<<endl;
        }
        int turns(vector <string> mp)
            {
                map<vector<string>, int> mv;
                set<pi> sd; pi s, e;
                int n = mp.size(), m = mp[0].size();
                //intialize md
                for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(mp[i][j] == 'O') sd.insert(make_pair(i, j));
                    else if(mp[i][j] == 'S')
                        s = make_pair(i, j);
                    else if(mp[i][j] == 'E') e = make_pair(i, j);
                if(!check(mp, s) || !check(mp, e)) return -1;
                queue<vector<string> > Q;

                mv[mp] = 0;
                Q.push(mp);
                int c = 0;
                while(!Q.empty()){
                    c++;
                    vector<string> v = Q.front();
                    Q.pop();
                    int level = mv[v];
                    if(level > 100) return -1;
//                    cout<<"level = "<<level<<endl;
//                    print(v);
                    for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        if(v[i][j] == 'S') s = make_pair(i, j);
                    vector<string> u = visit(v);
                    if(u[e.first][e.second] == 'x') { cout<<"count = "<<c<<endl; return mv[v];}
                    v[s.first][s.second] = ' ';
                    for(set<pi>::iterator it = sd.begin(); it != sd.end(); it++){
                        pi p = *it;
                        vector<vector<string> > r = flip(u, v, p);
                        if(r.size() >= 1){
                            if(mv.find(r[0]) == mv.end()){
                                mv[r[0]] = level+1;
                                Q.push(r[0]);
                            }
                        }
                        if(r.size() == 2){
                            if(mv.find(r[1]) == mv.end()){
                                mv[r[1]] = level+1;
                                Q.push(r[1]);
                            }
                        }
                    }
                }
                cout<<"count = "<<c<<endl;
                return -1;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "    ### ",
  "    #E# ",
  "   ## # ",
  "####  ##",
  "# S -O-#",
  "# ###  #",
  "#      #",
  "########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, turns(Arg0)); }
	void test_case_1() { string Arr0[] = { "#### ",
  "#S|##",
  "# O #",
  "##|E#",
  " ####" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, turns(Arg0)); }
	void test_case_2() { string Arr0[] = {"S                                                 ", "                                                  ", "                                                  ", "-O--O--O--O--O--O--O--O--O--O-                    ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                  ", "                                                 #", "                                                #E"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, turns(Arg0)); }
	void test_case_3() { string Arr0[] = { "###########",
  "#    #    #",
  "#  S | E  #",
  "#    O    #",
  "#    |    #",
  "#         #",
  "###########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, turns(Arg0)); }
	void test_case_4() { string Arr0[] = { "        E",
  "    |    ",
  "    O    ",
  "    |    ",
  " -O-S-O- ",
  "    |    ",
  "    O    ",
  "    |    ",
  "         " }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, turns(Arg0)); }
	void test_case_5() { string Arr0[] = { "##E#   ",
  "#  ##  ",
  " -O-## ",
  " #  ## ",
  " ##  ##",
  "  -O-  ",
  "##  ## ",
  " # ### ",
  " #  S  " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, turns(Arg0)); }
	void test_case_6() { string Arr0[] = { "#############",
  "#  #|##|#   #",
  "#   O  O    #",
  "# E || || S #",
  "#    O  O   #",
  "#   #|##|#  #",
  "#############" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, turns(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        RevolvingDoors ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
