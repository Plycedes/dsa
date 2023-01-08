#include <iostream>

using namespace std;

int arr[20];
int top1 = 0, top2 = 10, max1 = 9, max2 = 19;

void push1(int x){
    if(top1 > max1){
        cout<<"Stack1 overflow"<<endl;
    }else{
        arr[top1] = x;
        top1++;
        cout<<"Pushed into Stack1: "<<x<<endl;
    }
}

void push2(int x){
    if(top2 > max2){
        cout<<"Stack2 overflow"<<endl;
    }else{
        arr[top2] = x;
        top2++;
        cout<<"Pushed into Stack2: "<<x<<endl;
    }
}

void pop1(){
    if(top1 < 0){
        cout<<"Stack1 underflow"<<endl;
    }else{        
        cout<<"Popped from Stack1: "<<arr[--top1]<<endl;
        top1--;        
    }
}

void pop2(){
    if(top2 < 10){
        cout<<"Stack2 underflow"<<endl;
    }else{
        cout<<"Popped from Stack2: "<<arr[--top2]<<endl;
        top2--;
    }
}

void print1(){
    cout<<"Stack1: ";
    for(int i = 0; i <= top1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void print2(){
    cout<<"Stack2: ";
    for(int i = 10; i <= top2; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<endl;
    push1(10);
    push1(20);
    push1(30);
    push1(40);
    push1(50);
    pop1();
    print1();
    cout<<endl;
    push2(60);
    push2(70);
    push2(80);
    push2(90);
    push2(100);
    pop2();
    print2();
    cout<<endl;
    return 0;
}