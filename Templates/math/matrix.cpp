#include <bits/stdc++.h>
using namespace std;
/*
 * matrix exp
 */

// Implementation for square matrices.
struct Matrix {
  const static int N = 55;
  int n;
  long long v[N][N];
  Matrix(int _n) : n(_n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) v[i][j] = 0;
  }
  Matrix operator*(const Matrix &o) const {
    Matrix res(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          res.v[i][j] += v[i][k] * o.v[k][j];
    return res;
  }

  static Matrix getIdentity(int n) {
    Matrix res(n);
    for (int i = 0; i < n; i++) res.v[i][i] = 1;
    return res;
  }
  Matrix operator^(long long k) const {
    Matrix res = Matrix::getIdentity(n);
    Matrix a = *this;
    while (k) {
      if (k&1) res = res*a;
      a = a*a;
      k /= 2;
    }
    return res;
  }
};

/*
 * freddy frog
 FreddytheFroghasenteredanew
 pond.ThispondhasN+1lilypadsinarow,Freddyisat 
 lilypad0andwantstogettolilypadN. 
 FreddyhasmasteredKdifferentkindsofjumps,theith 
 jumpingFreddyforwarddililypads. 
 HowmanywayscanFreddyreachtheNthlilypad?Two 
 waysaredifferentifthesequenceofjumpsFreddy 
 performsisdifferent.OutputtheanswerMOD 
 1,000,000,007.
 recurrence:
 if jumps of 1, 2, 4 are available
 p(n) = p(n-1) + p(n-2) + p(n-4)
 */

const long long MOD = 1000000007;
const int MAXJUMP = 100;

int main() {
  int n, k;
  cin >> n >> k;
  Matrix rec(MAXJUMP);
  for (int i = 0; i < k; i++) {
    int d;
    cin >> d;
    // Note the d-1 here. 0 indexed
    rec.v[0][d-1] = 1;
  }

  for (int i = 1; i < MAXJUMP; i++)
    rec.v[i][i-1] = 1;
  
  rec = rec^n;
  // The first entry of rec^n multiplied by (1,0,...,0)^T
  cout << rec.v[0][0] << '\n';
}