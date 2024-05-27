// single number which appeared once else twice

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 2, 1};
    cout << singleNumber(nums) << endl;
    return 0;
}