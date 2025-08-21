#include <iostream>
#include <string>
using namespace std;

string invert(string str, int size) {
  for (int i = 0; i < size / 2; i++) {
    char temp = str[i];
    str[i] = str[size - 1 - i];
    str[size - 1 - i] = temp;
  }
  return str;
}

int main() {
  int n;
  cin >> n;
  cin.ignore(); // limpar o \n que ficou no buffer

  for (int i = 0; i < n; i++) {
    string usr;
    getline(cin, usr);
    int usr_Size = usr.length();
    for (int j = 0; j < usr_Size; j++) {
      usr[j] += 3;
    }
    string bufferPtr = invert(usr, usr_Size);

    for (int j = usr_Size / 2; j < usr_Size; j++) {
      bufferPtr[j] -= 1;
    }
    cout << bufferPtr << endl;
  }

  return 0;
}
