#include <cmath>
#include <iostream>
using namespace std;

int isPrime(unsigned int x) {
  if (x <= 1)
    return 0;

  unsigned int limit = sqrt(x);

  for (int i = 2; i <= limit; i++) {
    if (x % i == 0)
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  long long x;
  for (size_t i = 0; i < n; i++) {
    cin >> x;
    if (isPrime(x))
      std::cout << "Prime\n";
    else
      std::cout << "Not prime\n";
  }

  return 0;
}
