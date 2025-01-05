#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <tuple>
#include <fstream>
#include <cstring>

template<typename T, int row_number, int column_number>
class MatrixCT {
protected:
    int row_number_ = row_number;
    int column_number_ = column_number;
    std::vector<T> data_;

public:
        MatrixCT() : data_(row_number * column_number) {};
        MatrixCT(const MatrixCT& other) = default;
        MatrixCT& operator=(const MatrixCT& other) = default;
        MatrixCT(MatrixCT&& other) = default;
        MatrixCT& operator=(MatrixCT&& other) = default;
        ~MatrixCT() = default;

        MatrixCT(std::vector<T> other_data) {
            if (other_data.size() != row_number_ * column_number_) {
                throw std::invalid_argument("The data vector is of the wrong size!");
            }
            data_ = other_data;
        }

        MatrixCT(std::filesystem::path matrix_path) {
            std::ifstream fin(matrix_path);
            //проверить, что будет, если файл закончится раньше
            for (size_t i = 0; i < total_size(); ++i) {
                fin >> data_[i];
            }
            fin.close();
        }

        size_t total_size() const {
            return row_number_ * column_number_;
        }

        T& element(size_t row_ind, size_t colum_ind) {
            return data_[row_ind * column_number_ + colum_ind];
        }

        T element(size_t row_ind, size_t colum_ind) const {
            return data_[row_ind * column_number_ + colum_ind];
        }

        void WriteToFile(std::filesystem::path file_path) {
            std::ofstream fout(file_path);
            fout << row_number_ << column_number_ << std::endl;
            for (size_t i = 0; i < row_number_; ++i) {
                for (size_t j = 0; j < column_number_; ++j) {
                    fout << data_[column_number_ * i + j] << " ";
                }
                fout << std::endl;
            }
            fout.close();
        }

        MatrixCT Slice(size_t row_start, size_t row_end,
            size_t column_start, size_t colum_end) {
            MatrixCT slice{ row_end - row_start, colum_end - column_start };
            for (size_t i = 0; i < slice.row_number_; ++i) {
                std::memcpy(slice.data_.data() + i * slice.column_number_,
                    data_.data() + column_number_ * (row_start + i) + column_start,
                    sizeof(double) * (colum_end - column_start));
            }
            return slice;
        }

        MatrixCT operator+(const MatrixCT& other) const {
            if (row_number_ != other.row_number_ || column_number_ != other.column_number_) {
                throw std::invalid_argument("Matrices have different dimensions!");
            }

            MatrixCT result{};
            for (size_t i = 0; i < total_size(); ++i) {
                result.data_[i] = data_[i] + other.data_[i];
            }
            return result;
        }

        MatrixCT operator-() const {
            return *this * (-1);
        }

        MatrixCT operator-(const MatrixCT& other) const {
            return *this + (-other);
        }

        MatrixCT operator*(double scalar) const {
            MatrixCT result{};
            for (size_t i = 0; i < total_size(); ++i) {
                result.data_[i] = data_[i] * scalar;
            }
            return result;
        }

        MatrixCT operator*(const MatrixCT& other) const {
            if (column_number_ != other.row_number_) {
                throw std::invalid_argument("Matrices dimensions are incompatible for multiplication!");
            }
            MatrixCT result{};
            for (size_t i = 0; i < row_number_; ++i) {
                for (size_t j = 0; j < other.column_number_; ++j) {
                    result.element(i, j) = 0;
                    for (size_t k = 0; k < column_number_; ++k) {
                        result.element(i, j) += element(i, k) * other.element(k, j);
                    }
                }
            }
            return result;
        }

        T& operator[](std::tuple<size_t, size_t> ind) {
            return data_[get<0>(ind) * column_number_ + get<1>(ind)];

        }

        T operator[](std::tuple<size_t, size_t> ind) const {
            return data_[get<0>(ind) * column_number_ + get<1>(ind)];
        }
};

template<typename T, int row_number, int column_number>
MatrixCT<T, row_number, column_number> operator*(double scalar, const MatrixCT<T, row_number, column_number>& matrix) {
    return matrix * scalar;
}

