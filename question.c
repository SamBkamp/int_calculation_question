#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]){
  srand(time(NULL));
  
  if(argc < 3) {
    printf("please input n and k\n");
    exit(0);
  }

  int n = strtol(argv[1], (char **)NULL, 10);
  int k = strtol(argv[2], (char **)NULL, 10);
  int* firstPointer = malloc(sizeof(int) * n); //beginning of int array
  firstPointer[0] = (rand()%10) + 1; //random first integer
  int* endPointer = firstPointer + n;

  for (int* currentPointer = firstPointer+1; currentPointer < endPointer; currentPointer+=1){ //walk through each element in int* array
    int* start;
    int sum = 0;
    if(currentPointer-firstPointer < k){ //check if start at beginning or at k elements prior
      start = firstPointer;
    }else{
      start = currentPointer-k;
      
    }
    while(start < currentPointer){ //walk through all elements from start to where we are now
      sum += *start;
      start+=1;
    }
    *currentPointer = sum; //the sum then becomes the value of the current element in the array
  }

  for(int* number = firstPointer; number < endPointer; number+=1){ //printing loop - walks through array from start to finish, printing each element
    printf("%i ", *number);
  }
  printf("\n");

  free(firstPointer);
  
}
