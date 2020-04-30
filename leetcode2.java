package cn.xmy.problem2;


public class Problem2 {
	public static void main(String[] args) {
		ListNode a = new ListNode(5);
		a.next = new ListNode(2);
		a.next.next = new ListNode(1);
		
		ListNode b = new ListNode(5);
		b.next = new ListNode(2);
		b.next.next = new ListNode(1);
		
		Solution s = new Solution();
		ListNode c = s.addTwoNumbers(a, b);
		
		while(c!=null)
		{
			System.out.println(c.val);
			c = c.next;
		}
		
		
//		ListNode l1 = new ListNode(1);
//		l1.next = new ListNode(8);
//		
//		ListNode l2 = new ListNode(0);
//
//		
//		Solution s = new Solution();
//		ListNode l3 = s.addTwoNumbers(l1, l2);
//		while(l3!=null)
//		{
//			System.out.println(l3.val + "->");
//			//System.out.println(l3);
//			l3 = l3.next;
//		}
	}
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) 
    { 
    	val = x; 
    }
}
//class Solution {
//    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//        ListNode pre = new ListNode(0);
//        ListNode cur = pre;
//        int carry = 0;
//        while(l1 != null || l2 != null) {
//            int x = l1 == null ? 0 : l1.val;
//            int y = l2 == null ? 0 : l2.val;
//            int sum = x + y + carry;
//            
//            carry = sum / 10;
//            sum = sum % 10;
//            cur.next = new ListNode(sum);
//
//            cur = cur.next;
//            if(l1 != null)
//                l1 = l1.next;
//            if(l2 != null)
//                l2 = l2.next;
//        }
//        if(carry == 1) {
//            cur.next = new ListNode(carry);
//        }
//        return pre.next;
//    }
//}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	ListNode res = new ListNode(0);
    	int c = 0;
    	ListNode head = res;
    	while(l1 != null || l2 != null)
    	{
    		int x = (l1 == null) ? 0 : l1.val;
    		int y = (l2 == null) ? 0 : l2.val;
    		
    		int sum = c + x + y;
    		
    		c = sum / 10;
    		sum %= 10;//(sum = sum % 10;)
    		res.next = new ListNode(sum);
    		res = res.next;
    		
    		if(l1 != null)
    		{
    			l1 = l1.next;
    		}

    		if(l2 != null)
    		{
    			l2 = l2.next;
    		}
    		
    	}
    	
    	if(c == 1)
    	{
    		res.next = new ListNode(c);
    	}
    	
    	
		return head.next;
    	
    }
}