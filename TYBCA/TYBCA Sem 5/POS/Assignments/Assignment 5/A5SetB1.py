# AO* Algorithm for given graph

graph = {
    'A': [[('B',4)], [('C',5)], [('D',5)]],   # OR: can go to B or C or D
    'B': [[('C',2)]],                         # OR: B->C
    'C': [[('E',2), ('F',2)]],                # AND: must solve E and F
    'D': [[('E',2), ('F',4)]],                # AND: must solve E and F
    'E': [[('F',3)]],                         # OR: E->F
    'F': []                                   # Goal
}

h = {'A':8, 'B':1, 'C':2, 'D':8, 'E':3, 'F':0}

def ao_star(node):
    """Returns minimal cost for node using AO*"""
    if not graph[node]:        # goal node
        return h[node]
    min_cost = float('inf')
    for branch in graph[node]: # each branch can be OR (one list)
        cost = 0
        for (child, c) in branch:
            cost += c + ao_star(child)
        min_cost = min(min_cost, cost)
    return min_cost

print("Minimum cost from A:", ao_star('A'))
