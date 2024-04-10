#include<iostream>
using namespace std;
int c[20],key[20];
   int n,i;
class student{
public:
int prn;
string name;
void htable();
void declare();
void accept();
}h[20];
void student::accept(){
    int no,pos;
    for(i = 0; i < n; i++) {
    no=key[i] % 10;
    pos=no;
    do{
        if(h[no].prn==-1){
            h[no].prn=key[pos];
            cout<<"enter student name : "<<endl;
            cin>>h[no].name;
            break;
        }
        else{
            no++;
            c[pos]=no;
            if(no>10){
                no=0;
            }
        }
    }while(no<10);
}
}
void student::declare(){
    cout<<"enter how many key u want to insert : ";
    cin>>n;
    cout<<"enter the keys : ";
    for( i=0;i<n;i++){
        cin>>key[i];
    }
    for( i=0;i<n;i++){
        h[i].prn=-1;
        c[i]=0;
    }
}
void student::htable(){
    cout<<"\n PRN \tname \tchain"<<endl;
    for( i=0;i<n;i++){
        cout<<"\n"<<h[i].prn<< "\t"<<h[i].name<<"\t"<<c[i]<<endl;
    }
}
int main()
{
    student s;
    s.declare();
    s.htable();
    s.accept();
    s.htable();
return 0;
}