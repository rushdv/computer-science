#include<iostream>
using namespace std;
class student
{
protected:
    int roll;
public:
    void get_roll(int a)
    {
        roll=a;
    }
    void show_roll()
    {
        cout<<"Roll : "<< roll<<endl;
    }
};
class test : public student
{
protected:
    float subMark[5];// 5 sub -> array
public:
    void get_mark(float x, float y,float z,float a,float b)
    {
        subMark[0]=x;
        subMark[1]=y;
        subMark[2]=z;
        subMark[3]=a;
        subMark[4]=b;
    }
    void show_mark()
    {
        for(int i=0;i<5;i++)
        {
            cout<<"Subject"<<i+1<<" Mark is :"<<subMark[i]<<endl;
        }
    }
};
class result :public test
{
    float total=0,average;
public:
    //average
    void average_mark()
    {
        for(int i=0;i<5;i++)
        {
            total=total+subMark[i];
        }
        average=total/5;
    }
    void display()
    {
        show_roll();
        show_mark();
        average_mark();
        cout<<"Total Average="<<average<<endl;
    }
};
int main()
{
    result st1;
    st1.get_roll(67);
    st1.get_mark(7,5,6,7,8);
    st1.display();
}
