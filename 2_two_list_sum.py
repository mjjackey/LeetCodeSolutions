"""
https://leetcode-cn.com/problems/add-two-numbers/
"""
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self,l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        sum1=0
        sum2=0
        sum1_list=[]
        sum2_list=[]
        while(l1!=None or l2!=None):
            # if(l1!=None):  #### for len(l1) != len(l2)
            l1,x1=Solution.getValueAndMoveToNext(self,l1)
            # sum1 = sum1 * 10  # put before
            # sum1+=x1
            sum1_list.append(x1)

            # if(l2!=None):
            l2,x2 = Solution.getValueAndMoveToNext(self,l2)
            # sum2 = sum2 * 10
            # sum2 += x2
            sum2_list.append(x2)

        for x in sum1_list[::-1]:
            sum1=sum1*10
            sum1+=x

        for x in sum2_list[::-1]:
            sum2 = sum2 * 10
            sum2 += x

        sum=sum1+sum2
        print(sum1,sum2,sum)
        if(sum==0): return ListNode(0)  ####
        res_list=[]
        while(sum>0):
            res = sum % 10
            print("res", res)
            sum=sum//10
            print("sum",sum)
            res_list_node = ListNode(res)
            if(len(res_list)>0): Solution.genNextNode(self,res_list[-1],res_list_node)
            res_list.append(res_list_node)
        return res_list

    def getValueAndMoveToNext(self, l):
        x=0  ##### assign before reference
        if (l != None):
            x = l.val
            l = l.next
        return (l,x)

    def genNextNode(self, l1, l2):
        if (l1 != None and l2 != None):
            l1.next = l2

if __name__ == "__main__":
    # l1_1=ListNode(2)
    # l1_2=ListNode(4)
    # l1_3 = ListNode(3)
    # l1_1.next=l1_2
    # l1_2.next=l1_3
    # l2_1=ListNode(5)
    # l2_2 = ListNode(6)
    # l2_3 = ListNode(4)
    # l2_1.next=l2_2
    # l2_2.next=l2_3

    l1_1=ListNode(1)
    l1_2=ListNode(8)
    l1_1.next=l1_2
    l2_1=ListNode(0)

    sol=Solution()
    rest_list=sol.addTwoNumbers(l1_1,l2_1)
    for a in rest_list:
        print(a.val)
