#include <iostream>
int NOD(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}
class Rational
    {
    public:
        Rational(int ,int);//конструктор с параметрами
        Rational(const Rational& r);//конструктор копий

    int denominator;
    int numerator;
    const Rational operator+(const Rational &r) const;
    const Rational operator*(const Rational &r) const;
    const Rational operator/(const Rational &r) const;
    bool  operator==(const Rational& r) const;
    bool  operator<(const Rational& r) const;
    bool  operator>(const Rational& r) const;
private:
    void reduce();
};
Rational::Rational(const Rational& r){
    numerator=r.numerator;
    denominator=r.denominator;
}

void Rational::reduce() {
    if(NOD(numerator, denominator)==0)
        return;
    {
            numerator /= NOD(numerator, denominator);
            denominator/=NOD(numerator, denominator);
    }
}
Rational::Rational(int r_numerator, int r_denominator){
    numerator=r_numerator;
    denominator=r_denominator;
}
const Rational Rational::operator+(const Rational& r) const {
    Rational sum{numerator*r.denominator+r.numerator+denominator,denominator*r.denominator};
    sum.reduce();
    return sum;
}
const Rational Rational::operator*(const Rational& r) const {
    Rational multi{numerator*r.numerator, denominator*r.denominator};
    multi.reduce();
    return multi;
}
const Rational Rational::operator/(const Rational& r) const {
    Rational div{numerator * r.denominator, denominator*r.numerator};
    div.reduce();
    return div;
}

bool  Rational::operator==(const Rational& r) const {
    Rational r1{numerator, denominator};
    Rational r2{r.numerator, r.denominator};
    r1.reduce();
    r2.reduce();
    return numerator==r.numerator&&denominator==r.denominator;
}
bool  Rational::operator<(const Rational& r) const {
    Rational r1{r.numerator, r.denominator};
    Rational r2{r.numerator, r.denominator};
    r1.reduce();
    r2.reduce();
    Rational chr1{r1.numerator*r2.denominator, r1.denominator*r2.denominator};
    Rational chr2{r2.numerator*r1.denominator, r2.denominator*r1.denominator};
    return chr1.numerator<chr2.numerator;
}
bool  Rational::operator>(const Rational& r) const {
    Rational r1{numerator, denominator};
    Rational r2{r.numerator, r.denominator};
    r1.reduce();
    r2.reduce();
    Rational chr1{r1.numerator*r2.denominator, r1.denominator*r2.denominator};
    Rational chr2{r2.numerator*r1.denominator, r2.denominator*r1.denominator};
    return chr1.numerator>chr2.numerator;
}

std::ostream& operator<<(std::ostream&out, const Rational&r)
{
    if (r.denominator == 1 or r.numerator == 0) {
        out << r.numerator;
        return out;
    }

    out << r.numerator << "/" << r.denominator;
    return out;
}
int main() {
Rational r1(3,4);
Rational r2(5,7);
Rational r3=r1+r2;
 std::cout << r1<<(r1<r2?"<":">")<<r2;
std::cout << r3;
}
