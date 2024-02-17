
#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  // Rule of five
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Operator
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  double& operator()(int row, int col);

  bool operator==(const S21Matrix& other);

  // Methods
  void Print();
  void setRows(int rows);
  void setCols(int cols);
  int getRows() { return rows_; };
  int getCols() { return cols_; };
  void SumMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix Minor(int row, int col);
  S21Matrix InverseMatrix();
};

#endif
