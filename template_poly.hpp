#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "template_quat.hpp"


template<typename T>
class Polynom {
public:
    std::vector<T> coeff;

    //конструктор
    Polynom(int len);

    Polynom(const std::vector<T> &data);

    Polynom() = default;

    // Операторы
    Polynom<T> operator+(const Polynom<T> &p2);

    Polynom<T> operator-(const Polynom<T> &p2);

    Polynom<T> operator*(const Polynom<T> &p2);

    void print();
};

template<typename T>
Polynom<T>::Polynom(int len) {
    coeff.resize(len);
    for (int i = 0; i < len; ++i) {
        coeff[i] = 0;
    }
};

template<typename T>
Polynom<T>::Polynom(const std::vector<T> &data) {
    for (int i = 0; i < data.size(); ++i) {
        coeff.push_back(data[i]);
    }
};

// +
template<typename T>
Polynom<T> Polynom<T>::operator+(const Polynom<T> &p) {
    Polynom<T> summ_polynom(std::max(coeff.size(), p.coeff.size()));
    if (coeff.size() >= p.coeff.size()) {
        for (int i = 0; i < coeff.size(); ++i) {
            summ_polynom.coeff[i] = coeff[i];
        }
        for (int i = 0; i < p.coeff.size(); ++i) {
            summ_polynom.coeff[i] += p.coeff[i];
        }
    } else {
        for (int i = 0; i < p.coeff.size(); ++i) {
            summ_polynom.coeff[i] = p.coeff[i];
        }
        for (int i = 0; i < coeff.size(); ++i) {
            summ_polynom.coeff[i] += coeff[i];
        }
    }
    return summ_polynom;
};

// -
template<typename T>
Polynom<T> Polynom<T>::operator-(const Polynom<T> &p) {
    Polynom differ_polynom(std::max(coeff.size(), p.coeff.size()));
    if (coeff.size() >= p.coeff.size()) {
        for (int i = 0; i < coeff.size(); ++i) {
            differ_polynom.coeff[i] = coeff[i];
        }
        for (int i = 0; i < p.coeff.size(); ++i) {
            differ_polynom.coeff[i] -= p.coeff[i];
        }
    } else {
        for (int i = 0; i < p.coeff.size(); ++i) {
            differ_polynom.coeff[i] = p.coeff[i];
        }
        for (int i = 0; i < coeff.size(); ++i) {
            differ_polynom.coeff[i] -= coeff[i];
        }
    }
    return differ_polynom;
};

// *
template<typename T>
Polynom<T> Polynom<T>::operator*(const Polynom<T> &p) {
    int result = (coeff.size() - 1) + (p.coeff.size() - 1) + 1;
    Polynom mult_polynom(result);

    for (int i = 0; i < coeff.size(); i++)
        for (int j = 0; j < p.coeff.size(); j++)
            mult_polynom.coeff[i + j] += coeff[i] * p.coeff[j];

    return mult_polynom;
};

template<typename T>
void Polynom<T>::print() {
    std::cout << "[" << coeff[0];
    for (int i = 1; i < coeff.size(); ++i) {
        std::cout << " " << coeff[i];
    }
    std::cout << "]" << std::endl;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, Polynom<T> p) {
    for (int i = 0; i < p.coeff.size(); ++i) {
        os << p.coeff[i];
    }
    os << std::endl;
    return os;
}