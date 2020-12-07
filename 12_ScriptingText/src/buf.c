/* COMMENT:: Growable Memory Buffers for C99, 0.0: Tue Dec  8 00:01:51 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Tue Dec  8 00:01:14 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Tue Dec  8 00:00:00 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Mon Dec  7 23:58:42 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Mon Dec  7 23:58:11 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Mon Dec  7 23:22:41 MSK 2020 */
#include <stdio.h>
#include "buf.h"
int main(void){
float *values = 0;
for (size_t i = 0; i < 25; i++)
    buf_push(values, rand() / (float)RAND_MAX);

/* Access 25 values using the normal [] operator */
for (size_t i = 0; i < buf_size(values); i++)
    printf("values[%zu] = %f\n", i, values[i]);

/* Destroy/reset the buffer */
buf_free(values);
}
