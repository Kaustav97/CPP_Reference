#include <iostream>
#include <string.h>
using namespace std;

class StringStack{
  char arr[100][100];
  int top,bottom,msz;
 public:
  StringStack(int);
  void push(char[]);
  char* pop();
  void display();
  bool isEmpty();
};

StringStack::StringStack(int size){
  msz=size;
  top=bottom=-1;
}
void StringStack::push(char str[]){
  if(top==msz-1)cout<<"FULL\n";
  else strcpy(arr[++top],str);
}
char* StringStack::pop(){
  if(top==bottom)cout<<"EMPTY\n";
  else return(arr[top--]);
}
void StringStack::display(){
  if(top==bottom){
    cout<<"EMPTY\n";
    return;
  }
  for(int i=top;i>bottom;i--){
    cout<<arr[i]<<"\n";
  }
}
bool StringStack::isEmpty(){
  if(top==bottom)return true;
  else return false;
}
