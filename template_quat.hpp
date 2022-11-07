#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "template_poly.hpp"

template <typename T>
class Quat{
public:
    T s = 0;
    T x = 0;
    T y = 0;
    T z = 0;
    Quat() = default;

    Quat<T> operator + (const Quat<T> &q2);
    Quat<T> operator = (int n);
    Quat<T> operator - (const Quat<T> &q2);
    Quat<T> operator * (const Quat<T> &q2);
    bool operator == (const Quat<T> &quat);
    bool operator != (const Quat<T> &quat);
    Quat<T>& operator += (const Quat<T> &quat);
    Quat<T> operator * (int num);

    void print();

};

template <typename T>
Quat<T> Quat<T>::operator + (const Quat<T> &q2){
    return Quat<T>(s + q2.s, x + q2.x, y + q2.y, z + q2.z);
};

template <typename T>
Quat<T> Quat<T>::operator = (int n){
   this->s=n;
   this->x=n;
   this->y=n;
   this->z=n;
    return *this;
}

template <typename T>
Quat<T> Quat<T>::operator - (const Quat<T> &q2){
    return Quat<T>(s - q2.s, x - q2.x, y - q2.y, z - q2.z);
};

template <typename T>
Quat<T> Quat<T>::operator * (const Quat<T> &q2){
    return Quat<T>(
            s * q2.s - x * q2.x - y * q2.y - z * q2.z,
            s * q2.x + x * q2.s + y * q2.z - z * q2.y,
            s * q2.y - x * q2.z + y * q2.s + z * q2.x,
            s * q2.z + x * q2.y - y * q2.x + z * q2.s
    );
};

template<typename T>
Quat<T> Quat<T>::operator * (int num){
    return Quat<T>(s * num, x * num, y * num, z * num);
};

template<typename T>
bool Quat<T>::operator == (const Quat<T> &quat){
    return ((s == quat.s) and (x == quat.x) and (y == quat._j) and (z == quat._k));
};

template<typename T>
bool Quat<T>::operator != (const Quat<T> &quat){
    return ((s != quat.s) or (x != quat.x) or (y != quat.y) or (z != quat.z));
};

template<typename T>
Quat<T>& Quat<T>::operator += (const Quat<T> &quat){
    s = s + quat.s;
    x = x + quat.x;
    y = y + quat.y;
    z = z + quat.z;
    return *this;
};

template<typename R>
std::ostream &operator<<(std::ostream &os, Quat<R> &quat) {
    os << "(" << quat.s << ", [" << quat.x << ", " << quat.y << ", " << quat.z << "])";
    return os;
};
