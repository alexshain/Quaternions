#pragma once

#include <complex>
#include <filesystem>
#include <sstream>
#include <string>

#include "MatrixCT.h"

template<typename T, int rows = 4, int columns = 4>
class Quaternion : protected MatrixCT<T, rows, columns> {
private:
    T a_;
    T b_; 
    T c_; 
    T d_;
    MatrixCT<T, rows, columns> quaternion_;

    Quaternion(const MatrixCT<T, rows, columns>& quaternion) { 
        a_ = quaternion.element(0, 0);
        b_ = quaternion.element(1, 0);
        c_ = quaternion.element(2, 0);
        d_ = quaternion.element(3, 0);
        fillQuatMatrix();
    }

public:
    Quaternion() = default;

    Quaternion(T a, T b, T c, T d) : a_(a), b_(b), c_(c), d_(d) {
        fillQuatMatrix();
    }

    Quaternion(T a) : a_(a), b_(0), c_(0), d_(0) {
        fillQuatMatrix();
    }

    Quaternion(std::complex<T> complex) : a_(complex.real()), b_(complex.imag()), c_(0), d_(0) {
        fillQuatMatrix();
    }

    Quaternion operator+(const Quaternion& other) const {
        Quaternion q{quaternion_ + other.quaternion_};
        return q;
    }

    Quaternion operator+(const std::complex<T>& complex_number) const {
        Quaternion q_complex{complex_number};
        return Quaternion {quaternion_ + q_complex.quaternion_};
    }

    Quaternion operator+(T scalar) const {
        Quaternion q_scalsr{scalar};
        return Quaternion{quaternion_ + q_scalsr.quaternion_};
    }

    Quaternion operator*(const Quaternion& other) const {
        Quaternion q{quaternion_ * other.quaternion_};
        return q;
    }

    Quaternion operator*(std::complex<T> complex_number) const {
        Quaternion q_complex = Quaternion{complex_number};
        return Quaternion {quaternion_ * q_complex.quaternion_};
    }

    Quaternion operator*(T scalar) const {
        Quaternion q_scalsr{scalar};
        return Quaternion{quaternion_ * q_scalsr.quaternion_};
    }

    Quaternion operator-() const {
        return *this * (-1);
    }

    Quaternion operator-(const Quaternion& other) const {
        return *this + (-other);
    }

    Quaternion operator-(std::complex<T> complex_number) const {
        Quaternion q_complex{complex_number};
        return Quaternion{quaternion_ - q_complex.quaternion_};
    }

    Quaternion operator-(T scalar) const {
        Quaternion q_scalsr{scalar};
        return Quaternion{quaternion_ - q_scalsr.quaternion_};
    }

    Quaternion operator/(T scalar) const {
        return (*this)*(1.0/scalar);
    }

    bool operator==(const Quaternion& other) const {
        return a_ == other.a_ && b_ == other.b_ && c_ == other.c_ && d_ == other.d_;
    }

    void readScalars(std::filesystem::path path) {
        std::ifstream fin(path);
        fin >> a_;
        fin >> b_;
        fin >> c_;
        fin >> d_;
        fin.close();
        fillQuatMatrix();
    }

    void outputToConsole() {
        std::ostringstream oss;
        std::string imag_units[3] = {"i", "j", "k"};
        if(abs(quaternion_.element(0, 0)) > 1e-10) {
            oss << quaternion_.element(0, 0);
        }
        for(int i = 1; i < MatrixCT<T, 4, 4>::column_number_; ++i) {
            T element = quaternion_.element(i, 0);
            if(abs(element) > 1e-10 && element > 0 && oss.str().size() == 0) {
                oss << element << imag_units[i-1];
            } else if(abs(element) > 1e-10 && element > 0 && oss.str().size() != 0) {
                oss << "+" << element << imag_units[i-1];
            } else if(abs(element) > 1e-10 && element < 0) {
                 oss << element << imag_units[i-1];
            }
        }
        std::string result = oss.str();
        std::cout << result << std::endl;
    }

    friend Quaternion<T> operator+(std::complex<T> complex_number, const Quaternion<T>& other) {
        Quaternion q_complex = Quaternion{complex_number};
        return Quaternion{q_complex.quaternion_ + other.quaternion_};
    }

    friend Quaternion<T> operator+(T scalar, const Quaternion<T>& other) {
        Quaternion q_scalar = Quaternion{scalar};
        return Quaternion{q_scalar.quaternion_ + other.quaternion_};
    }

    friend Quaternion<T> operator*(std::complex<T> complex_number, const Quaternion<T>& other) {
        Quaternion q_complex = Quaternion{complex_number};
        return Quaternion{q_complex.quaternion_ * other.quaternion_};
    }

    friend Quaternion<T> operator*(T scalar, const Quaternion<T>& other) {
        Quaternion q_scalar = Quaternion{scalar};
        return Quaternion{q_scalar.quaternion_ * other.quaternion_};
    }

    friend Quaternion<T> operator-(std::complex<T> complex_number, const Quaternion<T>& other) {
        Quaternion q_complex = Quaternion{complex_number};
        return Quaternion{q_complex.quaternion_ + other.quaternion_*(-1)};
    }

    friend Quaternion<T> operator-(T scalar, const Quaternion<T>& other) {
        Quaternion q_scalar = Quaternion{scalar};
        return Quaternion{q_scalar.quaternion_ - other.quaternion_};
    }

private:
    void fillQuatMatrix() {
        int row = 4;
        int column = 4;
        std::vector<T> data(row * column);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column; ++j) {
                if(i == j) {
                    data[i * column + j] = a_;
                } else if(i + j == 1 || i + j == 5) {
                    data[i * column + j] = pow(-1, j)*b_;
                } else if(i + j == 3) {
                    data[i * column + j] = (i - j) > 0 ? d_ : -d_;
                } else if(abs(i - j) == 2) {
                    data[i * column + j] = (i - j)*pow(-1, j)*c_ / abs(i - j);
                }
            }
        }
        quaternion_ = MatrixCT<T, rows, columns>{data};
    }
};