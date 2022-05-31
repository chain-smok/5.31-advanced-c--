//公有繼承（public）：當一個類派生自公有基類時，基類的公有成員也是派生類的公有成員，
//基類的保護成員也是派生類的保護成員，基類的私有成員不能直接被派生類訪問，但是可以通
//過呼叫基類的公有和保護成員來訪問。
//保護繼承（protected）： 當一個類派生自保護基類時，基類的公有和保護成員將成為派生類的保護成員。
//私有繼承（private）：當一個類派生自私有基類時，基類的公有和保護成員將成為派生類的私有成員。


#include <iostream>
using namespace std;
class Person {
   protected:
     int id;
     string name;
   public:
      Person():id(0),name(""){};  ///Person p1;
      Person(int tid,string tname):id(tid),name(tname){};//Person p1(1,"john");
      Person(Person &p){
          id=p.id;
          name=p.name;
      }
      int getid(){return id;}
      string getName(){return name;}
      void setId(int tid){
            id=tid;
      }
      void setName(string tname){
          name=tname;
      }
      void print(){
          cout<<"ID="<<id<<" and name= "<<name<<endl;
      }
};
class Student: protected Person{
   private:
      double gpa;
   public:
      Student():Person(),gpa(0.0){};//Student s1;
      Student(int tid,string tname,double tgpa):Person(tid,tname),gpa(tgpa){}
      Student(Student &s):Person(s.id,s.name),gpa(s.gpa){}
      void setGpa(double tgpa){
          gpa=tgpa;
      }
      double getGpa(){return gpa;}
      void print(){//overwrite parent
          cout<<"ID="<<id<<" ,name="<<name<<" ,GPA="<<gpa<<endl;
      }

};
int main(){
    Student s1,s2(1,"mary",3.5),s3(2,"john",4.0),s4(s2);
    s1.print();
    s2.print();
    s3.print();
    s4.print();
}