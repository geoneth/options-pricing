#include <iostream>
#include <vector>
#include <cmath>


struct Node{
    double value;
    int ups;
    int downs;
}



class binomial{
    public:
        
        double S;
        double K;
        double r;
        double T;
        double sigma;
        int n;
        double delta_t;
        double u;
        double d;
        double p;
        std::vector<double> final_tree_row;


        binomial(double InitialStockPrice, double StrikePrice, double RiskFreeRate, double TimeToExpiration, double volatility, int StepsInTree){
            S = InitialStockPrice;
            K = StrikePrice;
            r = RiskFreeRate;
            T = TimeToExpiration;
            sigma = volatility;
            n = StepsInTree;
            delta_t = find_delta_t();
            u = find_up_factor();
            d = find_down_factor();
            p = find_risk_neutral_probability();
            final_tree_row = make_row_n();
        
        }

        double find_delta_t(){
            return T/n;
        }

        double f:ind_up_factor(){
            return std::exp(sigma * std::sqrt(delta_t));
        }

        double find_down_factor(){
            return std::exp(-sigma * std::sqrt(delta_t));
        }

        double find_risk_neutral_probability(){
            return (std::exp(r*delta_t)-d)/(u - d);
        }

        std::vector<double> make_row_n(){
            std::vector<double> row;
            for (int i = 0; i <= n; i++){ //the final row of a binary tree with have n+1 nodes and each node will have n total up and down factors
                Node temp;
                temp.ups = n - i;
                temp.downs = i;
                temp.value = S * std::pow(u, temp.ups) * std::pow(d, temp.downs);
                row.push_back(temp);
            }
            return row;
                

        }

        double call(){
            call_final_row = final_tree_row; //make a copy so i can change it, it would prob be better to add to my struct but this is how it makes more sense to me
            for (int i = 0; i<=n; i++){

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
