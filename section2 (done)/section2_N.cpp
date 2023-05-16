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

int find_x_smart(int* beg, int* end, int x){
    int cur_sum;
    while (beg != end){
        cur_sum = *beg + *end;
        if (cur_sum < x){
            beg += 1;
        }
        else if (cur_sum > x){
            end -= 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int arr[100000000];

int main(){
    std::ofstream results;
    results.open("N_random.txt", std::ios_base::app);
    for (int arr_sz = 10; arr_sz <= 1000; arr_sz += 10){
        int avg = 0;
        for (int k = 0; k < 100; k++){
                //int x = -1;
                int x = generate_x(arr_sz);
                for (int i = 0; i < arr_sz; i++){
                    arr[i] = i;
                }
                //std::shuffle(arr, arr + arr_sz, std::default_random_engine(arr_sz));
                std::cout<<arr_sz<<' ';
                auto begin = std::chrono::steady_clock::now();
                find_x_smart(arr, arr+arr_sz, x);
                auto end = std::chrono::steady_clock::now();
                auto time_span = (end - begin);
                avg += time_span.count();
        }
        results<<(avg / 100)<<'\n';
    }
    results.close();
    std::cout<<"Done!"<<std::endl;
    return 0;
}
