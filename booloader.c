#include <inttypes.h>
#include "memory_map.h"

int main(void) {
  uint32_t *app_code = (uint32_t *)__approm_start__;
  uint32_t app_sp = app_code[0];
  uint32_t app_start = app_code[1];
  /* TODO: Start app */
  /* Not Reached */
  uint32_t *src = (uint32_t*) &__approm_start__;
  uint32_t *dst = (uint32_t*) &__eram_start__;
  int size = (int) &__approm_size__;
  printf("Copying firmware from %p to %p\n", src, dst);
  memcpy(dst, src, size);

  /* find app start & SP */
  uint32_t app_sp = dst[0];
  uint32_t app_start = dst[1];

  /* cleanup peripherals here we may have initialized */

  /* start the app */
  start_app(app_start, app_sp)
  while (1) {}
}
