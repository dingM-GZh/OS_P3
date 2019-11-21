//
// Created by mbdin on 11/19/2019.
//
#include <iostream>
#include <deque>

#ifndef OS_P3_OPT_H
#define OS_P3_OPT_H
using namespace std;

class OPT {
private:
    int page_faults = 0, page_frames;
    deque<int> ref_string;
    bool found =  false;

public:
    int get_faults() {
        return this->page_faults;
    }

    void set_frames(int page_frames) {
        this->page_frames = page_frames;
    }

    void set_string(deque<int> ref_string) {
        this->ref_string = ref_string;
    }

    void load_pages() {
        cout << "Optimal" << endl;

        cout << "Page faults -\t" << page_faults << endl << endl;
    }
};

#endif //OS_P3_OPT_H
