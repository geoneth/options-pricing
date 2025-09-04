#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>

class bs_closed{

    public:

        double T;
        double S;
        double K;
        double r;
        double sigma;
        double value_d1;
        double value_d2;


        bs_closed(double TimeToMaturity, double StockPrice, double StrikePrice, double RiskFreeRate, double Volatility){
            T = TimeToMaturity;
            S = StockPrice;
            K = StrikePrice;
            r = RiskFreeRate;
            sigma = Volatility;
            value_d1 = d1();
            value_d2 = d2();
        }

        double call(){
            return (N(value_d1) * S) - (N(value_d2) * K * std::exp(-r*T));
        }

        double put(){
            return (K * std::exp(-r * T) * N(-1 * value_d2)) - (S * N(-1 * value_d1));
        }

        double d1(){
            return ((std::log(S/K)) + (r + (sigma * sigma)/2)*T)/(sigma * std::sqrt(T)); 
        }

        double d2(){
            return value_d1 - (sigma * std::sqrt(T));

        }

        double N(double Z_score){
            boost::math::normal_distribution<> standard_normal;
            return boost::math::cdf(standard_normal, Z_score);
        }

};

