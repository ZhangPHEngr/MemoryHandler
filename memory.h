// #ifndef MEMORY_H
// #define MEMORY_H
#pragma once

#include <iostream>
#include <stdarg.h>//用于支持动态参数个数
#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//void LOG(string type, string msg, string func, int line);



template <class T>
class MemHandler
{
private:
    vector<int> arr_dim;
    int len = 1;
    T* data;
public:
    int dim = 0;
public:
    MemHandler(int dim,...);//构造就初始化申请空间，输入dim x y z ...生成一个动态维度的存储矩阵<x,y,z,...>
    MemHandler(T* data, int dim, ...);//通过传入一个数据指针构造
    ~MemHandler();//释放存储空间
    void SetIndexData(T num, int a,...);//设置某个索引对应的值
    T GetIndexData(int a,...);//获取某个索引对应的值
    T* GetIndexPtr(int a,...);//获取某个索引对应的指针
    T* GetPtr();//获取整个内存块的头地址
    void FreeMem();//内存释放功能
private:
    int GetIdx(int arr_index[]);
    void GetIndexArray(int arr[], va_list arg_list);
};


// #endif

