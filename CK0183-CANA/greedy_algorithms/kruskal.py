class DisjointSet:
    def __init__(self, vertices):
        self.parent = {}
        self.rank = {}
        for v in vertices:
            self.parent[v] = v
            self.rank[v] = 0

    def make_set(self, v):
        self.parent[v] = v
        self.rank[v] = 0

    def find_set(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find_set(self.parent[v])
        return self.parent[v]

    def union(self, u, v):
        root_u = self.find_set(u)
        root_v = self.find_set(v)

        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            else:
                self.parent[root_u] = root_v
                if self.rank[root_u] == self.rank[root_v]:
                    self.rank[root_v] += 1


def kruskal(graph):
    A = set()
    edges = list(graph['edges'])
    edges.sort(key=lambda e: e[2])  # Sort edges by weight

    disjoint_set = DisjointSet(graph['vertices'])

    for u, v, weight in edges:
        if disjoint_set.find_set(u) != disjoint_set.find_set(v):
            A.add((u, v, weight))
            disjoint_set.union(u, v)

    return A


# Example usage
graph = {
    'vertices': ['A', 'B', 'C', 'D', 'E', 'F'],
    'edges': [
        ('A', 'B', 1),
        ('B', 'C', 4),
        ('A', 'C', 3),
        ('C', 'D', 2),
        ('D', 'E', 1),
        ('E', 'F', 5),
        ('D', 'F', 6),
    ]
}

mst = kruskal(graph)
print(mst)
