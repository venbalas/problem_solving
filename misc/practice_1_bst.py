class TreeNode:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:

    def __init__(self, root_data):
        if root_data is None:
            self.root = None
        else:
            self.root = TreeNode(root_data)

    def insert(self, data):
        if self.root is None:
            self.root = TreeNode(data)
            return True

        temp_node = self.root
        temp_root = self.root

        while(temp_node is not None):
            if temp_node.data > data:
                if temp_node.left is None:
                    temp_node.left = TreeNode(data)
                    return True
                else:
                    temp_node = temp_node.left

            else:
                if temp_node.right is None:
                    temp_node.right = TreeNode(data)
                    return True
                else:
                    temp_node = temp_node.right
        if temp_node == None:
            self.root = TreeNode(data)
            return True

    def lowest_common_ancestor(self, node1, node2):

        temp_node = self.root

        while(temp_node is not None):
            if (temp_node.data >= node1 and temp_node.data < node2) or (temp_node.data < node1 and temp_node.data >= node2):
                return temp_node
            elif temp_node.data >= node1 and  temp_node.data >= node2:
                temp_node = temp_node.left
            else:
                temp_node = temp_node.right

        return None

    def dist(self, parent, node_data):

        temp_node = parent
        counter=0

        while temp_node!= None:
            if temp_node.data > node_data:
                temp_node = temp_node.left
                counter += 1
            elif temp_node.data < node_data:
                temp_node = temp_node.right
                counter += 1
            else:
                break

        return counter

    def find_dist(self, node1_data, node2_data):
        lca = self.lowest_common_ancestor(node1_data,node2_data)
        return self.dist(lca,node1_data) + self.dist(lca,node2_data)

def main():
    array = [int(x) for x in input().split(" ")]
    n = len(array)
    node1 = int(input())
    node2 = int(input())
    bin_tree = BinaryTree(None)

    for item in array:
        bin_tree.insert(item)

    print(bin_tree.find_dist(node1, node2))

main()
