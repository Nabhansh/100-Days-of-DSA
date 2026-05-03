int missingNumber(int arr[], int n)
{
    int N = n + 1; // total numbers from 1 to N

    long long expected = (long long)N * (N + 1) / 2;
    long long actual = 0;

    for (int i = 0; i < n; i++)
    {
        actual += arr[i];
    }

    return (int)(expected - actual);
}