//
// Created by artem on 20.12.2024.
//

#include <bits/stdc++.h>
#include <omp.h>
#include "fluid.h"
#include "fluidwithoutmultithread.h"
#include "fluidwithmultithread.h"
using namespace std;

void doCompare(int numThreads) {
    if (numThreads <= 0) {
        cerr << "doCompare: кол во потоков должно быть больше нуля\n";
        exit(-1);
    }
    int n = 500;

    Fluid sim;

    clock_t start, finish;
    start = clock();
    sim.run(n);
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "обычной симулятор " << duration << std::endl;

    FluidWithMultiThread sim_1;
    clock_t start1 = clock();
    sim_1.run(n, numThreads);
    clock_t finish1 = clock();
    double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    cout << "улучшенный симулятор без многопоточки " << duration1 << std::endl;
}











int main(int argc, char* argv[]) {
    cout << argc << endl;
    if (argc < 2) {
        cout << "Запустили сравнение с 7 потоками" << endl;
        doCompare(7);
        return 0;
    }

    bool isMultiThread;
    int amountOfThreads = 0;
    string isCompare = argv[1];
    string mode = argv[2];
    if (mode == "multi") {
        isMultiThread = true;
        if (argc < 3) {
            cerr << "не укащано колво потоков\n";
            return 1;
        }

        amountOfThreads = stoi(argv[2]);
        if (amountOfThreads <= 0) {
            cerr << "колво потоков должно быть больше 0.\n";
            return 1;
        }
    } else if (mode == "single") {
        isMultiThread = false;
    }

    cout << isMultiThread << " " << amountOfThreads << endl;
    if (isCompare == "compare") {
        cout << "Запустили сравнение с" << amountOfThreads << "потоками" << endl;
        doCompare(amountOfThreads);
    }
//    if (isMultiThread) {
//        omp_set_num_threads(amountOfThreads);
//    }
    return 0;
}