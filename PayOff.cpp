//
// Created by Parth Parakh on 05/12/20.
//

#include <algorithm>
#include"PayOff.h"

using namespace std;

PayOff::PayOff() {};
PayOff::~PayOff() {};

PayOffCall::PayOffCall(const double &K_):K(K_) {};
PayOffCall::~PayOffCall() {};

double PayOffCall::operator()(const double &S) const
{
    return max(S-K,0.0);
}

PayOffPut::PayOffPut(const double &K_):K(K_){};
PayOffPut::~PayOffPut() {};

double PayOffPut::operator()(const double &S) const
{
    return max(K-S,0.0);
}



