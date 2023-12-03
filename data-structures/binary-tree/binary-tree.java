

class Main {
  // defining the node as a static class
  static class Node{ int data;
                    Node left,right = null;
                    Node(int data) {
                      this.data = data;
                      this.left=null;
                      this.right=null;
                    }
                   }
  //preorder traversal is the standard binary tree presentation why know
  public static void preorder(Node root){
    if (root == null) {
      return;
    }
    //this is a recursive process
    System.out.print(root.data + " ");
    preorder(root.left);
    preorder(root.right);
  }

  //the swap is a helper function to swap the left and right nodes
  public static void swap(Node root){
    //if root is null then return
    if (root == null) {
      return;
    }
    Node temp = root.left;
    root.left = root.right;
    root.right = temp;
  }

  //the postorder is a recursive function that traverses the tree in postorder
  public static void postorder(Node root){
    //if root is null, return
    if (root == null) {
      return;
    }
    swap(root);
    //this part is recursive
    postorder(root.left);
    postorder(root.right);
  }

  //this is a function to print out the inverted tree
  public static void printInvertedBinaryTree(Node root){
    //print out parent
    System.out.println("       ("+root.data+")");
    System.out.println("      /   \\");

    //print out children
    System.out.print("    ("+root.left.data+")");
    System.out.println("   ("+root.right.data+")");

    System.out.println("    / \\    / \\");

    //print out children of children
    System.out.print(" ("+root.left.left.data+")");
    System.out.print(" ("+root.left.right.data+")");
    System.out.print(" ("+root.right.left.data+")");
    System.out.println(" ("+root.right.right.data+")");
  }

  //this is a function to print out the binary tree
  public static void printBinaryTree(Node root){
    //print out parent
    System.out.println("       ("+root.data+")");
    System.out.println("      /   \\");

    //print out children
    System.out.print("   ("+root.right.data+")");
    System.out.println("    ("+root.left.data+")");
    System.out.println("    / \\    / \\");

    //print out children of children
    System.out.print(" ("+root.right.right.data+")");
    System.out.print(" ("+root.right.left.data+")");
    System.out.print(" ("+root.left.right.data+")");
    System.out.println(" ("+root.left.left.data+")");
    

  }

  //this is a function to print out the normal tree
  public static void printUpsideDownBinaryTree(Node root){
    //print out children of children
    System.out.print(" ("+root.right.right.data+")");
    System.out.print(" ("+root.right.left.data+")");
    System.out.print(" ("+root.left.right.data+")");
    System.out.println(" ("+root.left.left.data+")");
    System.out.println("    \\ /    \\ /");
    
    //print out children
    System.out.print("   ("+root.right.data+")");
    System.out.println("    ("+root.left.data+")");
    System.out.println("      \\   /");
    
    //print out parent
    System.out.println("       ("+root.data+")");

  }
  //start main
  public static void main(String args[]){
    //create a instance of the Node class and populate it
    Node root = new Node(4);
    root.left = new Node(2);
    root.right = new Node(7);
    root.left.left = new Node(1);
    root.left.right = new Node(3);
    root.right.left = new Node(6);
    root.right.right = new Node(9);

    System.out.println("The Preorder Traversal Is:");
    preorder(root);
    System.out.println();
    System.out.println();

    System.out.println("The Postorder Traversal Is:");
    postorder(root);
    preorder(root);
    System.out.println();
    System.out.println();

    System.out.println("Display Binary Tree:");

    printBinaryTree(root);

    System.out.println("\nDisplay Inverted Binary Tree:");

    printInvertedBinaryTree(root);

    System.out.println("\nDisplay Upside Down Binary Tree:");

    printUpsideDownBinaryTree(root);

    
  }
}




