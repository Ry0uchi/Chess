#pragma once

#include <iostream>

template <typename Type>
struct Vect2D {

    Type X, Y;
    Vect2D(Type x = 0, Type y = 0): X(x), Y(y){}

    // v1 == v2
    inline bool operator==(const Vect2D<Type>& v2) const {
        return (X == v2.X && Y == v2.Y);
    }

    // v1 + v2
    inline Vect2D<Type> operator+(const Vect2D<Type>& v2) const {
        return Vect2D<Type>(X + v2.X, Y + v2.Y);
    }

    // v1 += v2
    inline friend Vect2D<Type> operator+=(Vect2D<Type>& v1, const Vect2D<Type>& v2){
        v1.X += v2.X;
        v1.Y += v2.Y;
        return v1;
    }

    // v1 - v2
    inline Vect2D<Type> operator-(const Vect2D<Type>& v2) const {
        return Vect2D<Type>(X - v2.X, Y - v2.Y);
    }

   // v1 -= v2
    inline friend Vect2D<Type> operator-=(Vect2D<Type>& v1, const Vect2D<Type>& v2){
        v1.X -= v2.X;
        v1.Y -= v2.Y;
        return v1;
    }

    // v * d
    inline Vect2D<Type> operator*(const Type d) const {
        return Vect2D<Type>(X*d, Y*d);
    }

    // v / d
    inline Vect2D<Type> operator/(const Type d) const {
        return (d != 0 ? Vect2D<Type>(X/d, Y/d) : Vect2D<Type>(0,0));
    }

    void Log(){std::cout << X << " " << Y << std::endl;}
};

using Vect2i = Vect2D<int>;
using Vect2f = Vect2D<float>;







