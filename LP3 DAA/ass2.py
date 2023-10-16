import heapq
from collections import defaultdict

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    
    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(freq_table):
    heap = []
    for char, freq in freq_table.items():
        heapq.heappush(heap, HuffmanNode(char, freq))
    
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged_node = HuffmanNode(None, left.freq + right.freq)
        merged_node.left = left
        merged_node.right = right
        heapq.heappush(heap, merged_node)
    
    return heap[0]

def build_encoding_table(root, code='', encoding_table=None):
    if encoding_table is None:
        encoding_table = {}
    
    if root.char is not None:
        encoding_table[root.char] = code
    if root.left:
        build_encoding_table(root.left, code + '0', encoding_table)
    if root.right:
        build_encoding_table(root.right, code + '1', encoding_table)
    
    return encoding_table

def huffman_encoding(text):
    freq_table = defaultdict(int)
    for char in text:
        freq_table[char] += 1
    
    huffman_tree = build_huffman_tree(freq_table)
    encoding_table = build_encoding_table(huffman_tree)
    
    encoded_text = ''.join(encoding_table[char] for char in text)
    
    return encoded_text, huffman_tree

def huffman_decoding(encoded_text, root):
    decoded_text = ''
    current_node = root
    
    for bit in encoded_text:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right
        
        if current_node.char is not None:
            decoded_text += current_node.char
            current_node = root
    
    return decoded_text

# Get input from the user
input_text = input("Enter the text to encode: ")

# Huffman encoding
encoded_text, huffman_tree = huffman_encoding(input_text)
print("Encoded text:", encoded_text)

# Huffman decoding
decoded_text = huffman_decoding(encoded_text, huffman_tree)
print("Decoded text:", decoded_text)
