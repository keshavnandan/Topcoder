#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
class PassingGrade {
	public:
	int pointsNeeded(vector <int> pointsEarned, vector <int> pointsPossible, int finalExam) {
        int totalEarned = accumulate(pointsEarned.begin(), pointsEarned.end(), 0);
        int total = accumulate(pointsPossible.begin(), pointsPossible.end(), finalExam);
        int req = (int)ceil( (0.65*total) );
        if((totalEarned+finalExam) < req) return -1;
        if(totalEarned > req) return 0;
        return req-totalEarned;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
