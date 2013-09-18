#include <iostream>
using std::cout;
using std::endl;

class Rect
{
public:
	// 构造函数，p指向堆中分配的一空间
	Rect() : p(new int(100))
	{}
		
	// 析构函数，释放动态分配的空间
	~Rect()
	{
		cout << "p=" << p << endl;
		if(p != NULL)	
		{
			delete p;
		}
	}
private:
	int width;
	int height;
	int *p; // 一指针成员
};

int main()
{
	Rect rect1;
	Rect rect2(rect1); // 复制对象
	return 0;
}

