#include <iostream>
#include <chrono>
#include <typeinfo>
#include <random>
#include <fstream>
#include <algorithm>

int generate_x(int arr_sz){
    auto begin = std::chrono::steady_clock::now();
    auto epoch = begin.time_since_epoch();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

    int seed = time_span.count();
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, arr_sz - 1);

    int x = dstr(rng);
    x = dstr(rng);
    return(x);
}

int find_x(int arr[], int arr_sz, int x){
    for (int i1 = 0; i1 < arr_sz; i1++){
        for (int i2 = i1 + 1; i2 < arr_sz; i2++){
            if (arr[i1] + arr[i2] == x){
                return(1);
            }
        }
    }
    return(0);
}

int arr[100000000];

int main(){
    std::ofstream results;
    results.open("N2_random.txt", std::ios_base::app);
    for (int arr_sz = 10; arr_sz <= 1000; arr_sz += 10){
        int avg = 0;
        for (int k = 0; k < 100; k++){
                int x = generate_x(arr_sz);
                for (int i = 0; i < arr_sz; i++){
                    arr[i] = i;
                }
                auto begin = std::chrono::steady_clock::now();
                find_x(arr, arr_sz, x);
                auto end = std::chrono::steady_clock::now();
                auto time_span = (end - begin);
                avg += time_span.count();
        }
        results<<(avg / 100)<<'\n';
    }
    results.close();

    std::ofstream results1;
    results1.open("N2_worst.txt", std::ios_base::app);
    for (int arr_sz = 10; arr_sz <= 1000; arr_sz += 10){
        int avg = 0;
        for (int k = 0; k < 100; k++){
                int x = -1;
                for (int i = 0; i < arr_sz; i++){
                    arr[i] = i;
                }
                auto begin = std::chrono::steady_clock::now();
                find_x(arr, arr_sz, x);
                auto end = std::chrono::steady_clock::now();
                auto time_span = (end - begin);
                avg += time_span.count();
        }
        results1<<(avg / 100)<<'\n';
    }
    results1.close();

    std::cout<<"Done!"<<std::endl;
    return 0;
}