#include <iostream>
#include <string>
using namespace std;

static inline int fat(int x) {
  if (x <= 1)
    return 1;
  return x * fat(x - 1);
}

int main(int argc, char *argv[]) {
  string usr;

  while (cin >> n && n != 0) {
    const int size = usr.size();
    int buffer, result;
    result = 0;

    for (int i = size; i > 0; i--) {
      int temp = usr[size - i] - '0';
      buffer = temp * fat(i);
      result += buffer;
    }
    cout << result << endl;
  }
  return 0;
}
