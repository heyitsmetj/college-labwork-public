from heapq import heappush, heappop

# --------- Input States ----------
start = (2,8,3, 1,6,4, 7,0,5)     # initial state (0 = blank)
goal  = (1,2,3, 8,0,4, 7,6,5)     # goal state

# --------- Helper Functions ----------
def h(state):  # heuristic = number of misplaced tiles
    return sum(1 for i in range(9) if state[i] != 0 and state[i] != goal[i])

def neighbors(state):
    """Generate next possible states by moving blank tile"""
    pos = state.index(0)         # blank position
    r, c = divmod(pos, 3)
    moves = []
    if r > 0: moves.append(-3)   # up
    if r < 2: moves.append(3)    # down
    if c > 0: moves.append(-1)   # left
    if c < 2: moves.append(1)    # right
    for m in moves:
        new = list(state)
        new[pos], new[pos+m] = new[pos+m], new[pos]
        yield tuple(new)

# --------- A* Search ----------
def a_star(start, goal):
    pq = []                           # priority queue
    heappush(pq, (h(start), 0, start, []))  # (f, g, state, path)
    visited = set()

    while pq:
        f, g, state, path = heappop(pq)

        if state == goal:            # Goal found
            return path + [state]

        if state in visited:
            continue
        visited.add(state)

        for nxt in neighbors(state):
            if nxt not in visited:
                g2 = g + 1
                heappush(pq, (g2 + h(nxt), g2, nxt, path + [state]))

    return None

# --------- Run ----------
solution = a_star(start, goal)

# --------- Show Result ----------
def show(s):
    for i in range(0,9,3):
        print(*('_' if x==0 else x for x in s[i:i+3]))
    print()

print("\nSteps to reach goal:")
for step, state in enumerate(solution):
    print("Step", step)
    show(state)
print("Total moves:", len(solution)-1)
