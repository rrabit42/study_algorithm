# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    goodCnt = 0
        
    def goodNodes(self, root: TreeNode) -> int:
        # 아악 문제 잘못이해했네
        # root에서 나까지 가는 길에 나보다 큰 애가 없을 때임!!!!!!
        # 그니까 left / right 완전히 분리해야함 -> max 값이 길에 따라 다르니까

        def search(node, nowMax):
            if node == None:
                return
            nowMax = max(nowMax, node.val)
            if node.val >= nowMax:
                self.goodCnt += 1
            search(node.left, nowMax)
            search(node.right, nowMax)
            
        search(root, root.val)
        
        return self.goodCnt
        
