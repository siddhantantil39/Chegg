import java.util.*; 
// PriorityQueue is the inbuilt Library function for Min-Heap in Java
class ProcessInfo implements Comparable<ProcessInfo>{
    int Pid,BurstTime,prty,st,ed;
    ProcessInfo(int a,int b,int c){
        this.Pid=a;
        this.BurstTime=b;
        this.prty=c;
        this.st=-1; this.ed=-1;
    }
    public ProcessInfo getProcess(){
        return this;
    }
    public void setBs(int b){
        this.BurstTime = b;
        return;
    }
    public void setSt(int st){
        this.st = st;
        return;
    }
    public void setEd(int ed){
        this.ed = ed;
        return;
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ProcessInfo p = (ProcessInfo) o;
        return Double.compare(p.prty, this.prty) == 0 &&
                Objects.equals(this.Pid, p.Pid);
    }

    @Override
    public int hashCode() {
        return Objects.hash(Pid, BurstTime, prty);
    }

    @Override
    public String toString() {
        return ""+Pid;
    }

    @Override
    public int compareTo(ProcessInfo p) {
        if(this.prty > p.prty){
            return 1;
        } else if (this.prty < p.prty) {
            return -1;
        } else {
            return 0;
        }
    }
}
class PQ { 
    static int n,a,b,c;
	public static void main(String args[]) 
	{ 
        // Reading input from file.. 
        /*
            Scanner sc = new Scanner(new File("inputfile.txt")); // Open comments while reading from file..
        */

        // reading from terminal.
        Scanner sc = new Scanner(System.in);  // comment this line while reading input from file...
        PriorityQueue<ProcessInfo> pq = new PriorityQueue<ProcessInfo>(); // Using PriorityQueue - same as minHeap..

        System.out.println("Enter no. of Tasks");
        n = sc.nextInt();
        ProcessInfo[] pi = new ProcessInfo[n+1]; 

        System.out.println("Enter id, burstTime, priority for each task...");
        for(int i=0;i<n;i++){
            a=sc.nextInt(); b=sc.nextInt(); c=sc.nextInt();
            pi[a] = new ProcessInfo(a,b,c);
            pq.add(pi[a]);
        }

        Iterator it = pq.iterator();
        System.out.println("Printing initial order..(Only Pid's)");
        while (it.hasNext()) {
                System.out.println(it.next());
        }
        int tm=0; 
        int vs=0;                   // used to check wether all tasks are completed or not..
        int[] vis = new int[n+1];   // used to check wether a task is completed or not..
        for(int i=0;i<n+1;i++) vis[i]=0; 
        
        while(!pq.isEmpty() && vs<n){   // if vs==n then all the tasks are completed..
            it = pq.iterator();
            while(it.hasNext()){
                String p = it.next().toString();
                int i = Integer.parseInt(p);
                if(vis[i]==0){
                ProcessInfo pp = pi[i];
                if(pp.BurstTime <= (10-pp.prty)) {
                    if(pp.st==-1) pp.setSt(tm);
                    tm+=pp.BurstTime; vis[i]=1; vs++; 
                    pp.setEd(tm);
                }
                else{
                    if(pp.st==-1) pp.setSt(tm);
                    int b = pp.BurstTime; tm+=(10-pp.prty);
                    pp.setBs(b-(10-pp.prty));
                    }     
                }
            }
        }

        System.out.println("Starting and ending times for each task: ");
        for(int i=1;i<n+1;i++){
            System.out.println("TaskNo:"+pi[i].Pid+" StTm:"+pi[i].st+" EdTm:"+pi[i].ed);
        }
        System.out.print("Total time req. for all tasks to complete... = ");
        System.out.println(tm);
	} 
} 
