#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
int FC[105][105], FP[105][105];
int D[105][105];
int C[105][2], P[105][2];
int n, m;
int cx, px;
typedef pair<int, int> pi;
#define valid(x, y) ( (x) >= 0 && (x) <= n && (y) >= 0 && (y) <= (m) ? 1 : 0 )

class Parking {
        public:
        void bfs(int sx, int sy, char M[105][105]){
            int L[105][105];
            memset(L, -1, sizeof(L));
            L[sx][sy] = 0;
            pi s = make_pair(sx, sy);
            queue<pi> Q;
            Q.push(s);
            while(!Q.empty()){
                pi v = Q.front();
                Q.pop();
                int vx = v.first, vy = v.second;
//                cout<<vx<<" "<<vy<<endl;
                int l = L[vx][vy];

                if(valid(vx, vy) && M[vx][vy] != 'X'){
                    if(valid(vx+1, vy) && L[vx+1][vy] < 0){
                        L[vx+1][vy] = l+1;
                        Q.push(make_pair(vx+1, vy));
                    }
                    if(valid(vx-1, vy) && L[vx-1][vy] < 0){
                        L[vx-1][vy] = l+1;
                        Q.push(make_pair(vx-1, vy));
                    }
                    if(valid(vx, vy+1) && L[vx][vy+1] < 0){
                        L[vx][vy+1] = l+1;
                        Q.push(make_pair(vx, vy+1));
                    }
                    if(valid(vx, vy-1) && L[vx][vy-1] < 0){
                        L[vx][vy-1] = l+1;
                        Q.push(make_pair(vx, vy-1));
                    }
                    if(M[vx][vy] == 'P')
                        D[FC[sx][sy]][FP[vx][vy]] = l;
                }
            }
        }
        int minTime(vector <string> S)
        {
            n = S.size(), m = S[0].size();
            char M[105][105];
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= m; j++)
                    if(!i || !j) M[i][j] = 'X';
                    else M[i][j] = S[i-1][j-1];
            memset(FC, -1, sizeof(FC));
            memset(FP, -1, sizeof(FP));
            memset(D, -1, sizeof(D));
            memset(C, -1, sizeof(C));
            memset(P, -1, sizeof(P));

            cx = 0; px = 0;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++){
                    if(M[i][j] == 'C'){
                        C[cx][0] = i;
                        C[cx][1] = j;
                        FC[i][j] = cx++;
                    }
                    else if(M[i][j] == 'P'){
                        P[px][0] = i;
                        P[px][1] = j;
                        FP[i][j] = px++;
                    }
                }

            cout<<"cx = "<<cx<<" px = "<<px<<endl;
            if(!cx) return 0;
            if(px < cx) return -1;

            for(int i = 0; i < cx; i++)
                bfs(C[i][0], C[i][1], M);
/*
            for(int i = 0; i < cx; i++){
                for(int j = 0; j < px; j++)
                    cout<<D[i][j]<<" ";
                cout<<endl;
            }
*/
            set<int> E;
            for(int i = 0; i < cx; i++)
            for(int j = 0; j < px; j++)
                if(D[i][j] > 0)
                    E.insert(D[i][j]);

            for(set<int>::iterator it = E.begin(); it != E.end(); it++){
                int e = *it;
                cout<<"e = "<<e<<endl;
                int G[105][105];
                int R[105][105];
                memset(G, 0, sizeof(G));
                memset(R, 0, sizeof(R));
                for(int i = 0; i < cx; i++)
                for(int j = 0; j < px; j++)
                    if(D[i][j] <= e && D[i][j] != -1)
                        G[i][j] = 1;
                int MA[105], MB[105], seen[105];
                memset(MA, -1, sizeof(MA));
                memset(MB, -1, sizeof(MB));
                int max_flow = 0;
                for(int i = 0; i < cx; i++){
                    memset(seen, 0, sizeof(seen));
                    if(findMatch(G, i, MA, MB, seen)) max_flow++;
                }

                if(max_flow == cx)  return e;
                cout<<max_flow<<endl;
            }
            return -1;
        }

        bool findMatch(int G[105][105], int i, int MA[105], int MB[105], int seen[105]){

            for(int j = 0; j < px; j++){
                if(G[i][j] && !seen[j]){
                    seen[j] = 1;
                    if(MB[j] == -1 || findMatch(G, MB[j], MA, MB, seen)){
                        MB[j] = i;
                        MA[i] = j;
                        return true;
                    }
                }
            }
            return false;
        }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PDSSED" << endl; else { cerr << "FDILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Drr0[] = {"C.....P",
 "C.....P",
 "C.....P"}; vector <string> Drg0(Drr0, Drr0 + (sizeof(Drr0) / sizeof(Drr0[0]))); int Drg1 = 6; verify_case(0, Drg1, minTime(Drg0)); }
	void test_case_1() { string Drr0[] = {"C.X.....",
 "..X..X..",
 "..X..X..",
 ".....X.P"}; vector <string> Drg0(Drr0, Drr0 + (sizeof(Drr0) / sizeof(Drr0[0]))); int Drg1 = 16; verify_case(1, Drg1, minTime(Drg0)); }
	void test_case_2() { string Drr0[] = {"XXXXXXXXXXX",
 "X......XPPX",
 "XC...P.XPPX",
 "X......X..X",
 "X....C....X",
 "XXXXXXXXXXX"}
; vector <string> Drg0(Drr0, Drr0 + (sizeof(Drr0) / sizeof(Drr0[0]))); int Drg1 = 5; verify_case(2, Drg1, minTime(Drg0)); }
	void test_case_3() { string Drr0[] = {".C.",
 "...",
 "C.C",
 "X.X",
 "PPP"}; vector <string> Drg0(Drr0, Drr0 + (sizeof(Drr0) / sizeof(Drr0[0]))); int Drg1 = 4; verify_case(3, Drg1, minTime(Drg0)); }
	void test_case_4() { string Drr0[] = {"PPPPPPPPPPCCCCCCCCCC",
"PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC", "PPPPPPPPPPCCCCCCCCCC",
"PPPPPPPPPPCCCCCCCCCC" }; vector <string> Drg0(Drr0, Drr0 + (sizeof(Drr0) / sizeof(Drr0[0]))); int Drg1 = 10; verify_case(4, Drg1, minTime(Drg0)); }
	void test_case_5() { string Drr0[] = {"..X..",
 "C.X.P",
 "..X.."}; vector <string> Drg0(Drr0, Drr0 + (sizeof(Drr0) / sizeof(Drr0[0]))); int Drg1 = -1; verify_case(5, Drg1, minTime(Drg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        Parking ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
