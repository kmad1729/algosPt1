CC=g++
CC_Flags = -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL = quick_find quick_union

all: $(_ALL)

quick_find: quick_find.cc
	$(CC) -o $@ $(CC_Flags) $^

quick_union: quick_union.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
