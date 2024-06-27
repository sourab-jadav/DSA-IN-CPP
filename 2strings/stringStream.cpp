#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main() {

    // stringstream class useful things
    stringstream ss;
//    std::cout<<"wrirint to string stream"<<std::endl;
    // writing data to stringstream
    ss<<"hello string stream";
    // reading data from the string stream // default delimeter is " "
    // string temp;
    // while (ss>>temp) {
    //    std::cout<<temp<<std::endl;
    // }





    // type conversion from ss object to anyother data type

    string str=ss.str();
//    std::cout<<str<<std::endl;

    string d_value="12.45";                     //extracting double value from a string
    stringstream ss2(d_value);
    double d;
    ss2>>d;
    // 
    //
    //
    // for reading words ss object is enough 
    // for reading lines you can use getline() method to read one line at a time

    string fn[]{"sourab","ravi","aarti","raj","shiv","shoeb"};
    string last[]{"jadav","vanam","botnanager","kumar","saini","aktar"};
    // the point is we have to create a bunch of strings from this fn and ln 
    stringstream ss3;
    for(int i=0;i<6;i++){
        ss3<<"FirstName: "<<fn[i]<<" LastName: "<<last[i]<<std::endl;
    }
    // now you have the strings just print them out line by line
    string line="dasdfsdfsd";
    int count =1;
    while (getline(ss3,line)) { // getline overwrite the contents of the variable line which is of string type
//        std::cout<<"Line "<<count<<std::endl;
//        std::cout<<line<<std::endl;
//        std::cout<<std::endl;
        count++;
    }
    // formatting
    // error handling
    // changint the delimeter

    int hours=5;
    int minutes=67;
    int seconds=5;
    // use stringstream and format these hours minutes and seconds
//    std::cout<<"enter number of hours"<<std::endl;
    // cin>>hours;
//    std::cout<<"enter number of minutes"<<std::endl;
    // cin>>minutes;
//    std::cout<<"enter number of seconds"<<std::endl;
    // cin>>seconds;
    stringstream ss4;
    ss4<<(hours<10?"0":"")<<hours<<" : "<<(minutes<10?"0":"")<<minutes<<" : "<<(seconds<10?"0":"")<<seconds;

    string line2;
    getline(ss4,line2);
//    std::cout<<line2<<std::endl;
    return 0;
}

// reusing the string stream by seeking the position to the beginning
    // string input ="25525511135";
    // int n=input.length();
    // stringstream ss;
    // for(int i=0;i<n-1;){
    //     string part=input.substr(i,3);
    //     ss<<part<<" "; // here if you do not include spaces then the behaviour will not be as expected
    //     // ss<<part;
    //     i+=3;
    // }
    //
    // int x;
    // while (ss>>x) {
    //     std::cout<<x<<" ";
    // }
    // string te;
    // while (ss>>te) {
    //     std::cout<<te<<std::endl;
    // }
    // // The reason the te value is not being printed is that after the first loop where you extract integers (ss >> x),
    // // the stringstream's read position reaches the end of the stream. Once the end of the stream is reached,
    // // the state of the stream is set to fail, and further extraction operations will not work unless the stream state is reset.
    // if (ss.fail()) {   // this condition will be true here
    //     std::cout<<"ss is failed"<<std::endl;
    // }
    //
    // // to solve this we have to clear the stream state and reset the position of the stream 
    // // ss.clear();
    // // ss.seekg(0,ios::beg);
    // // while (ss>>te) { // now this is get executed
    // //     std::cout<<te<<std::endl;
    // // }
