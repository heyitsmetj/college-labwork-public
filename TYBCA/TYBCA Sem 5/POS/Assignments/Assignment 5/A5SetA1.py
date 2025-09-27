from heapq import heappush, heappop

start = (2,8,3, 1,6,4, 7,0,5)     
goal  = (1,2,3, 8,0,4, 7,6,5) 

def h(state):
    return sum(1 for i in range(9) if state[i] != 0 and state[i] != goal[i])

def neighbors(state):
    """Generate next possible states by moving blank tile"""
    pos = state.index(0)         
    r, c = divmod(pos, 3)
    moves = []
    if r > 0: moves.append(-3)   
    if r < 2: moves.append(3)    
    if c > 0: moves.append(-1)   
    if c < 2: moves.append(1)    
    for m in moves:
        new = list(state)
        new[pos], new[pos+m] = new[pos+m], new[pos]
        yield tuple(new)


def a_star(start, goal):
    pq = []                          
    heappush(pq, (h(start), 0, start, [])) 
    visited = set()

    while pq:
        f, g, state, path = heappop(pq)

        if state == goal:          
            return path + [state]

        if state in visited:
            continue
        visited.add(state)

        for nxt in neighbors(state):
            if nxt not in visited:
                g2 = g + 1
                heappush(pq, (g2 + h(nxt), g2, nxt, path + [state]))

    return None

solution = a_star(start, goal)

def show(s):
    for i in range(0,9,3):
        print(*('_' if x==0 else x for x in s[i:i+3]))
    print()

print("\nSteps to reach goal:")
for step, state in enumerate(solution):
    print("Step", step)
    show(state)
print("Total moves:", len(solution)-1)
