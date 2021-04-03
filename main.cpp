#include <iostream>
#include "memory.cpp"//使用时要包含.cpp文件，.h文件分离出来是为了后序生成库和使用做准备而已

using namespace std;

int main(){

    //方式一：
    MemHandler<int> mm(3,10,20,30);//生成一个三维矩阵存储空间，<10,20,30>,其中对照<x,y,z>x变化最快
    mm.SetIndexData(77,5,6,7);//在索引<5,6,7>出设置值为77
    mm.GetIndexData(5,6,7);//去除索引<5,6,7>处的值
    mm.GetIndexPtr(5,6,7);//去除索引<5,6,7>处对应的指针


    //方式二：
    int* data = (int*)malloc(10*20*sizeof(int));
    MemHandler<int> mm1(data,2,10,20);


    mm.FreeMem();//主动释放类中定义的内存
    mm1.FreeMem();//主动释放类中定义的内存
    return 0;

}
