# 1028. Recover a Tree From Preorder Traversal (Hard)
# Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-22
# Solved Status: Solved in 1.5 hour

from typing import *


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


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
    curr = root
    stack = [root]
    level = 1
    while traversal:
        dash_count, traversal = get_dash(traversal)
        num, traversal = get_num(traversal)
        node = TreeNode(num)
        if dash_count == level:
            curr.left = node
            curr = node
            stack.append(node)
            level += 1
        else:
            stack = stack[:dash_count]
            curr = stack[-1]
            curr.right = node
            curr = node
            stack.append(node)
            level = dash_count + 1
    return root


traversal = "1-2--3--4-5--6--7"
root = recover_from_preorder(traversal)
level_order(root)
