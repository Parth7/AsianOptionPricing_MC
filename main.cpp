#include <iostream>

#include "payoff.h"
#include "AsianOption.h"
#include "PathGenerator.h"

int main() {
    unsigned num_sims = 100;
    unsigned num_intervals = 250;
    double S = 30.0;
    double K = 29.0;
    double r = 0.08;
    double v = 0.3;
    double T = 1.00;
    std::vector<double> spot_prices(num_intervals, S);

    PayOff* pay_off_call = new PayOffCall(K);

    AsianOptionArithmetic asian(pay_off_call);

    double payoff_sum = 0.0;
    for (int i=0; i<num_sims; i++) {
        calc_path_spot_prices(spot_prices, r, v, T);
        payoff_sum += asian.payoff_price(spot_prices);
    }
    double discount_payoff_avg = (payoff_sum / static_cast<double>(num_sims)) * exp(-r*T);

    delete pay_off_call;

    // Finally we output the parameters and prices
    std::cout << "Number of Paths: " << num_sims << std::endl;
    std::cout << "Number of Ints:  " << num_intervals << std::endl;
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << v << std::endl;
    std::cout << "Maturity:        " << T << std::endl;

    std::cout << "Asian Price:     " << discount_payoff_avg << std::endl;

    return 0;
}