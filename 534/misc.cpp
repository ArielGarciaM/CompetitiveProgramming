#include <iostream>
using namespace std;
#define P1(x) x##x;
#define P2(x) P1(x) ## P1(x);

int main() {
    int P2(c) = 5;
    cout << cccc << endl;
}