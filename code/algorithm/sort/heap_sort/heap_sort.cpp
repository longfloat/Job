#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;


/**
* 给定堆中某节点下标, 获取其左孩子下标
*/
inline int left(int index)
{
    return 2 * index + 1;
}

template <typename T>
void swap(T &data1, T &data2)
{
	T tmp = data1;
	data1 = data2;
	data2 = tmp;
}

/**
* 从给定节点位置index开始, 调整堆结构, 使以index位置为根的树称为最大堆.
*/
template <typename T>
void max_heap_adjust(vector<T> &data, int index, int length)
{
    int child = left(index);
    T tmp = data[index];
    while (child < length)
    {	
		// 当前调整节点既有左孩子又有右孩子并且左孩子值小于右孩子
        // 则从二者中选出较大者
        if (child != length - 1 && data[child] < data[child + 1])
        {
            ++child;
        }
        
        // 给定根节点的值比左右孩子中较大的要小, 将根节点与此孩子交换
        if (tmp < data[child])
        {
            //swap(data[index], data[child]);
            data[index] = data[child];
        }
        else
        {
			// 否则终止当前调整, 表明以当前节点为根的树符合最大堆特性.
			break;
        }
        
        // 重置要调整的节点和要调整的左孩子
        index = child;
        child = left(index);
    }
    
    data[index] = tmp;
}

template <typename T>
void heap_sort(vector<T> &data)
{
	// 从序列的最后一个非叶子节点开始建堆
	for (int i = (data.size() - 2) / 2; i >=0; --i)
		max_heap_adjust(data, i, data.size());
		
	// 进行堆排序
	for (int j = data.size() - 1; j > 0; --j)
	{
		// 将堆顶元素与末尾元素交换
		swap(data[0], data[j]);
		// 调整交换后的结构使其保持最大堆
		max_heap_adjust(data, 0, j);
	}
}

template <typename T>
void print_vector(vector<T> &vec)
{
	for (vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		cout << *iter << " ";
	
	cout << endl;
}

int main(int argc, const char *argv)
{
	freopen("..\\sort.in", "r", stdin);
	int length;
	while (cin >> length)
	{
		vector<int> iv(length);
		for(int i = 0; i < length; ++i)
			cin >> iv[i];
			
		cout << "before sort:\t";
		print_vector(iv);
		heap_sort(iv);
		cout << "after sort:\t";
		print_vector(iv);
	}
	fclose(stdin);
	return 0;
}