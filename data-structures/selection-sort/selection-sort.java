
import java.util.Arrays;

//code in Java
public class Main {
  public static void selectionSort(int [] numbers) {
    int i,j,indexSmallest,temp;

    //##### selection sort loop
    //this incrementally moves the boundary of the unsorted array
    for (i = 0; i < numbers.length - 1; ++i) {
      // define smallest index as first index value initially
      indexSmallest = i;
      // find the index of the smallest element
      for (j = i + 1; j < numbers.length; ++j) {
        //if j is less than i, then j becomes smallest index
        if (numbers[j] < numbers[indexSmallest]){
          //set smallest index as j
          indexSmallest = j;
        }
      }
      //do swap of smallest index when needed
      //save current number at ith index to temp
      temp = numbers[i];
      //place number at indexsmallest index to ith index
      numbers[i] = numbers[indexSmallest];
      //place number at temp into index of smallest index
      numbers[indexSmallest] = temp;
      }
     //##### end of selection sort loop
    
    //swap minimum element and first elements
    //since now fully swapped, minimum element is index 0
    //repeats process of temp swap above, with 0 as the smallest index and 1 as the ith index
    indexSmallest=0;
    temp=numbers[indexSmallest];
    numbers[indexSmallest] = numbers[1];
    numbers[1] = temp;
  }

public static void main(String[] args) {
  //create array
  int[] array = new int[21];
  // set up first values for array
  int numval=50;
  int i=0;
  //fill array
  for ( i=0; i<array.length; i++){
    array[i]=numval;
    numval++;
  }
  //print out initial array
  System.out.println("INITIAL ARRAY: ");
  System.out.println(Arrays.toString(array));
  
  //apply selection sort (with the minimum and first values switched)
  selectionSort(array);
  System.out.println("SELECTION SORTED: ");
  System.out.println(Arrays.toString(array));
  }
}