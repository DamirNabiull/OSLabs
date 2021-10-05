#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc_new(void *ptr, size_t size){
  if(size == 0){ 
    free(ptr);
    return NULL;
  }
  else if (!ptr) {
      return malloc(size);
  }
  else {
      void *temp = malloc(size);
      memcpy(temp,ptr,size);
      free(ptr);
      return temp;
  }
}

int main() {
	return 0;
}