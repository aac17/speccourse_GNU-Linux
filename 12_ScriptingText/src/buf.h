/* COMMENT:: Growable Memory Buffers for C99, 0.0: Tue Dec  8 00:01:51 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Tue Dec  8 00:01:14 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Tue Dec  8 00:00:00 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Mon Dec  7 23:58:42 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Mon Dec  7 23:58:11 MSK 2020 */
/* COMMENT:: Growable Memory Buffers for C99, 0.0: Mon Dec  7 23:22:41 MSK 2020 */
#include <stdlib.h>
#include <stddef.h>

#ifndef BUF_INIT_CAPACITY
#  define BUF_INIT_CAPACITY 8
#endif

#ifndef BUF_ABORT
#  define BUF_ABORT abort()
#endif


struct buf {
    size_t capacity;
    size_t size;
    char buffer[];
};

#define buf_ptr(v) \
    ((struct buf *)((char *)(v) - offsetof(struct buf, buffer)))

#define buf_free(v) \
    do { \
        if (v) { \
            free(buf_ptr((v))); \
            (v) = 0; \
        } \
    } while (0)

#define buf_size(v) \
    ((v) ? buf_ptr((v))->size : 0)

#define buf_capacity(v) \
    ((v) ? buf_ptr((v))->capacity : 0)

#define buf_push(v, e) \
    do { \
        if (buf_capacity((v)) == buf_size((v))) { \
            (v) = buf_grow1(v, sizeof(*(v)), \
                            !buf_capacity((v)) ? \
                              BUF_INIT_CAPACITY : \
                              buf_capacity((v))); \
        } \
        (v)[buf_ptr((v))->size++] = (e); \
    } while (0)

#define buf_pop(v) \
    ((v)[--buf_ptr(v)->size])

#define buf_grow(v, n) \
    ((v) = buf_grow1((v), sizeof(*(v)), n))

#define buf_trunc(v, n) \
    ((v) = buf_grow1((v), sizeof(*(v)), n - buf_capacity(v)))

#define buf_clear(v) \
    ((v) ? (buf_ptr((v))->size = 0) : 0)
    
    
void *
buf_grow1(void *v, size_t esize, ptrdiff_t n);
