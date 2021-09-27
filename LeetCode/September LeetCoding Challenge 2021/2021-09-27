class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        # 메일을 받을 수 있는 서로 다른 메일의 개수
        res = set()
        for email in emails:
            local_name, domain_name = email.split('@')
            local_name = local_name.replace('.', '')
            local_name = local_name.split('+')[0]
            res.add(f"{local_name}@{domain_name}")
        
        return len(res)
