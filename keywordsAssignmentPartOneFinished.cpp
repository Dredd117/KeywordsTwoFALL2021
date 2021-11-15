#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// a vector is a dynamic array that can adjust itslef if an element is in or out.
vector<int> positions(string s, char c) {

    vector<int> ret;
    //push_back() moves and element to the back of the vector.
    ret.push_back(-1);
    //returns an iterator to the first element.
    if (s.find(c) != string::npos) {
        //pop_back() removes the element in the back of the vector.
        ret.pop_back();
        int pos = 0;
        //the for loop is constantly checking if the variouble const char and cc : s.
        for (const char& cc : s) {
            if (cc == c) {
                ret.push_back(pos);
            }
            ++pos;
        }
    }
    return ret;
}
// the function printPartial works when vector<> v and string s.
void printPartial(vector<int> v, string s) {
    printf("\n");
    //the loop iterates the vector s.size() when vector "it" finds the beginning and end.
    for (int i = 0; i < s.size(); i++) {

        vector<int>::iterator it = find(v.begin(), v.end(), i);
        if (it != v.end()) {
            printf("%c", s[i]);
        }
        else {
            printf("*");
        }
    }
}
int main()
{
    string test = "meow meow meow meow meow";

    printPartial(positions(test, 'm'), test);
    return 0;
}