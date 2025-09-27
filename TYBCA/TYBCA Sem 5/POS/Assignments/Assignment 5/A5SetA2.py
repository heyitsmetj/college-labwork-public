from heapq import heappush, heappop

# --- Graph ---
graph = {
    'A': {'B':6, 'F':3},
    'B': {'A':6, 'C':3, 'D':2},
    'C': {'B':3, 'D':1, 'E':5},
    'D': {'B':2, 'C':1, 'E':8},
    'E': {'C':5, 'D':8, 'I':5, 'J':5},
    'F': {'A':3, 'G':1, 'H':7},
    'G': {'F':1, 'I':3},
    'H': {'F':7, 'I':2},
    'I': {'G':3, 'H':2, 'E':5, 'J':3},
    'J': {'E':5, 'I':3}
}

heuristic = {
    'A':10, 'B':8, 'C':5, 'D':7, 'E':3, 'F':6,
    'G':5, 'H':3, 'I':1, 'J':5
}

# --- A* Algorithm ---
def a_star(start, goal):
    pq = []
    heappush(pq, (heuristic[start], 0, start, [start]))  # (f, g, node, path)
    visited = set()

    while pq:
        f, g, node, path = heappop(pq)
        if node == goal:
            return path, g
        if node in visited:
            continue
        visited.add(node)

        for neigh, cost in graph[node].items():
            if neigh not in visited:
                g2 = g + cost
                f2 = g2 + heuristic[neigh]
                heappush(pq, (f2, g2, neigh, path + [neigh]))

    return None, float('inf')

# Run
path, cost = a_star('A', 'J')
print("Best path:", " -> ".join(path))
print("Total cost:", cost)
