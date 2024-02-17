#include "s21_matrix_oop.h"

#include <cmath>
#include <iostream>

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

void S21Matrix::Print() {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
};

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < cols_; i++) {
    matrix_[i] = new double[cols_];
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
};
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("Error");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0 || rows_ <= 0) {
    throw std::out_of_range("Error");
  }
  S21Matrix temp(rows_, cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (j < cols) temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  for (int i = 0; i < rows_; ++i) {
    delete matrix_[i];
  }
  delete matrix_;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  *this = temp;
}

void S21Matrix::setRows(int rows) {
  if (rows <= 0 || cols_ <= 0) {
    throw std::out_of_range("Error");
  }
  S21Matrix temp(rows, cols_);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols_; j++) {
      temp.matrix_[i][j] = 0;
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i < rows_) temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  for (int i = 0; i < rows_; ++i) {
    delete matrix_[i];
  }
  delete matrix_;
  rows_ = rows;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  *this = temp;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete matrix_[i];
  }
  delete matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Error");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if ((rows_ == other.rows_) && (cols_ == other.cols_)) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  } else {
    throw std::out_of_range("Error");
  }
}

void S21Matrix::MulNumber(const double num) {
  if (getCols() == 0 || getRows() == 0) {
    throw std::out_of_range("Error");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.rows_) {
    S21Matrix temp(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < other.cols_; ++j) {
        for (int k = 0; k < cols_; ++k) {
          temp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = temp;
  } else {
    throw std::out_of_range("Error");
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix temp(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      temp.matrix_[j][i] = matrix_[i][j];
    }
  }
  return temp;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    delete matrix_[i];
  }
  delete matrix_;
  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i > rows_ || j > cols_) {
    throw std::out_of_range("Error");
  }
  return matrix_[i][j];
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix temp = *this;
  temp += other;
  return temp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix temp = *this;
  temp -= other;
  return temp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix temp = *this;
  temp *= other;
  return temp;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix temp = *this;
  temp *= num;
  return temp;
}

S21Matrix S21Matrix::Minor(int row, int col) {
  S21Matrix temp(rows_ - 1, cols_ - 1);
  int temp_row = 0;
  int temp_col = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i != row) {
      temp_col = 0;
      for (int j = 0; j < cols_; ++j) {
        if (j != col) {
          temp.matrix_[temp_row][temp_col] = matrix_[i][j];
          ++temp_col;
        }
      }
      ++temp_row;
    }
  }
  return temp;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::out_of_range("Error");
  }
  if (rows_ == 1) {
    return matrix_[0][0];
  } else if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    double det = 0;
    for (int i = 0; i < cols_; ++i) {
      det += pow(-1, i) * matrix_[0][i] * Minor(0, i).Determinant();
    }
    return det;
  }
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Error");
  }
  S21Matrix temp = *this;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      temp.matrix_[i][j] = pow(-1, i + j) * Minor(i, j).Determinant();
    }
  }
  return temp;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_ || Determinant() == 0) {
    throw std::out_of_range("Error");
  }
  double det = Determinant();
  S21Matrix temp = this->CalcComplements().Transpose();
  temp *= (1 / det);
  return temp;
}
