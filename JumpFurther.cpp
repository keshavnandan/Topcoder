#include <vector>
#include <string>
using namespace std;

class JumpFurther {
public:
    int furthest(int N,
                 int badStep) {

        int first = 1, t = 0;
        for(int i = 0; i <= N; i++){
           t += i;
           if(t == badStep) first = 0;
        }
        if(first) return t;
        return t-1;
    }
};
