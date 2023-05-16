#include <iostream>
#include <chrono>
#include <typeinfo>
#include <random>
#include <fstream>

int bin_search(int arr[], int arr_sz, int x){
    auto low = 0;
    auto mid = 0;
    auto high = arr_sz - 1;

    while (low < high){
        mid = (low + high) / 2;

        if (x == arr[mid])
        return mid;

        else if (arr[mid] < x)
        low = mid + 1;

        else 
        high = mid - 1;
    }
    return 0;
}

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

int arr[1000000];

int main(){
    std::ofstream searchfile, binfile;
    binfile.open("section1.txt", std::ios_base::app);
    for (int arr_sz = 100; arr_sz <= 1000000; arr_sz += 10000){
        int avg = 0;
        for (int k = 0; k < 100; k++){
                // auto x = generate_x(arr_sz);
                auto x = -1;
                for (int i = 0; i < arr_sz; i++){
                    arr[i] = i;
                }

                auto begin = std::chrono::steady_clock::now();
                bin_search(arr, arr_sz, x);
                auto end = std::chrono::steady_clock::now();
                auto time_span = (end - begin);
                avg += time_span.count();

                /*
                auto begin = std::chrono::steady_clock::now();
                search(arr, x);
                auto end = std::chrono::steady_clock::now();
                searchfile<<time_span.count()<<'\n';
                auto time_span = (end - begin);
                */
        }
        binfile<<(avg / 100)<<'\n';
    }
    binfile.close();
    std::cout<<"Done!"<<std::endl;
    return 0;
}