// Random Number Generator
#include "Random123/philox.h"
#include "Random123/examples/u01fixedpt.h"
#include "stdio.h"

int main() {

  unsigned int WORKER=1;
  unsigned int seed=1000;
  int iteration=1;
  philox4x32_key_t k1 = {{WORKER, 0xdecafbad}};
  philox4x32_key_t k2 = {{0xC001CAFE, 0xdecafbad}};
  philox4x32_ctr_t c = {{0, seed, iteration, 0xBADC0DED}};//0xBADCAB1E
  philox4x32_ctr_t r;
  printf("%u, %u, %u, %u\n", c.v[0], c.v[1], c.v[2], c.v[3]);
  for (int i=0; i<10; i++) {
    ++c.v[0];
    r = philox4x32_R(7, c, k1);
    printf("r: %u %u %u %u\n", r.v[0], r.v[1], r.v[2], r.v[3]);
    printf("fixedpt: %f\n", u01fixedpt_open_open_32_24(r.v[i%4]));
  }
  
  return 0;
}
