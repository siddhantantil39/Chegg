import java.util.*; 

public class LinkedList { 
	Node head; 
	static class lst{  // innser number(scores) list..
		int val; 
		lst next;
		lst(int v){
			this.val = v;
			this.next = null;
		} 
		public static lst ins(lst head, int val){
			lst newNode = new lst(val);
			if(head==null) head = newNode;
			else {
				lst tp = head;
				while(tp.next!=null){
					tp = tp.next;
				}
				tp.next = newNode;
			}
			return head;
		}
	}
	static class Node { 
		String name;
		Node next; lst a;
		Node(String nm) { 
			name = nm; 
			next = null; a = null;
		} 
	} 
	public static LinkedList insert(LinkedList list, String nm) { 
		Node new_node = new Node(nm); 
		new_node.next = null; 

		if (list.head == null) { 
			list.head = new_node; 
		} 
		else { 
			Node last = list.head; 
			while (last.next != null) { 
				last = last.next; 
			} 
			last.next = new_node; 
		} 

		return list; 
	} 

	public static void promptList(LinkedList list) { 
		Scanner sc = new Scanner(System.in);
		Node currNode = list.head; 
		while (currNode != null) { 
			System.out.print(currNode.name + " : Enter no. of  Scores : "); 
			int n = sc.nextInt();  int res=0;
			System.out.print("Enter your Scores : "); 
			for(int i=0;i<n;i++){
				int p = sc.nextInt(); res+=p;
				currNode.a = currNode.a.ins(currNode.a,p);
			} System.out.println("");
			currNode = currNode.next;
		} 
	}
	public static void disp(LinkedList list){
		Scanner sc = new Scanner(System.in);
		Node currNode = list.head; 
		while (currNode != null) { 
			int res=0,n=0; lst tp = currNode.a;
			while(tp!=null){
				res+=tp.val;
				n++; tp = tp.next;
			}
			System.out.println("\nAverage score of "+ currNode.name +" : "+((float)res/n));
			System.out.println("Total Score of "+ currNode.name +" : "+res);
			if((float)res/n >= 80) {
				System.out.println(currNode.name + "'s grade is : A");
			} else if((float)res/n >= 60) {
				System.out.println(currNode.name + "'s grade is : B");
			} else if((float)res/n >= 40) {
				System.out.println(currNode.name + "'s grade is : C");
			} else {
				System.out.println(currNode.name + " Failed..");
			}
			currNode = currNode.next; 
		} 
	} 

	public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in);
		LinkedList list = new LinkedList(); 

		System.out.print("Enter number of students : ");
		int n = sc.nextInt();
		System.out.println("\nEnter names one by one ");
		for(int i=0;i<n;i++){
			String s = sc.next();
			list = insert(list, s); 
		}

		promptList(list); 
		disp(list);
		// prompt.. scores.

	} 
} 
