/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Primes.h
 * Author: Daniel
 *
 * Created on October 19, 2022, 10:42 AM
 */

#ifndef PRIMES_H
#define PRIMES_H

struct Prime{
    unsigned short prime;
    unsigned short power;
};
struct Primes{
    unsigned char nPrimes;
    Prime *prime;
};

#endif /* PRIMES_H */

