#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  // goal - find two items who sum weights equals limit, return instance of answer

  if (length > 1)
  {
    // loop over weights, store weight as key, store (weight - limit) as value
    for (int i = 0; i < length; i++)
    {
      hash_table_insert(ht, weights[i], i);
    }
    // then hash the value of the weight passed in to get the other index
  }

  for (int i = 0; i < length; i++)
  {
    // check key against each value, look for a matching limit
    int index = hash_table_retrieve(ht, weights[i]);
    // compare value of node to key of node + 1
    if (limit - ht->storage[i]->key)
    {
      printf("%s\n", "match found");
      printf("%d\n", index);
      printf("%d\n", i);
      break;
    }
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  // int weights_1 = {9};
  // Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  // print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  // int weights_3[] = {4, 6, 10, 15, 16};
  // Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  // print_answer(answer_3); // {3, 1}

  // // TEST 4
  // int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  // Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  // print_answer(answer_4); // {6, 2}

  return 0;
}

#endif
