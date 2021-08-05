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

# 런타임 시간은 빠르나 메모리 사용량이 높음
#################################
# 런타임 시간은 조금 느리나 메모리 사용량이 낮음

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
                stack.append(node.val)
                if (node.left == None) and (node.right == None):
                    if sum(stack) == targetSum:
                        result.append(stack[:]) # 새 객체로 append 안하면 reulst에 append 해도 그 객체로 인식돼서 pop할 때 같이 없어짐
                    return
                if node.left != None:
                    dfs(node.left, stack)
                    stack.pop()
                if node.right != None:
                    dfs(node.right, stack)
                    stack.pop()
                
        dfs(root, [])
        
        return result
