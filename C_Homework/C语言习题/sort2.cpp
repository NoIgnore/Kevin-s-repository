/*#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Person{
    int no;
    int age;
    int height;
};
bool cmp(Person a,Person b){
    if(a.no!=b.no){
        return a.no<b.no;
    }
    if(a.no==b.no && a.age!=b.age){
        return a.age<b.age;
    }
    if(a.no==b.no && a.age==b.age){
        return a.height<b.height;
    }
}
int main(){
    int n;
    cin>>n;
    Person p[n];
    int i,j;
    for(i=0;i<n;i++){
        cin>>p[i].no>>p[i].age>>p[i].height;
    }
    //≈≈–Ú
    sort(p,p+n,cmp);
    //“¿¥Œ ‰≥ˆ
    for(i=0;i<n;i++){
        cout<<p[i].name<<' '<<p[i].age<<' '<<p[i].height<<endl;
    }
}*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Person{
    string name;
    int age;
    int height;
};
bool cmp(Person a,Person b){
    if(a.name!=b.name){
        return a.name<b.name;
    }
    if(a.name==b.name && a.age!=b.age){
        return a.age<b.age;
    }
    if(a.name==b.name && a.age==b.age){
        return a.height<b.height;
    }
}
int main(){
    int n;
    cin>>n;
    Person p[n];
    int i,j;
    for(i=0;i<n;i++){
        cin>>p[i].name>>p[i].age>>p[i].height;
    }
    //≈≈–Ú
    sort(p,p+n,cmp);
    //“¿¥Œ ‰≥ˆ
    for(i=0;i<n;i++){
        cout<<p[i].name<<' '<<p[i].age<<' '<<p[i].height<<endl;
    }
}
