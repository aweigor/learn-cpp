//
//  utils.cpp
//  char-frequency-2
//
//  Created by igor on 16.12.2023.
//

#include "utils.hpp"

void sortEntriesByFrequency(char* e, int* f)
{
  char key;
  int i = 1, j;
  
  while (e[i])
  {
    key = e[i];
    j = i - 1;
    while (j >= 0 && f[e[j]] < f[key])
    {
      e[j + 1] = e[j];
      j--;
    }
    e[j + 1] = key;
    i++;
  }
}

void sortEntries(char* e)
{
  char key;
  int i = 1, j;
  
  while (e[i])
  {
    key = e[i];
    j = i - 1;
    while (j >= 0 && e[j] > key)
    {
      e[j + 1] = e[j];
      j--;
    }
    e[j + 1] = key;
    i++;
  }
}
