/* what are structs? how do we use them?
1. structs are user defined data types. they are like classes, but exhibiting some significant differences.
        -> the main difference is the access modification. i.e structs are by default public datatypes while
        private in the case of classes.
    USES: 1. data grouping
           2.  Member functions; functions can also be considered as first order citizens
           3. Access modifiers -> pud public by default  */

//how to use structs
#include<iostream>
#include<cmath>
using namespace std;
//step1: define struct
struct point{
    float x;
    float y;
    //we want to represent R^2 space
};
struct dstns{
    float xTot;
    float yTot;
    float Tot;

};


int main(){
    point p1;//instantiation, using points to access the contents.
    p1.x = 2.1;
    p1.y = 4.6;

    point p2 = {5.9, 7.6};// instantiation using initiallizer list


    //taken instantiation and initialization, how do we access the contents in instantiated variables?
    dstns p1p2;
    p1p2.xTot = p1.x + p2.x;
    p1p2.yTot = p1.y + p2.y;
    p1p2.Tot = sqrt(pow(p1p2.xTot, 2) + pow(p1p2.yTot, 2));
    cout<<p1p2.Tot;
}

/*what the above code does
1. takes 2 points by initalization, the points are struces(user defined data types
2. takes components specificly and adds them together
3. compute the modulus||distance based on pythagorean theorem )*/