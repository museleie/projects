
#import graphviz package which is used to plot graphs in python
import graphviz


#define the Node class
class Node:
  #adding the initialization
  def __init__(self, key=0, left=None, right=None):
    #self is similar to the root
    self.key = key
    #this is defining the left and right nodes,
    #with the insertion of Nones for each as defined in the parameters
    self.left = left
    self.right = right

  #adding the print tree function
  def PrintTree(self):
    if self.left:
      self.left.PrintTree()
    print(self.key, end=' ')
    if self.right:
      self.right.PrintTree()


#adding a solution class
class Solution:
  #adding the inverting tree function
  def invertTree(self, root):
    #if there is nothing, stop the inversion
    if root == None:
      return
    #this is the node swap available for inverting
    root.left, root.right = self.invertTree(root.right), self.invertTree(
        root.left)
    return root


#this is the normal version of the binary tree
#preorder traversal: nodes are added before recursion
def preorder_traversal(root, dot):
  if root:
    #if a root is present, it will denote it as a node
    dot.node(str(root.key), label=str(root.key))
    #if left child is present, it will denote the connection as an edge
    if root.left:
      dot.edge(str(root.key), str(root.left.key), style='solid')
      #if right child is present, it will denote the connection as an edge
    if root.right:
      dot.edge(str(root.key), str(root.right.key), style='solid')
    #recursion happens here, there is a call to itself
    preorder_traversal(root.left, dot)
    preorder_traversal(root.right, dot)


#this is the 'upside down version' of the binary tree
#postorder traversal: nodes are added after recursion
def postorder_traversal(root, dot):
  if root:
    #recursion happens here, there is a call to itself
    #this time, the postorder recursion method is done first before adding the node
    postorder_traversal(root.left, dot)
    postorder_traversal(root.right, dot)
    #if a root is present, it will denote it as a node
    dot.node(str(root.key), label=str(root.key))
    #if left child is present, it will denote the connection as an edge
    if root.left:
      dot.edge(str(root.left.key), str(root.key), style='solid')
    #if right child is present, it will denote the connection as an edge
    if root.right:
      dot.edge(str(root.right.key), str(root.key), style='solid')


#function that is constructing the tree
def construct_tree():
  #define the root with 4
  root = Node(4)
  #create the right and left child
  root.left = Node(2)
  root.right = Node(7)
  #create the grandchildren
  #right and left child of the left child
  root.left.left = Node(1)
  root.left.right = Node(3)
  #right and left child of the right child
  root.right.left = Node(6)
  root.right.right = Node(9)
  #return the node
  return root


def print_preorder_tree(root):
  dot_preorder = graphviz.Digraph(comment='Preorder Traversal')
  preorder_traversal(root, dot_preorder)
  dot_preorder.render('preorder_traversal', view=True, format='png')


def print_postorder_tree(root):
  dot_postorder = graphviz.Digraph(comment='Postorder Traversal')
  postorder_traversal(root, dot_postorder)
  dot_postorder.render('postorder_traversal', view=True, format='png')


root = construct_tree()

#print out the normal binary tree information
print("\nThe Normal Binary Tree is:")
root.PrintTree()
print_preorder_tree(root)
print('\n')

#print out the inverted binary tree
print('\nThe Inverse Binary Tree is:')
#this applies the inversion function from the solutions class
Solution().invertTree(root=root)
root.PrintTree()
print_preorder_tree(root)
print(
    "\nPlease visit files to see preorder_traversal.png to see graphic image of the inverse"
)
print('\n')

#print out the upside down binary tree
print("The Upside Down Binary Tree is:")
#please view postorder_traversal.png on the files in replit
#invert the tree back to the original state
Solution().invertTree(root=root)
#do the post order traversal and print
print_postorder_tree(root)
print(
    "\n Please visit files to see postorder_traversal.png to see graphic image of the upside down"
)
