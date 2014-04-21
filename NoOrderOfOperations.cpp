#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

class NoOrderOfOperations {
public:
	int evaluate(string);
	int oper(int x, char op, int y){
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
	}
};

int NoOrderOfOperations::evaluate(string expr) {
    int sum = expr[0] - '0';
    char op = '\0';
    for(int i = 1; i < expr.size(); i++){
        char c = expr[i];
        if(isdigit(expr[i])) sum = oper(sum, op, c-'0');
        else op = c;
    }
    return sum;
}

int main(){

}
