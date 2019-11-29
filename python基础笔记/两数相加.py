# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        prenode = ListNode(0)
        lastnode = prenode
        val = 0
        while val or l1 or l2:
            val, cur = divmod(val + (l1.val if l1 else 0) + (l2.val if l2 else 0), 10)#第一次结果为：var=0,cur=7
            #divmod(7, 2)
            #返回元组(3, 1)，因为2*3+1=7
            lastnode.next = ListNode(cur)
            lastnode = lastnode.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return prenode.next

def generateList(l: list) -> ListNode:
    prenode = ListNode(0)
    lastnode = prenode
    for val in l:
        lastnode.next = ListNode(val)
        lastnode = lastnode.next
    return prenode.next

def printList(l: ListNode):
    while l:
        print("%d, " %(l.val), end = '')
        l = l.next
    print('')

if __name__ == "__main__":
    l1 = generateList([2, 4, 3])
    l2 = generateList([5, 6, 4])
    #printList(l1)
    #printList(l2)
    s = Solution()
    sum = s.addTwoNumbers(l1, l2)
    printList(sum)
'''
7, 0, 8,
[Finished in 0.1s]
'''