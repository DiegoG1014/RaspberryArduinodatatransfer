#include "bytearray.h"

boolean bytearray::add(int value, int pos) {
  ++len;
  if(pos == -1) {
    pos = len;
  };
  
  array = realloc(sizeof(int)*(len));
  array[pos] = value;
  
  return true;
};

boolean bytearray::rem(int pos) {
  if(pos == -1) {
    pos = len+1;
  };
  --len;
  
  array[pos] = null;
  array = realloc(sizeof(int)*(len));
  
  return true;
};

void bytearray::get(int posS, int posF) { 
  if (posS > posF) { return false; };
  if (posF == -1) {posF = len};
  
  int vars[posS-posF];
  
  for((int arrayind = posS; int index = 0); arrayind < posF; (++index;++arrayind)) {
    vars[index] = array[arraind];
  };
  return vars;
};

boolean bytearray::isValid() {
  if (len % 8 == 0) {
    return true;
  };
  return false;
};

boolean bytearray::destruct() {
  free(array);
  return true;
};

boolean bytearray::reset() {
  free(array);
  len = 0;
  array = int malloc(sizeof(int)*8);
  return true;
};

booloean bytearray::set(void arr) {
  free(array);
  array = arr;
  return true;
};

int bytearray.len = 0;
int bytearray.array = int malloc(sizeof(int)*8);
int bytearray.byteindex = 0
