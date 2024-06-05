import heapq

def prim(graph, start_vertex):
    mst = []
    visited = set([start_vertex])
    edges = [
        (cost, start_vertex, to)
        for to, cost in graph[start_vertex].items()
    ]
    heapq.heapify(edges)

    while edges:
        cost, frm, to = heapq.heappop(edges)
        if to not in visited:
            visited.add(to)
            mst.append((frm, to, cost))

            for to_next, cost in graph[to].items():
                if to_next not in visited:
                    heapq.heappush(edges, (cost, to, to_next))
    
    return mst

# Example usage
graph = {
    'A': {'B': 1, 'C': 3},
    'B': {'A': 1, 'C': 4, 'D': 2},
    'C': {'A': 3, 'B': 4, 'D': 5},
    'D': {'B': 2, 'C': 5, 'E': 1, 'F': 6},
    'E': {'D': 1, 'F': 5},
    'F': {'D': 6, 'E': 5}
}

mst = prim(graph, 'A')
print(mst)
