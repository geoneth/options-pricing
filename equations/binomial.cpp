/*
 * okk so pretty much i need to make a binary tree
 * inital price can go up or down  repeat n titimes
 * once tree is built calc s_t to find call and put prices
 * once you know call and put prices go to the previous node and use the call and put prices
 * along with magic probability to find the call and put values of that node
 * repeat this till you arive at node n=0
 * */

/*
 * ok so for this i imagine that ill create a struct that can contain a value v
 * a bool of retraced an int of how many ups an int of how many down and
 * pointers to the next node up and the next node down then i can just traverse this tree running equations
 */
struct Node{
    double price;
    int u;
    int d;
    bool traversed;
    Node* left;
    Node* right;
