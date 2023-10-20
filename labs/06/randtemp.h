#ifndef _RANDTEMP_H_
#define _RANDTEMP_H_

#include<random>

inline int randint(int min, int max)
{
    static std::default_random_engine gen;
    return std::uniform_int_distribution<>(min, max)(gen);//вызов operator()
}

inline int randint(int max){
    return randint(0,max);
}

double normal(double mean, double stddev){
    static std::default_random_engine gen;
    return std::normal_distribution<>(mean,stddev)(gen);
}


#endif //_RANDTEMP_H_