import heapq

def dijkstra(graph, costs, start):
  # Initialize distances and predecessors
  d = {v: float('inf') for v in graph}
  pi = {v: None for v in graph}
  
  d[start] = 0
  Q = [(0, start)]
  
  while Q:
    # Extract the vertex with the minimum distance
    current_distance, u = heapq.heappop(Q)
    
    if current_distance > d[u]:
      continue
    
    # Check all adjacent vertices of u
    for v in graph[u]:
      if d[u] + costs[(u, v)] < d[v]:
        d[v] = d[u] + costs[(u, v)]
        pi[v] = u
        heapq.heappush(Q, (d[v], v))
  
  return pi, d

# Example usage:
graph = {
  's': ['u', 'x'],
  'u': ['v'],
  'v': ['y'],
  'x': ['v', 'y'],
  'y': []
}

costs = {
  ('s', 'u'): 10,
  ('s', 'x'): 5,
  ('u', 'v'): 1,
  ('v', 'y'): 4,
  ('x', 'v'): 9,
  ('x', 'y'): 2,
}

start_vertex = 's'
predecessors, distances = dijkstra(graph, costs, start_vertex)

# Print the results
print("Vertex\tDistance from Source\tPredecessor")
for vertex in graph:
  print(f"{vertex}\t{distances[vertex]}\t\t{predecessors[vertex]}")
