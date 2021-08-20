# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    result = 0
    
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        # subsum * (totalsum - subsum) => 방정식: subsum = totalsum/2 에 가까울 수록 큼
        
        # tree val 합계 구하기
        def findSum(node, sum):
            if not node:
                return 0
            node.val = node.val + findSum(node.left, sum) + findSum(node.right, sum)
            return node.val
            
        findSum(root, 0)
        
        # 왼쪽 끊을 때, 오른쪽 끊을 때 -> 그럼 나머지애가 새로운 root가 됨!!!!!!
        # 손절 당한 애의 subsum 구하자
        self.result = 0
        def find(node):
            if not node:
                return
            
            # 어차피 none 이어도 findSum에서 알아서 처리해줌
            # 아 같은 노드인데도 계산을 또 해야하는구나 -> time limit exceeded 원인
            # => 루트는 자기거+왼쪽 자식+오른쪽자식 해서 합 트리를 만들고 머리끼리 지지고 볶고, totalSum은 root 노드꺼겠네
            if node.left:
                leftSum = node.left.val
                self.result = max(self.result, leftSum * (root.val - leftSum))
            if node.right:
                rightSum = node.right.val
                self.result = max(self.result, rightSum * (root.val - rightSum))
            
            find(node.left)
            find(node.right)
        
        find(root)
        
        # 나머지를 여기다가 했더니 맞았음 => 왜..?
        return self.result % (10**9 + 7)
