import java.util.Scanner;

class Node{
   
   Node next;
   int data;

   public Node(int data){
     this.data = data;
   }
}

public class LinkedList{
    Node head;
    public void insertAtFront(int value){
        Node current;
	current = new Node(value);
	current.next = head;
	head = current;
    }

    public void insertAtBack(int value){
        Node current;
	if(head == null){
	   current = new Node(value);
	   head = current;
	   return;
	}
	current = head;
        while(current.next != null){
	   current = current.next;
	}
	Node cur = new Node(value);
	current.next = cur;
    }

    public void deleteN(int value){
       if(head == null){
          System.out.println("List is empty");
          return ;
       }
       Node current = head;
       if(current.data == value){
          head = current.next;
	  return;
       }
      // current = head.next;
       while(current.next != null){
          if(current.next.data == value){
	     System.out.println("Node " + current.next.data + " Is deleted.");
	     current.next = current.next.next;
	     return;
	  } 
          current = current.next;
       }
    }

    public void printing(){
          if (head == null) {
            System.out.println("Node is empty");
	    return;
	  }
	  Node cur = head;
         while(cur != null){
	   System.out.print(cur.data + "\t");
	   cur = cur.next;
	 }
    }

  
    public static void main(String[] args){
       Scanner S = new Scanner(System.in);
       LinkedList L = new LinkedList();
       int n = S.nextInt();
       for(int i = 0 ;i < n ;i++){
          int value1 = S.nextInt();
	  int val2  = S.nextInt();
	  L.insertAtFront(value1);
	  L.insertAtBack(val2);
       }
       L.printing();
    }
}
