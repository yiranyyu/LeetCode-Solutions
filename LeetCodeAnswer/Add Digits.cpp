namespace Solution
{
    int addDigits(int num) 
    {
        int next = num % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        next += (num /= 10) % 10;
        int second = next % 10;
        second += (next /= 10) % 10;
        int ans = second % 10;
        ans += (second /= 10) % 10;
        return ans;
    }
}
