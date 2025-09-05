#include <iostream>
#include <cmath>


struct Node{
    double value;



class binomial{
    public:
        
        double S;
        double K;
        double r;
        double T;
        double sigma;
        int n;


        binomial(double InitialStockPrice, double StrikePrice, double RiskFreeRate, double TimeToExpiration, double volatility, int trials){
            S = InitialStockPrice;
            K = StrikePrice;
            r = RiskFreeRate;
            T = TimeToExpiration;
            sigma = volatility;
            n = trials
        }

        double call(){
            //makes it a call list
            //return calculate()
        }

        double put(){
            //makes it a put
            //return calculate()
        }

        double calculate(){
            //will take in the final row list
            //does the summation and multiplication
            //return value
        }
};
