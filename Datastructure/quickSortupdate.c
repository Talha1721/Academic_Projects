#include <stdio.h>

#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void swap(int num1, int num2) {
   int temp = intArray[num1];
   intArray[num1] = intArray[num2];
   intArray[num2] = temp;
}
int partition(int left, int right, int pivot) {
   int leftPointer = left ;
   int rightPointer = right;
   int temp,c;

   while(1) {
      while(intArray[leftPointer] < pivot) {
         leftPointer++;
      }

      while(rightPointer > 0 && intArray[rightPointer] > pivot) {
         rightPointer--;
      }

      if(leftPointer >= rightPointer) {
         return leftPoiter;
      } else {
           swap(leftPointer,rightPointer);
        // temp=leftPointer;
         //leftPointer=rightPointer;
         //rightPointer=temp;
      }
   }

   // pivot swapped
   swap(leftPointer,right);
  // c=leftPointer;
    //leftPointer=right;
   // right=c;


   return leftPointer;
}

void quickSort(int left, int right) {
   if(right>left) {
      int pivot = intArray[right];
      int partitionPoint = partition(left, right, pivot);
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   } else {
      return;
   }
}


int main() {
    int i;
   printf("Input Array: ");
   quickSort(0,MAX-1);
   printf("Output Array: ");
   for(i = 0;i < MAX;i++) {
      printf("%d ",intArray[i]);
   }



}

