# 1261. Find Elements in a Contaminated Binary Tree (Medium)
# Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21

from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.visited = set()
        self._dfs(root, 0)

    def _dfs(self, node, value):
        if node is None:
            return
        self.visited.add(value)
        self._dfs(node.left, 2 * value + 1)
        self._dfs(node.right, 2 * value + 2)

    def find(self, target: int) -> bool:
        return target in self.visited


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
