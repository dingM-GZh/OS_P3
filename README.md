# Page Replacement
Program the implements three virtual memory page replacement algorithms. The goal is to compare and assess the impact of these algorithms on the number of page faults incurred across a varying number of physical-memory page frames available

## Execution
To compile the program, enter the command `g++ -std=c++11 main.cpp FIFO.h LRU.h OPT.h`.
To run the program, enter the command `./a.out #` where _#_ is any integer greater than 0 (the number of page frames of the page table). 
A file named `report.txt` will be created and containing the number of page frames, page faults, and reference string. 
