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
