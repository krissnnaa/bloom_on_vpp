//
// Created by krishna on 10/24/17.
//

#ifndef BLOOM_FILTER_BLOOM_HEADER_H
#define BLOOM_FILTER_BLOOM_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct bloom_size{

    bool *bit_size;
};

struct bloom_filter{
    int filter_size;
    int hash_function;
    struct bloom_size *bit_s;

};

int create_bloom_filter(struct bloom_filter **filter, int s );
int insert_entries_into_bloom_filter(struct bloom_filter *filter, void *key);
int lookup_of_bloom_filter(struct bloom_filter *filter,void *key);
#endif //BLOOM_FILTER_BLOOM_HEADER_H
