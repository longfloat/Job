class Rect
{
private:
	int width;
	int height;
};

Rect rect1;
// 使用rect1初始化rect2,
// 此时会进行对象的复制
Rect rect2(rect1);


void fun1(Rect rect)
{
	...
}

int main()
{
	Rect rect1;
	// 此时会进行对象的复制
	fun1(rect1);
	
	return 0;
}


Rect fun2()
{
	Rect rect;
	return rect;
}

int main()
{
	Rect rect1;
	rect1=fun2();	
	// 在fun2返回对象时,会执行对象复制,
	// 复制出一份临时对象,
	// 然后将此临时对象“赋值”给rect1
	return 0;
}

Rect::Rect(const Rect& r)
	: width(r.width), height(r,height)
{}


