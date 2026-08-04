class Solution {
private:                                            //array inherent to object class, won't reset upon each new call to class's climbStairs function
    int combinations[46] = {0};                     //initialize 46 index array to store known n values outside of function call

public:
    int climbStairs(int n) {                        //Recursive

    int distinctWays;

    //Conditionals

    if ( n <= 1) {
        return 1;
    }
    
    else if (combinations[n] != 0) {                //Check in ARRAY if the value has already been calculated
       return combinations[n];
    }

    else 
        distinctWays = climbStairs(n - 1) + climbStairs(n - 2);
        combinations[n] = distinctWays;             //store n values not already manually inserted into array
        return distinctWays;
    }
};