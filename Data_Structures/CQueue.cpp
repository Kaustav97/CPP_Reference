#include <iostream>
using namespace std;

class CQueue{
  int front,rear,count,msize;
  int cq[100];
 public:
   CQueue(){
     front=rear=-1;count=0;msize=0;
   }
   CQueue(int m){
     front=rear=-1;count=0;msize=m;
   }
   void push(int);
   int pop();
   void display();
};
void CQueue::push(int num){
  if(count==msize){
    cout<<"Full";
    return;
  }
  rear=(rear+1)%msize;
  cq[rear]=num;
  count++;
}
int CQueue::pop(){
  if(front==rear){
    cout<<"Empty";
  }
  front=(front+1)%msize;
  return cq[front];
  count--;
}
void CQueue::display(){
  if(count==0)cout<<"EMPTY";
  else
  for(int i=(front+1)%msize;i!=rear;i=(i+1)%msize) cout<<cq[i]<<">>";
  cout<<cq[rear];
}

int main(){
  CQueue c1(5);
  c1.push(7);c1.push(5);c1.push(18);c1.push(10);c1.push(15);
  c1.pop();c1.pop();
  c1.display();
}
