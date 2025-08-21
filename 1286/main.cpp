#include <bits/stdc++.h>
using namespace std;

const int CAPACIDADE_MAX = 30;

int maxValue(int i, int j, const vector<int> &w, const vector<int> &v,
             int (*m)[CAPACIDADE_MAX + 1]) {
  if (i == 0 || j == 0) {
    return 0;
  }
  if (m[i][j] != -1) {
    return m[i][j];
  }
  if (w[i - 1] > j) {
    m[i][j] = maxValue(i - 1, j, w, v, m);
  } else {
    m[i][j] = max(maxValue(i - 1, j, w, v, m),
                  v[i - 1] + maxValue(i - 1, j - w[i - 1], w, v, m));
  }
  return m[i][j];
}

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N == 0)
      break;

    int P;
    cin >> P;

    vector<int> pizzas(N);
    vector<int> tempo(N);

    for (int i = 0; i < N; ++i) {
      cin >> tempo[i] >> pizzas[i];
    }

    int memo[N + 1][CAPACIDADE_MAX + 1];
    memset(memo, -1, sizeof(memo));

    int resultado = maxValue(N, P, pizzas, tempo, memo);
    cout << resultado << " min." << endl;
  }
  return 0;
}
