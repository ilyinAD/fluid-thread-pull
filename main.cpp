//
// Created by artem on 20.12.2024.
//

#include <bits/stdc++.h>
#include "fluid.h"
#include "fluidwithoutmultithread.h"
using namespace std;

int main() {
    int n = 500;

    Fluid sim;
    clock_t start, finish;
    start = clock();
    sim.run(n);
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << "обычной симулятор " << duration << std::endl;

    FluidWithoutMultiThread sim_1;
    clock_t start1 = clock();
    sim_1.run(n);
    clock_t finish1 = clock();
    double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    std::cout << "улучшенный симулятор без многопоточки " << duration1 << std::endl;
    return 0;
}