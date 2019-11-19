#include <iostream>
#include <stack>
#include <list>
                    // not sure if reference string needs to be string (stack or list is easier)
#include <time.h>

#include "FIFO.h" // First In First Out algorithmn
#include "OPT.h" // Optimal algorithmn
#include "LRU.h" // Least Recently Used algorithmn

using namespace std;

void FIFO_Algorithmn(); // executes all functions from FIFO class
void OPT_Algorithmn(); // executes all functions from OPT class
void LRU_Algorithmn(); // executes all functions from LRU class

list<int> l_rString;
stack<int> s_rString;

int fault_counter = 0,
    page_frames = 5; // DELETE TEMP AMOUNT

int main() {
    srand(time(NULL));

    int page_num; // randomly generated page number
    for (int i = 0; i < 100; i++) {
        page_num = rand() % 50; // provides integer from 0 to 49
        l_rString.push_back(page_num);
        s_rString.push(page_num);
    }

    cout << "Hello, World!" << endl;

    FIFO_Algorithmn();

    return 0;
}

void FIFO_Algorithmn() {
    FIFO fifo;
    fifo.set_frames(page_frames);
    fifo.set_string(l_rString);
}

void OPT_Algorithmn() {
    //
}

void LRU_Algorithmn() {
    //
}