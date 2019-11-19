//
// Created by mbdin on 11/19/2019.
//
#include <iostream>
#include <stack>
#include <list>

using namespace std;

#ifndef OS_P3_FIFO_H
#define OS_P3_FIFO_H

class FIFO {
public:
    void set_frames(int page_frames) {
        this->page_frames = page_frames;
cout << "FIFO frames - " << this->page_frames << endl;
    }

    void set_string(list<int> ref_string) {
        this->ref_string = ref_string;
cout << "FIFO reference string - SET" << endl;
    }

private:
    int page_frames, page_faults;
    list<int> ref_string;
};

#endif //OS_P3_FIFO_H
