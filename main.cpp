#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <deque>
#include <fstream>
#include <time.h>

#include "FIFO.h" // First In First Out algorithm
#include "OPT.h" // Optimal algorithm
#include "LRU.h" // Last Recently Used algorithm

#define MAX_PAGES 100
#define SEED (time(NULL))

using namespace std;

void FIFO_Algorithm(); // executes all functions from FIFO class
void OPT_Algorithm(); // executes all functions from OPT class
void LRU_Algorithm(); // executes all functions from LRU class

void gen_string();
void print_string();
void print_results(int, int);

deque<int> ref_string;
ofstream fout("report.txt");
int page_frames; //= 3; // DELETE TEMP AMOUNT

/*
void hw_string() {
    // 7, 2, 3, 1, 2,
    ref_string.push_back(7);
    ref_string.push_back(2);
    ref_string.push_back(3);
    ref_string.push_back(1);
    ref_string.push_back(2);
    // 5, 3, 4, 6, 7,
    ref_string.push_back(5);
    ref_string.push_back(3);
    ref_string.push_back(4);
    ref_string.push_back(6);
    ref_string.push_back(7);
    // 7, 1, 0, 5, 4,
    ref_string.push_back(7);
    ref_string.push_back(1);
    ref_string.push_back(0);
    ref_string.push_back(5);
    ref_string.push_back(4);
    // 6, 2, 3, 0, 1
    ref_string.push_back(6);
    ref_string.push_back(2);
    ref_string.push_back(3);
    ref_string.push_back(0);
    ref_string.push_back(1);

}
 */

int main(int argc, char *argv[]) {
    srand(SEED);
    page_frames = atoi(argv[1]);

    if (page_frames < 1) {
        cout << "ERROR - INVALID NUMBER OF PAGE FRAMES" << endl
             << "PLEASE ENTER AN INTEGER GREATER THAN 0" << endl;
    }
    else {
        gen_string();
        //hw_string();
        print_string();

        cout << "Frames -\t" << page_frames << endl << endl;
        fout << "Frames -\t" << page_frames << endl << endl;

        FIFO_Algorithm();
        OPT_Algorithm();
        LRU_Algorithm();
    }

    fout.flush();
    fout.close();
    return 0;
}

void gen_string() {
    int page_num; // randomly generated page number
    for (int i = 0; i < MAX_PAGES; i++) {
        page_num = rand() % 50; // provides integer from 0 to 49
        ref_string.push_back(page_num);
    }
}

void print_string() {
    fout << "Page Reference String - " << ref_string.size() << endl;
    for (int i = 0; i < ref_string.size(); i++) {
        fout << ref_string[i] << ' ';
    }
    fout << endl << endl;
}

void print_results(int algorithm, int faults) {
    switch (algorithm) {
        case 1:
            fout << "First In First Out" << endl;
            break;
        case 2:
            fout << "Last Recently Used" << endl;
            break;
        case 3:
            fout << "Optimal" << endl;
            break;
        default:
            cout << "ERROR - ALGORITHM DOESN'T EXIST" << endl;
    }
    fout << "Page faults -\t" << faults << endl << endl;
}

void FIFO_Algorithm() {
    FIFO fifo;
    fifo.set_frames(page_frames);
    fifo.set_string(ref_string);
    fifo.load_pages();

    print_results(1, fifo.get_faults());
}

void OPT_Algorithm() {
    OPT opt;
    opt.set_frames(page_frames);
    opt.set_string(ref_string);
    opt.load_pages();

    print_results(3, opt.get_faults());
}

void LRU_Algorithm() {
    LRU lru;
    lru.set_frames(page_frames);
    lru.set_string(ref_string);
    lru.load_pages();

    print_results(2, lru.get_faults());
}