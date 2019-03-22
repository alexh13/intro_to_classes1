/*
 Alex Hughes
 CS 110B
 3/18/19
 Professor Dave
 Assignment 8.1


 */

#include <iostream>
using namespace std;






class Fraction
{
private:
    // int's declared add to rest of program
    int numerator;
    int denominator;
public:
    Fraction();
    Fraction(int a,int b);
    Fraction addedTo(Fraction f2);
    Fraction subtract(Fraction f2);
    Fraction multipliedBy(Fraction f2);
    Fraction dividedBy(const Fraction& f2) const;
    int get_num() const;
    int get_den() const;
    bool isEqualTo(Fraction f2);
    void print() const;
    void set(int a, int b);
};






Fraction::Fraction()
{
    num = 0;
    den = 1;
}







Fraction::Fraction(int a, int b)
{
    int large = a>b?a:b;
    num = a;
    den = b;
    int gcd= 1;
    for(int i=large; i>=2; i--)
    {
        if(num%i==0 && den%i==0) {
            gcd = i; break; }
    }
    num = num/gcd;
    den = den/gcd;
}






Fraction Fraction::addedTo(Fraction f2)
{
    int new_num = num*f2.get_den() + den*f2.get_num();
    int new_den = den*f2.get_den();
    return Fraction(new_num,new_den);
}






Fraction Fraction::subtract(Fraction f2)
{
    int new_num = num*f2.get_den() - den*f2.get_num();
    int new_den = den*f2.get_den();
    return Fraction(new_num,new_den);
}






Fraction Fraction::multipliedBy(Fraction f2)
{
    int new_num = num*f2.get_num();
    int new_den = den*f2.get_den();
    return Fraction(new_num,new_den);
}






Fraction Fraction::dividedBy(const Fraction& f2) const
{
    int new_num = (this->get_num())*f2.get_den();
    int new_den = (this->get_den())*f2.get_num();
    Fraction temp(new_num,new_den);
    return temp;
}






bool Fraction::isEqualTo(Fraction f2)
{
    return (num==f2.get_num() && den == f2.get_den());
}





void set(int a, int b);
{

}






void Fraction::print() const
{
    cout << num << "/" << den;
}






int Fraction::get_num() const
{
    return num;
}






int Fraction::get_den() const
{
    return den;
}






int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}






