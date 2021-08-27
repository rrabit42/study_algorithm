class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        # 올바른 tree인지 검증
        # root->left->right
        # 이용할 수 있을 만한게 index, level(?), ## 두개 연속으로 => vlr이니까 내 자식을 연속해서 스택에 넣을 수 있다
        # 아스키코드에서 #이 숫자문자보다 항상 작다
        
        stack = []
        for val in preorder.split(','):
            stack.append(val)
            
            # leaf node 찾기
            while len(stack) > 2 and stack[-1] == '#' and stack[-2] == '#':
                stack.pop()
                stack.pop()
                leaf = stack.pop()
                # leaf 노드는 null 이면 안됨
                if leaf == '#':
                    return False
                stack.append('#') # leaf 노드가 맞으면 null로 정리해가기

        # 마지막이 # 이면 됨
        return (stack[-1] == '#' and len(stack) == 1)
