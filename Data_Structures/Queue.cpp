#include <iostream>
using namespace std;

class Queue{
  int front,rear,msz;
  int Q[100];
 public:
   Queue(int);
   void push(int);
   int pop();
   bool isEmpty();
   bool isFull();
   void display();
};

Queue::Queue(int size){
  front=rear=-1;msz=size;
}
void Queue::push(int n){
  if(rear==msz-1)cout<<"FULL";
  else Q[++rear]=n;
}
int Queue::pop(){
  if(front==rear)cout<<"EMPTY";
  else return Q[++front];
}
bool Queue::isEmpty(){
  if(front==rear)return true;
  else return false;
}
bool Queue::isFull(){
  if(rear==msz-1)return true;
  else return false;
}
void Queue::display(){
  if(front==rear){
    cout<<"EMPTY";
    return;
  }
  for(int i=front+1;i<=rear;i++){
    cout<<Q[i]<<"<<";
  }
}
