#include "buf.h"


#suite grow_buf
#test push_and_grow
    long *ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
    ck_assert_msg(buf_size(ai) == 10000, "size 10000");
    int match = 0;
    for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;
    ck_assert_msg(match == 10000, "match 10000");
    buf_free(ai);
    buf_grow(ai, 1000);
    ck_assert_msg( buf_capacity(ai) == 1000, "grow 1000");
    ck_assert_msg(buf_size(ai) == 0, "size 0 (grow)");
    buf_trunc(ai, 100);
    ck_assert_msg( buf_capacity(ai) == 100, "trunc 100");
    buf_free(ai)
