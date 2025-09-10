#include <iostream>

#include <libheif/heif.h>

using namespace std;

int main() {
  printf("Hello, World!\n");

  // print libheif version:
  cout << "libheif version: " << heif_get_version() << endl;
  return 0;
}