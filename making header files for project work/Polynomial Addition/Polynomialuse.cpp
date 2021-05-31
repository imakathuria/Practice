#include<iostream>
using namespace std;
#include "Polynomial.h"
int main(){
    Polynomial p1;
    p1.setCoefficient(2,-2);
    p1.setCoefficient(1,1);
    p1.setCoefficient(0,-1);
    p1.print();
    Polynomial p2(p1);
    p2.print();
    Polynomial p3;
    p3=p2+p1;
    p3.print();
    Polynomial p4;
    p4.setCoefficient(9,-9);
    p4.print();
    Polynomial p5;
    p5=p3+p4;
    p5.print();
    return 0;
}