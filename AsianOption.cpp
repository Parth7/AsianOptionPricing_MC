//
// Created by Parth Parakh on 05/12/20.
//

#include "AsianOption.h"
#include <numeric>
#include <cmath>

using namespace std;

AsianOption:: AsianOption(PayOff *_payoff) : payoff(_payoff) {};
AsianOption::~AsianOption() {};

AsianOptionArithmetic::AsianOptionArithmetic(PayOff *_payoff): AsianOption(_payoff) {};
AsianOptionArithmetic::~AsianOptionArithmetic() {};

double AsianOptionArithmetic::payoff_price(const vector<double> &spot_prices) const
{
    unsigned num_times = spot_prices.size();
    double sum = accumulate(spot_prices.begin(), spot_prices.end(), 0);
    double a_mean = sum / static_cast<double>(num_times);
    return (*payoff)(a_mean);
}

AsianOptionGeometric::AsianOptionGeometric(PayOff *_payoff):AsianOption(_payoff) {};
AsianOptionGeometric::~AsianOptionGeometric() {};

double AsianOptionGeometric::payoff_price(const vector<double> &spot_prices) const
{
    unsigned num_times = spot_prices.size();
    double log_sum = 0.0;
    for(int i=0; i<spot_prices.size(); i++) {
        log_sum += log(spot_prices[i]);
    }
    double g_mean = exp(log_sum / static_cast<double>(num_times) );
    return (*payoff)(g_mean);
}