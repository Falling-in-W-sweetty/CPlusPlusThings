//Eg10-9.cpp
//有可能产生两种报告方式
//　　1、抛出bad_alloc异常来报告分配失败；
//    2、返回空指针，而不会抛出异常。
#include<iostream>
using namespace std;
class A{
    int a;
public:
    A(int i=0):a(i){}
    ~A(){cout<<"in A destructor..."<<endl;}
};
class B{
    A obj[3];
    double *pb[10];
    public:
        B(int k){
            cout<<"int B constructor..."<<endl;
            for (int i=0;i<10;i++){
                pb[i]=new double[20000000];//第一种方式抛出异常时，后面的程序不会执行，这段程序只能针对方式2
                if(pb[i]==0)
                    throw i;
                else 
                    cout<<"Allocated 20000000 doubles in pb["<<i<<"]"<<endl;
            }
        }
};
int main(){
    try{
        B b(2);
    }
    catch(int e){
        cout<<"catch an exception when allocated pb["<<e<<"]"<<endl;   
    }
    system("pause");
}
