//
// Created by Alexandra on 03.06.2021.
//

#include "templatef.h"
#include<iostream>
#include<vector>



template<class T>
void afismax(std::vector<T> v){
    if(v.size() == 0){
        return;
    }
    T maxim = v[0];
    for(int i = 1; i < v.size(); i++){
        if(maxim < v[i]){
            maxim = v[i];
        }
    }
    std::cout<< maxim <<"\n";
}