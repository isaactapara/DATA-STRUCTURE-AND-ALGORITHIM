// BSE-05-0065-2024 ISAACK TAPARA

import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    public Node(int value) {
        this.data = value;
        left = right = null;
    }
}

class BinaryTree {
    private Node root;

    public void insert(int value) {
        root = insertRecursive(root, value);
    }

    private Node insertRecursive(Node node, int value) {
        if (node == null)
            return new Node(value);

        if (value < node.data) {
            node.left = insertRecursive(node.left, value);
        } else if (value > node.data) {
            node.right = insertRecursive(node.right, value);
        } // ignore duplicates
        return node;
    }

    public void inOrderTraversal() {
        System.out.print("In-order: ");
        inOrderRecursive(root);
        System.out.println();
    }

    private void inOrderRecursive(Node node) {
        if (node != null) {
            inOrderRecursive(node.left);
            System.out.print(node.data + " ");
            inOrderRecursive(node.right);
        }
    }

    public void preOrderTraversal() {
        System.out.print("Pre-order: ");
        preOrderRecursive(root);
        System.out.println();
    }

    private void preOrderRecursive(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrderRecursive(node.left);
            preOrderRecursive(node.right);
        }
    }

    public void postOrderTraversal() {
        System.out.print("Post-order: ");
        postOrderRecursive(root);
        System.out.println();
    }

    private void postOrderRecursive(Node node) {
        if (node != null) {
            postOrderRecursive(node.left);
            postOrderRecursive(node.right);
            System.out.print(node.data + " ");
        }
    }

    public boolean search(int key) {
        return searchRecursive(root, key);
    }

    private boolean searchRecursive(Node node, int key) {
        if (node == null)
            return false;
        if (node.data == key)
            return true;
        if (key < node.data)
            return searchRecursive(node.left, key);
        return searchRecursive(node.right, key);
    }

    public int height() {
        return heightRecursive(root);
    }

    private int heightRecursive(Node node) {
        if (node == null)
            return 0;
        return 1 + Math.max(heightRecursive(node.left), heightRecursive(node.right));
    }
}

public class TreeDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinaryTree tree = new BinaryTree();

        System.out.println("Enter numbers to insert into the Binary Tree (type -1 to finish):");
        while (true) {
            System.out.print("Enter value: ");
            int value = scanner.nextInt();
            if (value == -1)
                break;
            tree.insert(value);
        }

        System.out.println("\nTree Traversals:");
        tree.inOrderTraversal();
        tree.preOrderTraversal();
        tree.postOrderTraversal();

        System.out.println("\nHeight of the tree: " + tree.height());

        System.out.print("Enter a number to search: ");
        int searchValue = scanner.nextInt();
        boolean found = tree.search(searchValue);
        System.out.println("Search result: " + (found ? "Found" : "Not Found"));

        scanner.close();
    }
}
