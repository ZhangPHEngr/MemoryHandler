#include "memory.h"

static void LOG(string type, string msg, string func, int line){
    cout<<func<<": "<<line<<" "
        <<" Type: "<<type
        <<" Msg : "<<msg
        <<endl;
}

template <class T>
MemHandler<T>::MemHandler(int dim,...)
{
    if(dim <= 0){
        LOG("Error", "Class construct failed!", __func__, __LINE__);
        exit(-1);
    } 
    this->dim = dim;
    va_list dim_list;//获取参数列表的头指针
    va_start(dim_list, dim);
    
    for (int i = 1; i < dim+1; i++)
    {
        int v = va_arg(dim_list,int);
        //cout<<v<<endl;
        this->arr_dim.push_back(len);
        len *= v;
    }
    //分配内存
    data = (T*)malloc(len * sizeof(T));
    //cout<<len<<endl;
  
}

template <class T>
MemHandler<T>::MemHandler(T* data, int dim, ...){

    if(dim <= 0 || data == NULL){
        LOG("Error", "Class construct failed!", __func__, __LINE__);
        exit(-1);
    }

    this->data = data;
    this->dim = dim;
    va_list dim_list;//获取参数列表的头指针
    va_start(dim_list, dim);
    
    for (int i = 2; i < dim+2; i++)
    {
        int v = va_arg(dim_list,int);
        cout<<v<<endl;
        this->array.push_back(len);
        this->len *= v;
    }
}

template <class T>
MemHandler<T>::~MemHandler()
{
    if (data != NULL)
        free(data);
}

template <class T>
void MemHandler<T>::SetIndexData(T num, int a,...){
    va_list index_list;//获取参数列表的头指针
    va_start(index_list, a);

    int arr_index[dim] = {0};
    arr_index[0] = a;

    GetIndexArray(arr_index, index_list);
    //cout<<arr_index[0]<<arr_index[1]<<endl;
    int index = GetIdx(arr_index);
    data[index] = num;
}


template <class T>
T MemHandler<T>::GetIndexData(int a,...){
    va_list index_list;//获取参数列表的头指针
    va_start(index_list, a);

    int arr_index[dim] = {0};
    arr_index[0] = a;

    GetIndexArray(arr_index, index_list);
    //cout<<arr_index[0]<<arr_index[1]<<endl;
    int index = GetIdx(arr_index);
    return data[index];
}

template <class T>
T* MemHandler<T>::GetIndexPtr(int a,...){
    va_list index_list;//获取参数列表的头指针
    va_start(index_list, a);

    int arr_index[dim] = {0};
    arr_index[0] = a;

    GetIndexArray(arr_index, index_list);
    //cout<<arr_index[0]<<arr_index[1]<<endl;
    int index = GetIdx(arr_index);
    return &data[index];
}

template <class T>
T* MemHandler<T>::GetPtr(){
    return (T*)data;
}

template <class T>
void MemHandler<T>::FreeMem(){
    free(data);
    LOG("Info", "free memory success!", __func__, __LINE__);
}

template <class T>
int MemHandler<T>::GetIdx(int arr_index[]){
    int res = 0;
    for (int i = 0; i < dim; i++)
    {
        res += arr_index[i]*arr_dim.at(i);
    }
    
    return res;
}

template <class T>
void MemHandler<T>::GetIndexArray(int arr[], va_list arg_list){
    int tmp;
    for (int i = 1; i < dim; i++)
    {  

        if ((tmp = va_arg(arg_list,int))>=0)
        {
            arr[i]  = tmp;
        }else{
            LOG("Error", "Index Illegal!", __func__, __LINE__);
            exit(-1);
        }
        
    }
}

    