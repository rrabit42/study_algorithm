# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        # 합이 같은게 있으면 리턴
        # binary search tree -> 오른쪽은 작은 숫자 노드, 왼쪽은 더 큰 숫자 노드
        
        # tree에 있는 value 값 리스트로 만들기
        val_list = []
        def traverse(node):
            if not node:
                return
            val_list.append(node.val)
            traverse(node.left)
            traverse(node.right)
            return
        traverse(root)
        
        # 트리 전체 탐색
        def search(node):
            if node:
                left = k - node.val
                # 2개를 골라야하니 둘 다 숫자가 같으면 안됨, binary search tree라 중복된 숫자 X
                if left in val_list and left != node.val:
                    return True
                else:
                    return search(node.right) or search(node.left)
            return False
        
        return search(root)
