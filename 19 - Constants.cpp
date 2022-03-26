Constant
- read only entity
- Read allowed
- Write not allowed

1- constant variables(identifiers)
2- Constant Pointers
3- Constant data member
4- constant methods
5- constant object

1- Constant Variables
   - read only 
 const  int a=5;
  x=a; //ok
  a=a+1; //error

2- Constant Pointers
   -read only address location
  1) pointer pointed to constant
      const int *p;
  2) pointer itself constant
       int  *const p;

  
1) pointer pointed to constant
     int a=5;  
    const int *p=&a; //aliasing 
       *p=*p+10;//error
....................................................
Example: Usage of Pointer pointed to constant
   It will create  side effects
What is Side Effect?
- one variable has different values in same expression   
- Poor  programming Practices
- Banned in Industry
- A program with Side Effects will create readability problem for maintenance      programmers


void main () {
int a=5;
int x=10;
int b= x+a*f(&a);//poor readability
cout<<b<<endl;

}
int f(int *p){
cout<<*p<<endl;// read allowed
*p=*p+10;//write allowed
return 2;
}

output1 without side effects
             20

output2 with side effects
           40
................................................................
Remedy : use Pointer pointed to constant
 
void main () {
int a=5;
int x=10;
int b= x+a*f(&a);
cout<<b<<endl;

}
int f(const int *p){ //read only function
cout<<*p<<endl;// read allowed
//*p=*p+10;//write not allowed error
return 2;
}
............................................................
Common Industy Practice
- function Signature are predecided before coding
e.g.
Implement two funtions with signatures

int f (const int *p)
char grade(const student *p)  

.............................................................
2- Pointer itself Constant

  int  *const p;

void main () {
int a=5;
int  *const p=&a;
int b=10;
p=&b;
}
....................................................
major usage
1- Array name

e.g
void main () {
int a[5]={1,2,3,4,5}; // here a is pointer itself conatant
int  *p;
p=a; //aliasing
cout<<a[1]<<p[1]<<endl; //output is same  2 2
p++;
cout<<a[1]<<p[1]<<endl; //output is  not same  2  3
//a++; //not allowed reason a is constant pointer  error
}

2- Avoid Garbage Problem (memory leakage)

what is Garbage?
-unreferenced memory location are called garbage

e.g
void main() {
int *p;
p= new int;

p=new int; // it will create garbage in memory
delete p;
for (;;) // this for creats too much garbage
  p= new int;
}
.......................................................
Remedy
1- Every new keyword should have matching delete keyword
2- Go for pointer itself constant
...............................................
Constant data member
- read only data member
- there is no setter methods for constants

class Math {
private:
 const double pi;
public:
Math ( ):pi(3.14) { }
double getPI() { return pi;}
};
void main() {
Math ob;
cout<<ob.getPI()<<endl;
}
..............................................................
4- constant methods
 - read only methods 
 - can't change instance level data members
 - most common practice in industry reason(readability)
 - Static methods should not be constant

class Student {
private :
  int marks;
public : 
    Student ( ){}
    Student (int m ) { marks=m;}
    char grade() const{
          cout<<marks;// read allowed
          marks++;//write not allowed error
          return 'A';          

   }
   void printMarks()const {
    cout<<marks;//allowed
    int i=10;//allowed
    cout<<i; //allowed
    i++; //allowed
   }
};
void main() {
Student ob;
cout<<ob.grade();

}
.............................................................

5- constant object

 -   read only Objects
 -    can access only constant methods
 

class A {
public :
  void m() { }
  void m2()const{}
};

void main(){
const A ob;
ob.m(); // not allowed
ob.m2(); //allowed
}
..............................................................



