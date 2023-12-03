#CIS 131 Exam 1
#Rosemary Moseley
#Due: 9/14/23


#Selection Sort in Python
def selectionSort(array, size):
  #iterating over all items in array
  for i in range(size):
    #define starting smallest index as first element
    indexSmallest = i
    #check next elemement to see if it is smaller than the previous element
    for j in range(i + 1, size):
      # select the minimum element in every iteration
      if array[j] < array[indexSmallest]:
        #if next element is smaller, make that the new smallest element
        indexSmallest = j
  # swapping the elements to sort the array
  (array[i], array[indexSmallest]) = (array[indexSmallest], array[i])
  #switch 0 and 1 arrays at the end
  (array[0], array[1]) = (array[1], array[0])


#create empty array
ifill = 50
arr = []
#fill empty array
for i in range(0, 21):
  arr.append(ifill)
  ifill = ifill + 1

size = len(arr)
print('Before Selection Sort is:')
print(arr)
selectionSort(arr, size)
print('Array Afer Selection Sort is:')
print(arr)
