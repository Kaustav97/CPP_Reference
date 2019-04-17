#include <iostream>
#include "Structs/StringStack.cpp"
using namespace std;

void PostToIn(char str[]){
  StringStack stk(20);
  int i=0;
  while(str[i]!='\0'){
    char tmp[10];
    tmp[0]=str[i];tmp[1]='\0';
    char op1[30],op2[30],tmp2[30]="";
    if(tmp[0]<65||tmp[0]>122){
      strcpy(op2,stk.pop());
      strcpy(op1,stk.pop());
      strcat(tmp2,"(");
      strcat(tmp2,op1);strcat(tmp2,tmp);
      strcat(tmp2,op2);strcat(tmp2,")");
      stk.push(tmp2);
    }
    else{
      stk.push(tmp);
    }
    i++;
  }
  cout<<stk.pop();
}

int main(){
  PostToIn("ab+cd*/e-");
}
