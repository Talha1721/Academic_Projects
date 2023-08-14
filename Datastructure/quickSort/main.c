



#include <stdio.h>




int partition(int left, int right, int pivot,int intArray[]) {
   int leftPointer = left ;
   int rightPointer = right;

   while(1) {
      while(intArray[leftPointer] < pivot) {
         leftPointer++;
      }

      while(rightPointer > 0 && intArray[rightPointer] > pivot) {
         rightPointer--;
      }

      if(leftPointer >= rightPointer) {
         return leftPointer;
      } else {

   int temp = intArray[leftPointer];
   intArray[leftPointer] = intArray[rightPointer];
   intArray[rightPointer] = temp;
      }
   }

   // pivot swapped

 /*  c=intArray[leftPointer];
    intArray[leftPointer]=intArray[right];
    intArray[right]=c;


   return leftPointer;  */
}

void quickSort(int left, int right,int intArray[]) {
   if(right>left) {
      int pivot = intArray[right];
      int partitionPoint = partition(left, right, pivot,intArray);
      quickSort(left,partitionPoint-1,intArray);
      quickSort(partitionPoint+1,right,intArray);
   } else {
      return;
   }
}


int main() {
    int i,MAX;
    scanf("%d",&MAX);
    int Array[MAX];
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&Array[i]);
    }
   printf("Input Array: ");
   quickSort(0,MAX-1, Array);
   printf("Output Array: ");
   for(i =0;i < MAX;i++) {
      printf("%d ",Array[i]);
   }



}
