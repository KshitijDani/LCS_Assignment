from itertools import permutations
 
def print_list(a):
	for i in a:
		print i,
	print


# Get all permutations of [1, 2, 3]
perm = permutations([2, 3, 4, 5, 6, 7 , 8, 9])
 
# Print the obtained permutations
for i in list(perm):
    print_list(i)
