class Solution {
    public ListNode rotateRight(ListNode head, int k) {

        if (head == null || head.next == null || k == 0)
            return head;

        // Find length
        int n = 1;
        ListNode temp = head;

        while (temp.next != null) {
            temp = temp.next;
            n++;
        }

        // Avoid unnecessary rotations
        k = k % n;

        if (k == 0)
            return head;

        // Make circular
        temp.next = head;

        // Find new tail
        int steps = n - k;
        ListNode newTail = temp;

        while (steps > 0) {
            newTail = newTail.next;
            steps--;
        }

        // New head
        ListNode newHead = newTail.next;

        // Break the circle
        newTail.next = null;

        return newHead;
    }
}