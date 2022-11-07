#include <iostream>
#include <vector>
#include <complex>
#include "template_poly.hpp"
#include "template_quat.hpp"

int main(){
    std::vector<double> coeff1 {1., 2., 3., 4.};
    std::vector<double> coeff2 {2., 5., 6.};
    Polynom<double> Polynom_1(coeff1);
    Polynom<double> Polynom_2(coeff2);

    std::cout << "Sum of polys is ";
    (Polynom_1 + Polynom_2).print();

    std::vector<std::complex<double> > coeff3{{1., 2.},
                                              {3., 4.},
                                              {5., 6.}};
    std::vector<std::complex<double> > coeff4{{6., 5.},
                                              {4., 3.},
                                              {2., 1.}};
    Polynom <std::complex<double>> Polynom_3(coeff3);
    Polynom <std::complex<double>> Polynom_4(coeff4);
    std::cout << "Sum of polys is ";
    (Polynom_3 + Polynom_4).print();

    std::vector<Quat <double>> vector_q1{{1., 2., 3., 4.}, {5., 6., 7., 8.}};
    std::vector <Quat <double>> vector_q2{{1., 1., 1., 1.}, {1., 2., 3., 4.}, {5., 6., 7., 8.}};
    Polynom <Quat <double>> quat_1 (vector_q1);
    Polynom <Quat <double>> quat_2 (vector_q2);
    std::cout << "Sum of quats is ";
    std::cout << (quat_1 + quat_2) << std::endl;
    return 0;
}
