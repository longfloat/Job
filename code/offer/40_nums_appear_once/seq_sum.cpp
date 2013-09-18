void print_seq(int small, int big)
{
    for (int i = small; i <= big; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}

void seq_sum(int sum)
{
    if (sum < 2)
    {
        return;
    }

    int small = 1, big = 2;
    int middle = (1 + sum) >> 2;
    int cur_sum = small + big;

    while (small < middle)
    {
        if (cur_sum == sum)
        {
            print_seq(small, big);
        }

        while (cur_sum>sum && small<middle)
        {
            cur_sum -= small;
            ++small;
            if (cur_sum == sum)
            {
                print_seq(small, big);
            }
        }

        ++big;
        cur_sum += big;
    }
}

