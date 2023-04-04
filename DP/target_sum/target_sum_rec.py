def find_target_sum_ways(arr, T):
    return find_target_sum_ways_rec(arr, 0, T)

def find_target_sum_ways_rec(arr, i, T):
    # If all integers are processed
    if i == len(arr):
        # If target is reached
        if T == 0:
            return 1
        # If target is not reached
        return 0
 
    # Return total count of the following cases:
    #       1. Add current element to the target
    #       2. Subtract current element from the target
    return (find_target_sum_ways_rec(arr, i + 1, T + arr[i]) +
            find_target_sum_ways_rec(arr, i + 1, T - arr[i]))


# Driver code
def main():
    arrs = [[1], [3, 3, 3, 3], [2, 3, 4, 6, 8, 12], [2, 2, 2, 4, 4, 4, 8, 8, 8]]
    targets= [1, 6, 15, 18]
    
    # You can uncomment the lines below and check how this recursive solution causes a time-out
    
    # arrs.append([2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3,
    #              2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3])
    # targets.append(42)
    
    for i in range(len(arrs)):
        print(i + 1, ".\t Input array: ", arrs[i], sep="")
        print("\t Target: ", targets[i], sep="")
        print("\t Number of ways in which we can find the target sum: ", find_target_sum_ways(arrs[i], targets[i]), sep="")
        print("-" * 100)
    

if __name__ == '__main__':
    main()
