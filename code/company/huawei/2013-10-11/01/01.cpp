#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

const int TIMES = 7;

size_t get_reverse(size_t n)
{
	size_t sum = 0;
	size_t last = 0;

	while (n > 0)
	{
		last = n % 10;
		sum = sum * 10 + last;
		n = n / 10;
	}

	return sum;
}

size_t get_palindrome(size_t n)
{
	bool found = false;
	size_t result = n;
	for (size_t i = 0; i < TIMES; ++i)
	{
		size_t p = get_reverse(result);
		size_t sum = p + result;

		result = sum;
		if (sum == get_reverse(sum))
		{
			found = true;
			break;
		}
	}

	if(found)
		return result;
	else
		return 0;
}

int main()
{
	freopen("01.in", "r", stdin);

	size_t n;
	while (cin >> n)
	{
		cout << get_palindrome(n) << endl;
	}

	fclose(stdin);
	return 0;
}