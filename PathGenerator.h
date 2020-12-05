//
// Created by Parth Parakh on 05/12/20.
//

#ifndef ASIANOPTION_PRICER_PATHGENERATOR_CPP
#define ASIANOPTION_PRICER_PATHGENERATOR_CPP

#include<cmath>
#include<vector>
#include<random>

using namespace std;

double random_number_generator()
{
    random_device rd{};
    mt19937 gen{rd()};
    normal_distribution<> d{0,1};
    return d(gen);
}

void calc_path_spot_prices(vector<double>& spot_prices,const double& r,const double& v,const double& T)
{
    double dt = T/static_cast<double>(spot_prices.size());
    double drift = exp(dt*(r-0.5*v*v));
    double vol = sqrt(v*v*dt);

    for (int i=1; i<spot_prices.size(); i++)
    {
        double gauss_bm = random_number_generator();
        spot_prices[i] = spot_prices[i-1] * drift * exp(vol*gauss_bm);
    }
}

#endif //ASIANOPTION_PRICER_PATHGENERATOR_CPP
