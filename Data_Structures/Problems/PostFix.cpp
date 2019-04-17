#include "Structs/Stack.cpp"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

enum precedence{lparen,rparen,pls,mins,times,divide,mod,eos,operand};
//lparen enters stack irrespective of top element
//rparen pops lparen, so rparen<lparen
//operand has no precedence
//eos always 0
//rest (plus=minus)<(times=mod=divide)
//Keep corresponding values equal in both arrays!!

int icp[]={10,9 ,7 ,7 ,8 ,8 ,8 ,0};
int isp[]={0 ,9 ,7 ,7 ,8 ,8 ,8, 0};

precedence get_token(char c){
  switch (c) {
    case '(':return lparen;break;
    case ')':return rparen;break;
    case '+':return pls;break;
    case '-':return mins;break;
    case '*':return times;break;
    case '/':return divide;break;
    case '%':return mod;break;
    default: return operand;
  }
}
// (a+b)/(c+d) ---> ab+cd+/
void InToPost(char str[]){
  precedence tmp;
  Stack stk(100);
  int i=0;
  while(str[i]!='\0'){
    tmp=get_token(str[i]);
    if(tmp==operand)cout<<str[i];
    else if(tmp==rparen){
      while( get_token(((char)stk.peek()))!=lparen)cout<<(char)stk.pop();
      stk.pop();
    }
    else{
      if(stk.isEmpty())stk.push((int)str[i]);
      else{
        while( icp[tmp]<=isp[get_token(((char)stk.peek()))])cout<<(char)stk.pop();
        stk.push((int)str[i]);
      }
    }
    i++;
  }
  while(!stk.isEmpty())cout<<(char)stk.pop();
}
void EvalPF(char str[]){
  Stack stk(100);int i=0;
  while(str[i]!='\0'){
    precedence tmp;
    tmp=get_token(str[i]);
    if(tmp==operand){
      int n;
      cout<<"Enter value of "<<str[i]<<": ";
      cin>>n;
      stk.push(n);
    }
    else{
      int op1=stk.pop();
      int op2=stk.pop();
      switch(str[i]){
        case '+':stk.push(op1+op2);break;
        case '-':stk.push(op1-op2);break;
        case '*':stk.push(op1*op2);break;
        case '/':stk.push(op1/op2);break;
        case '%':stk.push(op1%op2);break;
      }
    }
    i++;
  }
  stk.display();
}
void InToPre(char str[],char str2[]){
  int icp[]={9,10,7,7,8,8,8,0};
  int isp[]={9,0,7,7,8,8,8,0};
  precedence tmp;
  Stack stk(100);
  int i=strlen(str)-1,j=0;
  while(i>=0){
    tmp=get_token(str[i]);
    if(tmp==operand)str2[j++]=str[i];
    else if(tmp==lparen){
      while( get_token(((char)stk.peek()))!=rparen)str2[j++]=(char)stk.pop();
      stk.pop();
    }
    else{
      if(stk.isEmpty())stk.push((int)str[i]);
      else{
        while( icp[tmp]<=isp[get_token(((char)stk.peek()))])str2[j++]=(char)stk.pop();
        stk.push((int)str[i]);
      }
    }
    i--;
  }
  while(!stk.isEmpty())str2[j++]=(char)stk.pop();
  str2[j]='\0';
  j--;
  while(j>=0){
    cout<<str2[j--];
  }
}

int main(){
  //InToPost("a+b*c-d/e*f");
  //EvalPF("ab+c*");
  char ans[100];
  InToPre("(a+b)*c",ans);
  getchar();
}
