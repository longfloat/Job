
int median(int *a, int *b, int low_a, int high_a, int low_b, int high_b)
{
    if (NULL==a || NULL==b)
    {
        return -1;
    }

    int p = (low_a + high_a) / 2;
    int q = (low_b + high_b) / 2;

    if (a[p] == b[q])
    {
        return a[p];
    }
    else if (a[p] > b[q])
    {
        return median(a, b, low_a, p-1, q+1, high_b);
    }
    else
    {
        return median(a, b, p+1, high_a, low_b, q-1);
    }
}