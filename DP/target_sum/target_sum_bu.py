def find_target_sum_ways(arr, T):
    total = sum(arr)

    # If the target can't be generated using the given numbers
    if total < abs(T):
        return 0    

    # Initialize a lookup table
    dp = [[0 for _ in range(2*total+1)] for _ in range(len(arr))]
    dp[0][total + arr[0]] = 1
    dp[0][total - arr[0]] += 1

    # For every integer
    for i in range(1, len(arr)):
        # For every possible target sum
        for t in range(-total, total+1):
            # If at least one expression (during previous iterations) evaluated to this target sum
            if dp[i - 1][total + t] > 0:
                dp[i][total + t + arr[i]] += dp[i - 1][total + t]
                dp[i][total + t - arr[i]] += dp[i - 1][total + t]
    
    return dp[len(arr)-1][T+total]


# Driver code
def main():
    arrs = [[1], [3, 3, 3, 3], [2, 3, 4, 6, 8, 12], [2, 2, 2, 4, 4, 4, 8, 8, 8]]
    targets= [1, 6, 15, 18]
    
    # Let's uncomment this to see the benefit of using dynamic programming with tabulation
    
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
