/* 
 Editorial link : https://apps.topcoder.com/wiki/display/tc/SRM+456
 IDEA : We use Binary Search to solve this problem. First of all, if you have not come across Binary Search before, refer to this excellent tutorial. 

We ask the question, 'For a certain value check, is it or is it not possible to obtain K sticks of length greater than or equal to check from the given set of sticks using at most C cuts?' If yes, then we have a way of cutting the sticks such that the value of the Kth stick when the sticks are sorted in non-increasing order is atleast check. [Since we have >= K sticks of length >= check]

Notice that if the answer to the question is 'yes' for a certain value check, then it is also 'yes' for all values <= check. It is so, since the same cutting which we did for the value check, will also suffice for any value less than check. It is so because all the K sticks which have length >= check, also have a length >= (the value less than check). Since we have a continuous stretch of 'yes' followed by a continuous stretch of 'no', we can use binary search to find the maximum value for which we get the answer 'yes'. 

Now, we see how to find out whether or not we can get K sticks of length >= check using at most C cuts. 

First, notice that the sticks available must be long enough to provide K sticks of length check. A single stick of length len, can provide at most floor(len/check) sticks of length >= check. 
Hence, total #sticks we can get of length greater than or equal to check is
= can_make = ∑floor(length[i]/check), 0 <= i < size
We need K such sticks at minimum. Hence we have the inequality, ∑floor(length[i]/check) >= K

Second, we must not use more than C cuts to obtain the sticks. For this, we first count the number of sticks of length greater than or equal to check (call this value present) that we have initially. Now, every cut can create at most one new stick of size >= check. Therefore, the maximum total number of sticks of length greater than or equal to check that we can have is (present + C). But we need K such sticks, hence we have the inequality (present + C) >= K. 

Moreover, notice that we can get the required K sticks by repeatedly cutting sticks of length check (to get a new stick of length >= check) from the larger sticks if the above two inequalities are met. 
Hence, the answer >= check if (can_make >= K && present + C >= K), else answer < check
We can do the Binary search using the above information after initializing the lower and upper bounds appropriately.
One must be careful to use 64-bit integers to compute the value can_make, since using a 32-bit integer can cause overflow. 

The following C++ code solves the problem by using the above idea:-
*/
double maxKth(vector <int> sticks, int C, int K)
    {
        sort(sticks.begin(), sticks.end(), greater<int>());
        double low = 0.0; double high = sticks[0];
        long long can_make, present;

        // Repeat binary search a fixed number of times to deal with precision
        // instead of comparing doubles
        for (int i = 0; i < 500; i++)
        {
            double mid = (high + low)/2.0;
            can_make = present = 0LL;
            // Count the #pieces of length >= mid you can make
            // and the #pieces of length >= mid you already have
            for (int j = 0; j < sticks.size(); j++)
                {
                    can_make += (long long)(double(sticks[j])/mid);
                    present += (((long long)(double(sticks[j])/mid))?1LL:0LL);
                }
            // Check if the constraints are satisfied
            if (can_make >= K && C+present >= K) low = mid;
            else high = mid;
        }
        return low;
    }
