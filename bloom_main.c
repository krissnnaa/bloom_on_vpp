//
// Created by krishna on 10/24/17.

#include "bloom_header.h"

//FNV hash function
unsigned long int FNV_Hash(unsigned long int *str)
{
    const unsigned int fnv_prime = 0x811C9DC5;
    unsigned long int hash      = 0;
    unsigned int i         = 0;
    unsigned int length=strlen(str);

    for(i = 0; i < length; str++, i++)
    {
        hash = hash * fnv_prime;
        hash = hash ^ (*str);
    }


    return hash;
}

//RS hash function
unsigned long int RS_Hash(unsigned long int * str)
{
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned long int hash = 0;
    unsigned int i    = 0;
    unsigned int length=strlen(str);
    for (i = 0; i < length; ++str, ++i)
    {
        hash = hash * a + (*str);
        a    = a * b;
    }

    return hash;
}

//JS hash function
unsigned long int JS_Hash(unsigned long int * str)
{
    unsigned long int hash = 1315423911;
    unsigned int i    = 0;
    unsigned int length=strlen(str);

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((hash << 5) + (*str) + (hash >> 2));
    }

    return hash;
}

//This function creates new bloom filter
int create_bloom_filter(struct bloom_filter **b_filter, int size){

    struct bloom_filter *filter;
    filter=malloc(sizeof(struct bloom_filter));
    filter->bit_s->bit_size=calloc(sizeof(char),size);
    filter->filter_size=size;
    *b_filter=filter;
    return 1;

}

//This function is used to fill up entries in a bloom filter
int insert_entries_into_bloom_filter(struct bloom_filter *filter, void *key){
    unsigned long int hash_1= FNV_Hash((unsigned long int *)key);
    filter->bit_s->bit_size[hash_1]==1;
    unsigned long int hash_2= RS_Hash((unsigned long int *)key);
    filter->bit_s->bit_size[hash_2]==1;
    unsigned long int hash_3= JS_Hash((unsigned long int *)key);
    filter->bit_s->bit_size[hash_3]==1;
}

//This function is used to test membership
int lookup_of_bloom_filter(struct bloom_filter *b_filter,void *key) {
    unsigned long int hash_1= FNV_Hash((unsigned long int *)key);
    unsigned long int hash_2= RS_Hash((unsigned long int *)key);
    unsigned long int hash_3= JS_Hash((unsigned long int *)key);
    if(b_filter->bit_s->bit_size[hash_1]==1 && b_filter->bit_s->bit_size[hash_2]==1 && b_filter->bit_s->bit_size[hash_3]==1)
        return 1;
    else
        return 0;

}


