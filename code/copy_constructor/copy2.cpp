#include <iostream>
using std::cout;
using std::endl;

class Rect
{
public:
	Rect() // 构造函数,计数器加1
	{
		count++;
	}
	
	Rect(const Rect& r) : width(r.width), height(r.height)
	{
		count++;
	}
	
	~Rect() // 析构函数,计数器减1
	{
		count--;
	}
	
	// 返回计数器的值
	static int getCount()
	{
		return count;
	}
private:
	int width;
	int height;
	static int count; // 一个静态成员作为计数器
};

int Rect::count = 0; // 初始化计数器

int main()
{
	Rect rect1;
	cout<<"The count of Rect: "<<Rect::getCount()<<endl;
	Rect rect2(rect1); // 使用rect1复制rect2,此时应该有两个对象
	cout<<"The count of Rect: "<<Rect::getCount()<<endl;
	return 0;
}

