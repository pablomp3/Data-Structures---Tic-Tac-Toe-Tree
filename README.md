# Data-Structures---Tic-Tac-Toe-Tree
https://acm.cs.nthu.edu.tw/problem/12227/

## Description
You will be first be given a list of nodes to insert into a tree. The resulting trees will not be balanced, complete nor full. After building the tree, you should traverse it and find wether there is a path with a 'winning' Tic-tac-toe game status. There will be either 1 or 0 'Winning' paths in a tree.

If there is a 'Winning' path in a tree, you will have to output the resulting Tic-Tac-Toe grid layout.

If there is not a 'Winning' path in a tree, you will have to output the contents of the tree nodes by traversing the tree in post order traversal.

**Example 1: tree with a 'winning' path** (see Example 1 Tree above)

![](https://github.com/pablomp3/Data-Structures---Tic-Tac-Toe-Tree/blob/master/example-1_tree.png)

**Example 2: Tree without a 'winning' path** (see Example Tree 2 above)

![](https://github.com/pablomp3/Data-Structures---Tic-Tac-Toe-Tree/blob/master/example-2_tree.png)

## Input
* An integer n followed by a new line, indicating the number of nodes to insert in the tree
* N lines indicating the node contents. Each line looks like below:
  * Node Id, Parent Id, Position x, position Y, Mark;  separated by whitespaces and ending in new lines
  
**Notes:**

Node Id is an integer ranging from 0 to 100.
Parent Id is an integer ranging from-1 to 99, where -1 is the root.
Position x and position y are integers ranging from 0 to 2, indicating the tic-tac-toe grid position.
Mark is a character, either 'O' or 'X' (uppercase)
The tic-tac-toe gris positions are illustrated below:

| Col 1 | Col 2 | Col 3 |
|-------|-------|-------|
| (0,0) | (1,0) | (2,0) |
| (0,1) | (1,1) | (2,1) |
| (0,2) | (1,2) | (2,2) |

**Example 1: Input for tree with a 'winning path'** (see Sample Input 1 above)

![](https://github.com/pablomp3/Data-Structures---Tic-Tac-Toe-Tree/blob/master/sample-input-1.png)

**Example 2: Input for tree without a 'winning path'** (see Sample Input 2 above)

![](https://github.com/pablomp3/Data-Structures---Tic-Tac-Toe-Tree/blob/master/sample-input-2.png)


## Output

* If there is a 'winning’ path in the tree, ouput:
  * Win’, followed by new line
  * The tic-tac-toe grid with the moves on the winning path. Empty squares will be represented with ‘_’ .Positions are separated with whitespaces. There is an endline at the end of each line.
* Else, output:
  * ‘Tie’, followed by new line
  * For each node, traversed in postorder traversal, output:
    * Position x, position y and Mark{O, X}, separated by whitespaces, followed by new line
    
**Example 1: Output for tree with a 'winning' path** (see Sample Output 1 above)

![](https://github.com/pablomp3/Data-Structures---Tic-Tac-Toe-Tree/blob/master/sample-output-1.png)

**Example 2: Output for tree without a 'winning path** (see Sample Output 2 above)

![](https://github.com/pablomp3/Data-Structures---Tic-Tac-Toe-Tree/blob/master/sample-output-2.png)


## Sample Input  

    12
    0 -1 1 1 O
    1 0 0 0 X
    2 0 2 2 X
    3 1 2 0 O
    4 1 0 2 O
    5 2 2 0 O
    6 2 0 2 O
    7 3 0 2 X
    8 3 0 1 X
    9 4 2 0 X
    10 4 1 0 X
    11 8 0 2 O

## Sample Output

    Win
    X _ O
    X O _
    O _ _
