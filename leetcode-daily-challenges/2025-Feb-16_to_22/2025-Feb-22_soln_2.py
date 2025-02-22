class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return self.val


def level_order(root):
    queue = [root]
    order = []
    while queue:
        node = queue.pop(0)
        order.append(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    print(order)


def get_num(traversal):
    num = ""
    i, n = 0, len(traversal)
    while i < n and traversal[i] != "-":
        num += traversal[i]
        i += 1
    return int(num), traversal[i:]


def get_dash(traversal):
    i, n = 0, len(traversal)
    while i < n and traversal[i] == "-":
        i += 1
    return i, traversal[i:]


def recover_from_preorder(traversal):
    num, traversal = get_num(traversal)
    root = TreeNode(num)
    stack = [root]
    level = 1

    while traversal:
        dash_count, traversal = get_dash(traversal)
        num, traversal = get_num(traversal)
        node = TreeNode(num)

        while level > dash_count:
            stack.pop()
            level -= 1

        if not stack[-1].left:
            stack[-1].left = node
        else:
            stack[-1].right = node
        stack.append(node)
        level += 1

    return root


traversal = "1-2--3--4-5--6--7"
root = recover_from_preorder(traversal)
level_order(root)
