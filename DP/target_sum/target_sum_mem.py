def find_target_sum_ways(arr, T):
    total = sum(arr)

    # If the target can't be generated using the given numbers
    if total < abs(T):
        return 0
    
    # Initialize a lookup table
    dp = [[-1 for _ in range(2*total+1)] for _ in range(len(arr))]
    
    return find_target_sum_ways_rec(arr, 0, T, dp)

def find_target_sum_ways_rec(arr, i, T, dp):
    # If all integers are processed
    if i == len(arr):
        # If target is reached
        if T == 0:
            return 1
        # If target is not reached
        return 0

    #If we have solved it earlier, then return the result from memory
    if dp[i][T] != -1:
        return dp[i][T]
    
    # Calculate both sub-problems and save the results in the memory
    dp[i][T] = find_target_sum_ways_rec(arr, i + 1, T + arr[i], dp) + \
               find_target_sum_ways_rec(arr, i + 1, T - arr[i], dp)
    
    return dp[i][T]


# Driver code
def main():
    arrs = [[1], [3, 3, 3, 3], [2, 3, 4, 6, 8, 12], [2, 2, 2, 4, 4, 4, 8, 8, 8]]
    targets= [1, 6, 15, 18]
    
    # Let's uncomment this and check the effect of dynamic programming using memoization
    
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
