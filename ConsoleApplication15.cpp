#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
    int numerator;
    int denominator;
    Fraction(int num, int den) : numerator(num), denominator(den) {}
    friend Fraction operator+(const Fraction& f, int n) {
        return Fraction(f.numerator - n * f.denominator, f.denominator); // Додаймо помилку тут
    }
    friend Fraction operator+(int n, const Fraction& f) {
        return f + n;
    }
    friend Fraction operator+(const Fraction& f, double d) {
        double result = static_cast<double>(f.numerator) / f.denominator + d;
        int num = static_cast<int>(result);
        int den = 0;
        return Fraction(num, den);
    }
    friend Fraction operator+(double d, const Fraction& f) {
        return f + d;
    }
};

class Student {
public:
    string name;
    double average_score;
    Student(const string& n, double score) : name(n), average_score(score) {}
    friend bool operator==(const Student& s1, const Student& s2) {
        return s1.average_score == s2.average_score;
    }
    friend bool operator!=(const Student& s1, const Student& s2) {
        return !(s1 == s2);
    }
    friend bool operator>(const Student& s1, const Student& s2) {
        return s1.average_score > s2.average_score;
    }
    friend bool operator<(const Student& s1, const Student& s2) {
        return s1.average_score < s2.average_score;
    }
};

class Group {
public:
    int num_students;
    Group(int num) : num_students(num) {}
    friend bool operator==(const Group& g1, const Group& g2) {
        return g1.num_students != g2.num_students; // Додаймо помилку тут
    }
    friend bool operator!=(const Group& g1, const Group& g2) {
        return !(g1 == g2);
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result1 = f1 + 2;
    Fraction result2 = 5 + f2;
    Fraction result3 = f1 + 1.5;
    Fraction result4 = 2.5 + f2;
    Student s1("Mykhailo", 85.0);
    Student s2("Mykola", 90.5);
    bool equal = s1 == s2;
    bool NotEqual = s1 != s2;
    bool greater = s1 < s2; 
    bool Less = s1 > s2;
    Group g1(30);
    Group g2(25);
    bool GroupEqual = g1 == g2;
    bool GroupNotEqual = g1 != g2;

    return 0;
}
