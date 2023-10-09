#include <bits/stdc++.h>

using namespace std;

// Multiplies two matrices and returns the result.
vector<vector<int>> matrix_product(vector<vector<int>> const& matrix1, vector<vector<int>> const& matrix2) {
  int n = matrix1.size();
  vector<vector<int>> result(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

// Extracts a matrix from a string.
vector<vector<int>> extract_matrix(int n, const char* str) {
  int i = 0, j = 0;
  vector<vector<int>> matrix(n);

  int s = 0;
  while (str[i] != '$') {
    if (str[i] == '.') {
      matrix[j].push_back(s);
      s = 0;
    } else if (str[i] == ',') {
      matrix[j].push_back(s);
      ++j;
      s = 0;
    } else {
      s *= 10;
      s += str[i] - '0';
    }

    ++i;
  }
  matrix[j].push_back(s);

  return matrix;
}

int main(int argc, char** argv) {
  time_t start, end;

  int n;
  sscanf(argv[1], "%d", &n);

  const char* mat1 = argv[2];
  const char* mat2 = argv[3];

  time(&start);

  vector<vector<int>> matrix1 = extract_matrix(n, mat1);
  vector<vector<int>> matrix2 = extract_matrix(n, mat2);

  vector<vector<int>> result = matrix_product(matrix1, matrix2);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << result[i][j] << ' ';
    }

    cout << endl;
  }

  time(&end);

  double time_taken = double(end - start);
  cout << time_taken << endl;

  return 0;
}