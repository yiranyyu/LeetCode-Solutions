namespace Solution
{
    int getSum(int a, int b) 
    {
        int n_1 = a ^ b;
        int n_2 = a & b;
        if (n_2 == 0) // 不需要进位时
            return n_1;
        return getSum(n_1, n_2 << 1);
    }
};
