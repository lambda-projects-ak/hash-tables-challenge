#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *)); // route is array of pointers

  /* YOUR CODE HERE */
  // loop over each ticket, add source as key, add destination as value
  for (int i = 0; i < length; i++)
  {
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  // start at src none, get destination, add destination to route
  int current = 0;
  // get first destination
  char *current_location = hash_table_retrieve(ht, "NONE");

  // setting current location to route at current index
  // increment current index each new location
  // then loop over all tickets until reaching destination == NONE
  while (strcmp(current_location, "NONE") != 0)
  {
    route[current] = current_location;
    current++;
    current_location = hash_table_retrieve(ht, current_location);
  }

  // once all tickets at added to route, set destination as NONE
  route[current] = "NONE";

  // clean up hash table
  destroy_hash_table(ht);

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "TEST";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  for (int i = 0; i < 3; i++)
  {
    free(tickets[i]);
  }

  free(tickets);

  return 0;
}
#endif
