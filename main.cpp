#include <iostream>
#include <stack>
#include <list>
//                  not sure if reference string needs to be string (stack or list is easier)
#include <time.h>

#include "FIFO.h" // First In First Out algorithmn
#include "OPT.h" // Optimal algorithmn
#include "LRU.h" // Least Recently Used algorithmn

using namespace std;

string test = "TEST";
int main() {
    srand(time(NULL));

    list<int> l_rString;
    stack<int> s_rString;

    int page_num; // randomly generated page number

    for (int i = 0; i < 100; i++) {
        page_num = rand() % 50; // provides integer from 0 to 49
        l_rString.push_back(page_num);
        s_rString.push(page_num);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}