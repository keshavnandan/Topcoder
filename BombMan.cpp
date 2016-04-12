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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
struct  state
{
	int x, y, t, b;
	state(int x, int y, int t, int b) : x(x), y(y), t(t), b(b) {}
};
bool operator<(state a, state b){
	if(a.t != b.t) return a.t > b.t;
	return a.b < b.b;
}

class BombMan{ 
        public: 
        int shortestPath(vector <string> maze, int bombs) {
        	int n = maze.size(), m = maze[0].size();
       		int dx[4] = {1, 0, -1, 0};
       		int dy[4] = {0, 1, 0, -1};
       		priority_queue<state> Q;
       		int bx = 0, by = 0, ex = 0, ey = 0;
       		for(int i = 0; i < n; i++)
       			for(int j = 0; j < m; j++)
       				if(maze[i][j] == 'B'){
       					bx = i;
       					by = j;
       				}
       				else if(maze[i][j] == 'E'){
       					ex = i;
       					ey = j;
       				}
       		cout<<"bx = "<<bx<<" by = "<<by<<endl;
       		cout<<"ex = "<<ex<<" ey = "<<ey<<endl;
       		
       		vvi visited(n, vi(m, 0));
       		Q.push(state(bx, by, 0, bombs));
       		while(!Q.empty()){
       			state p = Q.top();
       			Q.pop();
       			int x = p.x, y = p.y, t = p.t, b = p.b;
       			if(visited[x][y]) continue;
       			// cout<<x<<" "<<y<<" "<<t<<" "<<b<<endl;
       			if(x == ex && y == ey) return t;
       			visited[x][y] = 1;
       			for(int k = 0; k < 4; k++){
       				int xx = x+dx[k], yy = y+dy[k];
       				if(0 <= xx && xx < n && 0 <= yy && yy < m){
       					if(maze[xx][yy] == '#'){
							if(b > 0) Q.push(state(xx, yy, t+3, b-1));
						}
       					else Q.push(state(xx, yy, t+1, b));
       				}
       			}
       		}
           	return -1;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....B.",
 ".#####.",
 ".#...#.",
 ".#E#.#.",
 ".###.#.",
 "......."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; verify_case(0, Arg2, shortestPath(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"B.#.#.#...E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = -1; verify_case(1, Arg2, shortestPath(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..#####",
 "B.#####",
 "..#####",
 "#######",
 "####...",
 "####.E."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 17; verify_case(2, Arg2, shortestPath(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".#.#.#.#B#...#.#...#.#...#.#...#.#...#.#.#.......",
 ".#.#.#.#.#.###.###.#.###.#.#.###.###.#.#.#.###.##",
 ".#.#.#...#.#.#.#.#.#...#.....#.#.#...#...#.#.#...",
 ".#.#.###.#.#.#.#.#.###.#.#####.#.###.###.#.#.###.",
 ".............#.#...#...#.....#.#.#...#.#.#.....#.",
 "##.#######.###.#.#####.#.#####.#.###.#.#.#.#.####",
 ".#.#.....#...#...#.#...#...#.#.#...#...#...#.....",
 ".#######.#.#####.#.#.#.#.###.#.###.#.#####.#.####",
 ".#.#.#.#...#.#.#.#.#.#.......#...#.#...#.#.#.....",
 ".#.#.#.###.#.#.#.#.#####.#####.###.###.#.#.######",
 ".....#...#.#...#...#...#...#...#...#.#.#.........",
 "####.###.#.###.###.#.###.#.#.###.###.#.#.########",
 ".......#.........#.#.#.#.#.#.#.#.........#...#...",
 ".#.###.#########.#.#.#.#.###.#.#####.#.#.#.###.##",
 ".#.#.........#.#.#.#.#.....#.#.#.....#.#.........",
 "############.#.#.#.#.#.#####.#.#.################",
 ".#...........#...#.#.#.#...#.#.#...#.#.#.....#...",
 ".#####.#####.###.#.#.#.#.###.#.#.###.#.#.#####.##",
 ".......#...#.#.#.....#...#...#.#.#.#.#...........",
 "##########.#.#.#####.#.###.###.#.#.#.#.##########",
 ".....#...#.....#.#...#.......#.#...#.......#.....",
 "##.#.###.#.###.#.#.#.#.#####.#.#.###.#######.####",
 "...#...#...#.......#.....#.#...#...#.......#.....",
 "####.#.#.#########.#.###.#.#####.###.#.#######.##",
 ".#...#...#.........#.#.....#.........#.#.#.#.....",
 ".#####.#.#.###.#######.#.###.#.#########.#.#.####",
 ".......#.#.#...#.......#.....#.#.#.......#.#.#.#.",
 "########.#.#.#.#####.#.###.#.###.#.#######.#.#.#.",
 ".........#.#.#.#.....#...#.#.........#.#.........",
 "################.#.#.#.#.#.#.#.#######.#.########",
 ".................#.#.#.#.#.#.#...........#.......",
 "########.#####.#.###.#.#.#####.###.#.#####.###.##",
 ".........#...#.#...#.#.#...#.....#.#.........#...",
 ".#####.#####.#.###.#.###.#.#.#.#.#.#####.#.###.#.",
 ".#.....#.........#.#.#...#.#.#.#.#.#.....#...#.#.",
 "####.#####.###.#.#.#.#.#.#.###.###.#.#.#.#.#####.",
 ".....#.....#.#.#.#.#.#.#.#.#...#...#.#.#.#...#...",
 "####.#.#.###.#.#.###.#.###.#.#.#####.#.#.#.######",
 ".....#.#.#.#...#...#.#...#.#.#...#...#.#.#.......",
 "##########.#.#.#.#####.###.#.#.###.#.###.#####.##",
 "...#.#...#...#.#.....#.#...#.#...#.#.#.......#...",
 ".#.#.#.#.#.#.#.#.#.#.###.#.#########.###.#.#.#.#.",
 ".#.#...#...#.#.#.#.#...#.#...#.......#...#.#.#.#.",
 "##.###.#.#.###.#.#.#.#.#####.#.#.#.###.#.########",
 ".......#.#...#.#.#.#.#.#.....#.#.#...#.#.........",
 "####.#######.#.#####.#.###.#.#.###.#.#.#.########",
 "E..#.......#.#.....#.#.#.#.#.#.#...#.#.#.........",
 "##.#.#.#.###.###.###.###.#.#.###.#.#.#.#.#######.",
 ".....#.#...#.#.....#.#.....#...#.#.#.#.#.....#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 76; verify_case(3, Arg2, shortestPath(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        BombMan ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
