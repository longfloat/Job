#include <iostream>
#include <algorithm>
using namespace std;

int map[9][9];

bool is_place(int count)
{
	int row = count / 9;
	int col = count % 9;
	int j;
	//ͬһ��
	for(j = 0; j < 9; ++j)
	{
		if(map[row][j] == map[row][col] && j != col)
		{
			return false;
		}
	}
	//ͬһ��
	for(j = 0; j < 9; ++j)
	{
		if(map[j][col] == map[row][col] && j != row)
		{
			return false;
		}
	}
	//ͬһС��
	int tempRow = row / 3 * 3;
	int tempCol = col / 3 * 3;
	for(j = tempRow; j < tempRow + 3; ++j)
	{
		for(int k = tempCol; k < tempCol + 3; ++k)
		{
			if(map[j][k] == map[row][col] && j != row && k != col)
			{
				return false;
			}
		}
	}
	return true;
}
void backtrace(int count)
{
	if(count == 81)
	{
		for(int i = 0; i < 9; ++i)
		{
			for(int j =  0; j < 9; ++j)
			{
				if (j != 8)
					cout << map[i][j] << " ";
				else 
					cout << map[i][j];
			}
			cout << endl;
		}
		return;
	}
	int row = count / 9;
	int col = count % 9;
	if(map[row][col] == 0)
	{
		for(int i = 1; i <= 9; ++i)
		{
			map[row][col] = i;//��ֵ
			if(is_place(count))
			{
				//���Է�
				backtrace(count+1);//������һ��
			}
		}
		map[row][col] = 0;//����
	}
	else
	{
		backtrace(count + 1);
	}
}

int main()
{
	freopen("03.in", "r", stdin);
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			cin >> map[i][j];
		}
	}
	backtrace(0);
	fclose(stdin);
	return 0;
}