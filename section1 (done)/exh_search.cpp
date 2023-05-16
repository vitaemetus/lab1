#include <iostream>
#include <chrono>
#include <typeinfo>
#include <random>
#include <fstream>
#include <algorithm>

int search(int arr[], int arr_sz, int x){
    auto i = 0;

    while (i < arr_sz){
        if(x == arr[i]) {return i;}
        else {i += 1;}
    }
    return -1;
}

int generate_x(int arr_sz){
    auto begin = std::chrono::steady_clock::now();
    auto epoch = begin.time_since_epoch();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

    auto seed = time_span.count();
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, arr_sz - 1);

    int x = dstr(rng);
    x = dstr(rng);
    return(x);
}

void generate_arr(int arr_sz){
    
}

int arr[1000000];

int main(){
    std::ofstream searchfile, binfile;
    binfile.open("exh.txt", std::ios_base::app);
    for (int arr_sz = 100; arr_sz <= 1000000; arr_sz += 1000){
        int avg = 0;
        for (int i = 0; i < arr_sz; i++){
                    arr[i] = i;
                }

        std::shuffle(arr, arr + arr_sz, std::default_random_engine(arr_sz));

        for (int k = 0; k < 100; k++){
                auto x = generate_x(arr_sz);

                auto begin = std::chrono::steady_clock::now();
                search(arr, arr_sz, x);
                auto end = std::chrono::steady_clock::now();
                auto time_span = (end - begin);
                avg += time_span.count();
        }
        binfile<<(avg / 100)<<'\n';
    }
    binfile.close();
    std::cout<<"Done!"<<std::endl;
    return 0;
}