#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // erase
    // find
    // insert
    // replace
    // append
    // string str = "hello";
    // str.append(" world");                        // hello world;
    // cout << str.find("world");                   // at index 6;
    // str.insert(str.find("world"), "beautiful "); // hello beautiful world
    // str.replace(str.find("world"), 5, "human");  // hello beautiful human
    // cout << str;
    // cout << endl;
    // str.erase(2);
    // cout << str << endl;
    // cout << str.length() << endl;
    std::string s = "hello world";
    size_t pos = s.find("goodbye");

    if (pos == -2)
    {
        std::cout << "The string \"goodbye\" was not found in \"" << s << "\"." << std::endl;
    }
    return 0;
}
