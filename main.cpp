#include <iostream>
#include <deque>
#include <fstream>
#include <iterator>
#include <time.h>

#include "FIFO.h" // First In First Out algorithm
#include "OPT.h" // Optimal algorithm
#include "LRU.h" // Least Recently Used algorithm

#define MAX_PAGES 100

using namespace std;

void FIFO_Algorithm(); // executes all functions from FIFO class
void OPT_Algorithm(); // executes all functions from OPT class
void LRU_Algorithm(); // executes all functions from LRU class

void gen_string();
void print_string();

deque<int> ref_string;
ofstream fout("report.txt");
int fault_counter = 0, page_frames = 3; // DELETE TEMP AMOUNT

void display_table(int arr[]) {
    cout << "TABLE -\t";
    for(int i = 0; i < page_frames; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

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

int main() {
    srand(time(NULL));

    //gen_string();
    hw_string();


    fout << "Frames -\t" << page_frames << endl << endl;

    FIFO_Algorithm();
    //OPT_Algorithm();
    LRU_Algorithm();

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
    //
}

void FIFO_Algorithm() {
    FIFO fifo;
    fifo.set_frames(page_frames);
    fifo.set_string(ref_string);
    fifo.load_pages();

    fout << "First In First Out" << endl
         << "Page faults -\t" << fifo.get_faults() << endl << endl;
}

void OPT_Algorithm() {
    OPT opt;
    //opt.set_frames(page_frames);
}

void LRU_Algorithm() {
    LRU lru;
    lru.set_frames(page_frames);
    lru.set_string(ref_string);
    lru.load_pages();

    fout << "Last Recently Used" << endl
         << "Page faults -\t" << lru.get_faults() << endl << endl;
}