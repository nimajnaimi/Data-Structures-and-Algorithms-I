#include <list>

#define MAX_SIZE 100

// Used class example as a reference to write this function
void possibleParenthesis(int pos, int n, int open, int closed, std::list<std::string> & result) {
    static char str[MAX_SIZE]; // stores a combination of open and closed brackets
    if (closed == n) {
        result.push_back(str); // store the finished result
        return;
    }

    // must be n number of open brackets
    if (open < n) {
        str[pos] = '{';
        possibleParenthesis(pos + 1, n, open + 1, closed, result);
    }

    // number of open brackets must match number of closed brackets
    if (open > closed) {
        str[pos] = '}';
        possibleParenthesis(pos + 1, n, open, closed + 1, result);
    }
}

// n: size of the problem
// result: a list of string, each string represents a case of valid parentheses of size n
void possibleParenthesis(int n, std::list<std::string> & result)
{
    if (n > 0) {
        possibleParenthesis(0, n, 0, 0, result);
    }
}

