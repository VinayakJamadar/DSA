class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

// Tree
//    1
//   / \
//  2   3
//   \
//    5

class BinaryTree {
    // Root of Binary Tree
    Node root;

    // Constructors
    BinaryTree(int key) {
        root = new Node(key);
    }

    BinaryTree() {
        root = null;
    }

    public void inOrderTraversal(Node focusNode) {
        if (focusNode != null) {
            inOrderTraversal(focusNode.left);
            System.out.print(focusNode.key + " ");
            inOrderTraversal(focusNode.right);
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.right = new Node(5);

        tree.inOrderTraversal(tree.root);
    }
}