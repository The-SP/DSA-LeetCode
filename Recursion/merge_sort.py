def merge(arr, left, mid, right):
    temp = []
    i, j = left, mid+1
    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1
    while i <= mid:
        temp.append(arr[i])
        i += 1
    while j <= right:
        temp.append(arr[j])
        j += 1
    
    for i in range(len(temp)):
        arr[left+i] = temp[i]        

def merge_sort(arr, left, right):
    if left < right:
        mid = left + int((right-left)/2)
        merge_sort(arr, left, mid)
        merge_sort(arr, mid+1, right)
        merge(arr, left, mid, right)
        
        
arr = [5, 15, 10, 3, 13, 17, 20]
merge_sort(arr, 0, len(arr)-1)
print(arr)