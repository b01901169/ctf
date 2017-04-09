
HIDWORD = lambda x: (x>>32) & 0xffffffff
LOWWORD = lambda x: x & 0xffffffff

count = 1 # v16
state = 1
v7 = 1103515245 * state + 12345
state = v7 & 0x7fffffff # last 31 bits
v9 = state - (1000 * (274877907 * state) >> 32) >> 6
# 49080534052
v10 = v9 * HIDWORD(count) + (v9>>31) * count
v11 = v10 << 32 + LOWWORD(count * v9)
times = v11 % (1<<32 + 1)
#do state randm times


