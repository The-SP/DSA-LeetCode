# 802. Find Eventual Safe States
# Medium
# Link: https://leetcode.com/problems/find-eventual-safe-states/description/

from typing import *


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        terminal_nodes = set()
        for i in range(len(graph)):
            if len(graph[i]) == 0:
                terminal_nodes.add(i)

        while 1:
            updated_terminal_nodes = False
            for i in range(len(graph)):
                if i in terminal_nodes:
                    continue
                is_safe = True
                for node in graph[i]:
                    if node not in terminal_nodes:
                        is_safe = False
                if is_safe:
                    terminal_nodes.add(i)
                    updated_terminal_nodes = True

            if not updated_terminal_nodes:
                break
        return sorted(list(terminal_nodes))
