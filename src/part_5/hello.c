#include "fcgi_stdio.h"
#include <stdlib.h>

int main(void) {
  while (FCGI_Accept() >= 0) {
    printf(
        "Content-type: text/html\r\nStatus: 200 OK\r\n"
        "\r\n"
        "<title>Hello World!</title>"
        "<h1>Hello World!</h1>"
        "<h2>SPARRVIO</h2>"
        "<h2>PART 5</h2>");
  }
  return 0;
}