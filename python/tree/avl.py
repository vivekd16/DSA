class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 0

class AVLTree:
    def __init__(self):
        self.root = None

    def get_height(self, node):
        return node.height if node else -1

    def max(self, a, b):
        return a if a > b else b

    def rotate_right(self, root):
        node = root
        ptr = node.left
        ptr2 = ptr.right

        ptr.right = node
        node.left = ptr2

        node.height = self.max(self.get_height(node.left), self.get_height(node.right)) + 1
        ptr.height = self.max(self.get_height(ptr.left), self.get_height(ptr.right)) + 1

        return ptr

    def rotate_left(self, root):
        node = root
        ptr = node.right
        ptr2 = ptr.left

        ptr.left = node
        node.right = ptr2

        node.height = self.max(self.get_height(node.left), self.get_height(node.right)) + 1
        ptr.height = self.max(self.get_height(ptr.left), self.get_height(ptr.right)) + 1

        return ptr

    def get_balance(self, node):
        return self.get_height(node.left) - self.get_height(node.right) if node else 0

    def insert(self, root, key):
        if not root:
            return Node(key)

        if key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        else:
            return root

        root.height = self.max(self.get_height(root.left), self.get_height(root.right)) + 1
        balance = self.get_balance(root)

        # Left-Left case
        if balance > 1 and key < root.left.key:
            return self.rotate_right(root)

        # Right-Right case
        if balance < -1 and key > root.right.key:
            return self.rotate_left(root)

        # Left-Right case
        if balance > 1 and key > root.left.key:
            root.left = self.rotate_left(root.left)
            return self.rotate_right(root)

        # Right-Left case
        if balance < -1 and key < root.right.key:
            root.right = self.rotate_right(root.right)
            return self.rotate_left(root)

        return root

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.key, end=" ")
            self.inorder(root.right)

    def insert_key(self, key):
        self.root = self.insert(self.root, key)

# Usage
if __name__ == "__main__":
    tree = AVLTree()
    keys = [9, 15, 20, 8, 7, 13, 10]

    for key in keys:
        tree.insert_key(key)

    print("Inorder traversal:", end=" ")
    tree.inorder(tree.root)
