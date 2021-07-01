import java.util.Scanner;

class Node{
 
	Node parent, right, left;
	int data;

	public Node(int data){
	  this.data = data;
	}
}

public class BST{
  
    Node head;

    public void insert(int value){
	    Node newNode;
            if(head == null){
	        newNode = new Node(value);
		head = newNode;
		return;
	    }
	    Node curr = head, parent = null;
	    while(curr != null){
	      if(curr.data >= value){
		 parent = curr;
	         curr = curr.left;
	      }else{
		 parent = curr;
	         curr = curr.right;
	      }
	    }
            newNode = new Node(value);
	    if(parent.data >= value){
	      parent.left = newNode;
	      newNode.parent = parent;
	    }else{
	      parent.right = newNode;
	      newNode.parent = parent;
	    }
    }
    void inorder(Node n){
       if(n == null) return ;
       
       inorder(n.left);
       System.out.print(n.data + "\t");
       inorder(n.right);
    }
    void preorder(Node n){
        if(n== null) return;

        System.out.print(n.data + "\t");
	preorder(n.left);
	preorder(n.right);
    }
    void postorder(Node n){
      if(n == null ) return ;

      postorder(n.left);
      postorder(n.right);
      System.out.print( n.data + "\t");
    }

    public void printing(){
        if(head == null){
	   System.out.println("Head is NULL");
	   return;
	}
	Node cu = head;
	System.out.print("Inorder : ");
	inorder(cu);

	System.out.print("\nPreorder : ");
	preorder(cu);
	System.out.print("\npostoder : ");
	postorder(cu);
	System.out.println();
    }

    public void nextNode(Node N){
         if(N == null){
	    System.out.println(" Node is empty");
	    return;
	 }
	 if(N.right != null){
            System.out.println(getNextNode(N.right).data);	 
	    return;
	 }else{
	    Node parent = N.parent;
	    Node child = N;
	    while(parent.right == child){
	       child = child.parent;
	       parent = parent.parent;
	    }
	    System.out.println(parent.data);
	 }
         
    }  
    Node getNextNode(Node N){
       if(N.left == null) return N;
       else return( N.left);
    }
    public static void main(String[] args){
       Scanner S = new Scanner(System.in);
       BST b = new BST();
       System.out.print("Enter the size : ");
       int n = S.nextInt();
       for(int i = 0 ;i < n ; i++){
          int c  = S.nextInt();
	  b.insert(c);
       }
       System.out.println("List inorder");
       b.printing();
       b.nextNode(b.head.left.right.right.right);
    }
}

