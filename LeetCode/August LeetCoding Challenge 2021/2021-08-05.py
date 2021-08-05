# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        result = []
        
        def dfs(node: TreeNode, stack: List[int]):
            if node != None:
                # 양쪽 자식이 없을 때 리턴
                if (node.left == None) and (node.right == None):
                    if sum(stack) + node.val == targetSum:
                        result.append(stack + [node.val,])
                    return
                if node.left != None:
                    dfs(node.left, stack + [node.val,])
                if node.right != None:
                    dfs(node.right, stack + [node.val,])
                
        dfs(root, [])
        
        return result
