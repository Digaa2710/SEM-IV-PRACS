import java.util.*;

public class Main
{   
    static void bfs(int adj[][],int source){
        int visited []=new int[adj.length];
        Queue<Integer>q=new LinkedList<>();
        
        q.add(source);
        
        while(!q.isEmpty()){
            int node=q.poll();
            visited[node]=1;
            System.out.println(node);
            
            for(int i=0;i<adj.length;i++){
                if(adj[node][i]==1 && visited[i]!=1){
                    q.add(i);
                    visited[i]=1;
                }
            }
        }
    }
	public static void main(String[] args) {
		int adj[][]={
		    {0,1,1,0},
		    {1,0,0,1},
		    {1,0,0,0},
		    {0,1,0,0}
		};
		bfs(adj,0);
	}
}
