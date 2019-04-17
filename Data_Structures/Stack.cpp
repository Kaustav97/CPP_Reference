#include <iostream>
using namespace std;

class Stack{
  int stk[100],top,bottom,sz;
 public:
   Stack(int);
   void push(int);
   void display();
   int pop();
   int isEmpty();
   int peek();
   int isFull();
};
Stack::Stack(int n){
  sz=n;
  top=bottom=-1;
}
void Stack::push(int a){
  if(top==sz-1){
    std::cout << "Stack Full" << '\n';
    return;
  }
  else stk[++top]=a;
}
void Stack::display(){
  if(top==bottom){
    std::cout << "Empty" << '\n';
    return;
  }
  for(int i=top;i>bottom;i--){
    cout<<stk[i]<<" ";
  }
}
int Stack::pop(){
  if(top!=bottom){
    return stk[top--];
  }
  else std::cout << "Empty" << '\n';
}
int Stack::peek(){
  if(top>bottom)return stk[top];
}
int Stack::isEmpty(){
  if(top==bottom)return 1;
  else return 0;
}
int Stack::isFull(){
  if(top==(sz-1))return 1;
  else return 0;
}
