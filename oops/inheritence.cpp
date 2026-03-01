//demonstrating public private and protected inheritence
//
// #include <iostream>
//
// // demonstrating the value of private public and protected variables
//
// // class Base{
// //     public:
// //         int a{0};
// //         void display(){std::cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<std::endl;}
// //     protected:
// //         int b{0};
// //     private:
// //         int c{0};
// // };
// // class Derived:public Base{
// //     public:
// //         void access_base_members(){
// //             a=100;
// //             b=200;
// //             // c=300; not acceble
// //         }
// // };
// //
//
// // using Base::Base syntax
// class Base {
// private:
//   int temp;
//
// public:
//   Base() : temp{0} { std::cout << "base class no -args" << std::endl; }
//   Base(int x) : temp{x} {
//     std::cout << "base one arg constructor with value " << temp << std::endl;
//   }
//   Base &operator=(const Base &rhs) {
//     std::cout << "Base operator=" << std::endl;
//     if (this == &rhs) {
//       return *this;
//     }
//     temp = rhs.temp;
//     return *this;
//   }
//   void display() { std::cout << "the value is " << temp << std::endl; }
//   ~Base() { std::cout << "Base destructor" << std::endl; }
// };
// class Derived : public Base {
//   using Base::Base; // using this syntax symplifies
// private:
//   int doubled_value;
//
// public:
//   Derived() : doubled_value{0} {
//     std::cout << "derived function no-args constructor" << std::endl;
//   }
//   Derived(int x) : doubled_value{x} {
//     std::cout << "derived one -arg constructor" << std::endl;
//   }
//   void deriviedFunction() { std::cout << "Derivied function" << std::endl; }
// };
//
// int main() {
//
//   // Derived d;
//   // d.a=100;
//   // // d.b=200; // the protected member is accecceble only inside the dervied
//   // class and base class d.display();
//
//   Derived d;
//
//   Base b1(10);
//   Base b2 = b1;
//   b2.display();
//
//   return 0;
// }
//

// public inheritence  vehicle<-car //here public members of the base class becomes public members of derived class
// #include <iostream>
// class Vehicle{
//     public:
//         void start(){
//             std::cout<<"vechicle started"<<std::endl;
//         }
//         void stop(){
//             std::cout<<"vehicle stoped"<<std::endl;
//         }
// };
//
// class Car: public Vehicle{
//     public:
//         void drive(){
//             std::cout<<"car is driving"<<std::endl;
//         }
// };
//
// int main(){
//     Car c;
//     c.start();
//     c.drive();
//     c.stop();
// }
//


// private inheritence person<-student //here public members of base class becomes private members of derived class
//that means the inherited methods are accessible only within the inherited class
// #include <iostream>
// class Person{
//     public:
//         void introduce(){
//             std::cout<<"i am a person"<<std::endl;
//         }
// };
// class Student:private Person{
//     public:
//         void study(){
//             std::cout<<"studenet is studying"<<std::endl;
//         }
//         using Person::introduce;
// };
// class SomeOther:public Student{
//     public:
//         void someting(){
//             std::cout<<"this is doing something"<<std::endl;
//         }
// };
// int main(){
//     Student student;
//     student.study();
//     student.introduce();
//     SomeOther str;
//     str.study();
//
//     return 0; 
// }

// in protected both public and protected members of base class becomes protected members of derived class
