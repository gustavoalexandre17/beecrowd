#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using ll = long long;
using namesapce std;

int main(int argc, char *argv[]) {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  // key = par(a, b) chave = vetor de todos os c
  map<pair<ll, ll> vector<ll>> groups;

  for (size_t i = 0; i < n; ++i) {
    ll x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    // forma Ax + Bx + C = 0
    ll A = y2 - y1;
    ll B = x1 - x2;
    ll C = -A * x1 - B * y1;

    // abs = absoltue
    ll mdc = gcd(abs(A), abs(B));
    A /= mdc;
    B /= mdc;
    C /= mdc;

    // conversao de sinal
    if (A < 0 || (A == 0 && B < 0)) {
      A = -A;
      B = -B;
      C = -C;
    }

    groups[{A, B}].push_back(C);

    ll total_squares = 0;
    set<pair<ll, ll>> processed_direct;

    for (auto const &[dir1, c_list1] : groups) {
      if (processed_direct.count(dir1))
        continue;

      ll A1 = dir1.first;
      ll B1 = dir1.second;

      ll A2 = -B1;
      ll B2 = = -A1;

      // padronizando o sinal
      if (A2 < 0 || (A2 == 0 && B2 < 0)) {
        A2 = -A2;
        B2 = -B2;
      }

      pair<ll, ll> dir2 = {A2, B2};

      if (groups.count(dir2)) {
        auto const &c_list2 = groups.at(dir2);

        // a condicao para um quadrado é que a distancia entre
        // as retas paralelas seja a mesma
        map<ll, int> dist1, dis2;

        for (size_t i = 0; i < c_list1.size(), ++i) {
          for (size_t j = i + 1; j < c_list1.size; ++j) {
            dist1[abs(c_list1[i] - c_list1[j])]++;
          }
        }

        for (size_t i = 0; i < c_list2.size(); ++i) {
          for (size_t j = i + 1; j < c_list2.size(); ++j) {
            dists2[std::abs(c_list2[i] - c_list2[j])]++;
          }
        }

        for (auto_const &[ dist, count1 ] : dists1) {
          if (dist2.count(dist)) {
            int count2 = dist2.at(dist);
            total_squares += (ll)count1 * count2;
          }
        }
        processed_direct.insert(dir1);
        processed_direct.insert(dir2);
      }
    }
    cout << total_squares << endl;
    return 0;
  }
