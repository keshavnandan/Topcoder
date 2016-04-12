#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

class CaptureThemAll
        {
        public:
        typedef pair<int, int> pi;
        int bfs(pi s, pi d){
                int m[8][2] = { {1,2}, {-1,2}, {1,-2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};
                int dist[8][8];
                for(int i = 0; i < 8; i++)
                for(int j = 0; j < 8; j++)
                    dist[i][j] = -1;
                queue<pi> Q;
                int p1 = s.first, p2 = s.second;
                int x, y;
                Q.push(s);
                dist[p1][p2] = 0;

                while(!Q.empty()){

                    pi p = Q.front();
                    p1 = p.first; p2 = p.second;
//                    cout<<p1<<" "<<p2<<" "<<dist[p1][p2]<<endl;
                    Q.pop();
                    if(p == d)
                    return dist[p1][p2];
                    for(int i = 0; i < 8; i++){
                        x = p1+m[i][0]; y = p2+m[i][1];
                        if(x >= 0 && x < 8 && y >= 0 && y < 8){
                            dist[x][y] = dist[p1][p2]+1;
                            Q.push(make_pair(x, y));
                        }
                    }
                }
        }

        int fastKnight(string knight, string rook, string queen)
            {
                pi k, r, q;
                k = make_pair(knight[0]-'a', knight[1]-'1');
                r = make_pair(rook[0]-'a', rook[1]-'1');
                q = make_pair(queen[0]-'a', queen[1]-'1');
                int d1 = bfs(k, q), d2 = bfs(k, r), d3 = bfs(q, r);
                return min(d1,d2)+d3;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a1"; string Arg1 = "b3"; string Arg2 = "c5"; int Arg3 = 2; verify_case(0, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "b1"; string Arg1 = "c3"; string Arg2 = "a3"; int Arg3 = 3; verify_case(1, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "a1"; string Arg1 = "a2"; string Arg2 = "b2"; int Arg3 = 6; verify_case(2, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "a5"; string Arg1 = "b7"; string Arg2 = "e4"; int Arg3 = 3; verify_case(3, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "h8"; string Arg1 = "e2"; string Arg2 = "d2"; int Arg3 = 6; verify_case(4, Arg3, fastKnight(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        CaptureThemAll ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
