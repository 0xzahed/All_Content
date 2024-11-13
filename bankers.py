def is_safe(available, max_need, allocation):
    P = len(max_need)
    R = len(available)
    
    work = available[:]
    finished = [False] * P
    safe_sequence = []
    
    process_count = 0
    while process_count < P:
        found = False

        for p in range(P):
            if not finished[p]:
                can_proceed = True
                for r in range(R):
                    if max_need[p][r] - allocation[p][r] > work[r]:
                        can_proceed = False
                        break

                if can_proceed:
                    for r in range(R):
                        work[r] += allocation[p][r]
                    
                    safe_sequence.append(p)
                    finished[p] = True
                    found = True
                    process_count += 1

        if not found:
            print("System is not in a safe state.")
            return False

    print("System is in a safe state.")
    print("Safe sequence:", safe_sequence)
    return True

available = [3, 3, 2]
max_need = [
    [7, 5, 3],
    [3, 2, 2],
    [9, 0, 2],
    [2, 2, 2],
    [4, 3, 3]
]
allocation = [
    [0, 1, 0],
    [2, 0, 0],
    [3, 0, 2],
    [2, 1, 1],
    [0, 0, 2]
]

is_safe(available, max_need, allocation)
