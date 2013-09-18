#include <iostream>
using std::cout;
using std::endl;

class Rect
{
public:
	// 构造函数，p指向堆中分配的一空间
	Rect() : p(new int(100))
	{}
	
	// 重新定义拷贝构造函数
	Rect(const Rect& r)
		: width(r.width), height(r.height)
	{
		p = new int; // 为新对象重新动态分配空间
		*p = *(r.p);
	}
		
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

