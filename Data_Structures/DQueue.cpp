#include <iostream>
using namespace std;

class DQueue{
  int front,rear,msz;
  int beg,end,cap;
  int dq[100];
 public:
   DQueue(int size){
     front=-1;rear=msz=size;
     beg=-1,end=msz;
     cap=100;
   }
   void insFront(int m){
     if(isFull()){
       cout<<"FULL";
       return;
     }
     dq[++front]=m;
   }
   void insRear(int m){
     if(isFull()){
       cout<<"FULL";
       return;
     }
     dq[--rear]=m;
   }
   int popFront(){
     if((rear-front)==msz+1)cout<<"EMPTY";
     else if(beg==front)cout<<"EMPTY";
     else return dq[beg++];
   }
   int popRear(){
     if((rear-front)==msz+1)cout<<" EMPTY ";
     else if(end==rear)cout<<" EMPTY ";
     else return dq[end--];
   }
   bool isFull(){
     if((front-beg+(end-rear))==msz)return true;
     else return false;
   }
   void display(){
     if((rear-front)==msz+1){
       cout<<"EMPTY";
       return;
     }
     for(int i=beg+1;i<=front;i++)cout<<dq[i]<<" ";
     cout<<"\t";
     for(int i=rear;i<end;i++)cout<<dq[i]<<" ";
   }
};
