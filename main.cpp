
#include "utilities.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

int main () {
    system("cls");
    
    paire<uint, double> p (1, 5.3);
    cout << p;

    return 0;
}
