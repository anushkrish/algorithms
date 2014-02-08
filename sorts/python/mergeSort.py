def mergeSort(a, start, end, b):
	if end-start==1:
		return
	
	middle = (end+start)/2
	mergeSort(a, start, middle, b)
	mergeSort(a, middle, end, b)

if __name__ == "__main__":
	