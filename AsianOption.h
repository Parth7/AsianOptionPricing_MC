//
// Created by Parth Parakh on 05/12/20.
//

#ifndef ASIANOPTION_PRICER_ASIANOPTION_H
#define ASIANOPTION_PRICER_ASIANOPTION_H

#include<vector>
#include "PayOff.h"

using namespace std;

class AsianOption
{
protected:
    PayOff *payoff;
public:
    AsianOption(PayOff* _payoff);
    virtual ~AsianOption();
    virtual double payoff_price(const vector<double>& spot_prices ) const =0;
};

class AsianOptionArithmetic : public AsianOption
{
public:
    AsianOptionArithmetic(PayOff* _payoff);
    virtual ~AsianOptionArithmetic();
    virtual double payoff_price(const vector<double>& spot_prices ) const;
};

class AsianOptionGeometric : public AsianOption
{
public:
    AsianOptionGeometric(PayOff* _payoff);
    virtual ~AsianOptionGeometric();
    virtual double payoff_price(const vector<double>& spot_prices ) const;
};
#endif //ASIANOPTION_PRICER_ASIANOPTION_H
