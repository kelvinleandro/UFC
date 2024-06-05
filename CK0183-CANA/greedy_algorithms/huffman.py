import heapq

class Node:
  def __init__(self, freq, symbol, left=None, right=None):
    # Initialize the node with frequency and symbol
    self.freq = freq
    self.symbol = symbol
    self.left = left
    self.right = right

  def __lt__(self, other):
    # Define less-than for priority queue to compare nodes by frequency
    return self.freq < other.freq

def build_min_heap(freq):
  # Create a priority queue (min-heap) using frequencies
  heap = []
  for symbol, frequency in freq.items():
    node = Node(frequency, symbol)
    heapq.heappush(heap, node)
  return heap

def extract_min(heap):
  # Extract the node with the minimum frequency
  return heapq.heappop(heap)

def insert_heap(heap, node):
  # Insert a new node into the heap
  heapq.heappush(heap, node)

def huffman(freq):
  heap = build_min_heap(freq)
  while len(heap) > 1:
    x = extract_min(heap)
    y = extract_min(heap)
    z = Node(x.freq + y.freq, None, x, y)
    insert_heap(heap, z)
  return extract_min(heap)

def generate_codes(node, prefix="", code={}):
  # Recursively generate Huffman codes
  if node:
    if node.symbol is not None:
      code[node.symbol] = prefix
    generate_codes(node.left, prefix + "0", code)
    generate_codes(node.right, prefix + "1", code)
  return code

# Example input frequency dictionary
freq = {
  'a': 45,
  'b': 13,
  'c': 12,
  'd': 16,
  'e': 9,
  'f': 5
}

# Build the Huffman tree
huffman_tree = huffman(freq)

# Generate Huffman codes
huffman_codes = generate_codes(huffman_tree)

# Print the results
print("Symbol\tFrequency\tHuffman Code")
for symbol in freq:
  print(f"{symbol}\t{freq[symbol]}\t\t{huffman_codes[symbol]}")
