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
void search();
void update();
void Delete();
}h[20];

void student::Delete(){
        int no,pr,pos,f=0;
    cout<<"enter u want to deleted"<<endl;
    cin>>pr;
    for(int i=0;i<n;i++){
        no=pr%10;
        pos=no;
        do{
            if(h[no].prn==pr){
                f=1;
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
if(f==1){
    cout<<"record deleted successfully";
    h[no].prn=-1;
    h[no].name=" ";
    
}
else{
    cout<<"record is not found";
}
}

void student::update(){
    int no,pr,pos,f=0;
    cout<<"enter u want to update"<<endl;
    cin>>pr;
    for(int i=0;i<n;i++){
        no=pr%10;
        pos=no;
        do{
            if(h[no].prn==pr){
                f=1;
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
if(f==1){
    cout<<"enter info "<<endl;
     cout<<"\n PRN \tname \tchain"<<endl;
     cin>>h[no].name ;
}
else{
    cout<<"record is not found";
}
}
void student::search(){
    int no,pr,pos,f=0;
    cout<<"enter u want to search "<<endl;
    cin>>pr;
    for(int i=0;i<n;i++){
        no=pr%10;
        pos=no;
        do{
            if(h[no].prn==pr){
                f=1;
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
if(f==1){
     cout<<"\n PRN \tname \tchain"<<endl;
       cout<<"\n"<<h[no].prn<< "\t"<<h[no].name<<"\t"<<c[i]<<endl;
}
else{
    cout<<"record is not found";
}
}
void student::accept(){
    int no,pos;
    for(i = 0; i < n; i++) {
    no=key[i] % 10;
    pos=no;
    do{
        if(h[no].prn==-1){
            h[no].prn=key[i];
            cout<<"enter student name : "<<endl;
            cin>>h[no].name;
            break;
        }
        else{
            no++;
            c[pos]=no;
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
    for( i=0;i<20;i++){
        h[i].prn=-1;
        c[i]=0;
    }
}
void student::htable(){
    cout<<"\n PRN \tname \tchain"<<endl;
    for( i=0;i<20;i++){
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
    s.search();
    // s.update();
    s.Delete();
    s.htable();
return 0;
}