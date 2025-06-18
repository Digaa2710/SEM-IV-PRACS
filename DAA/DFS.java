import java.util.*;

public class Main
{   
    static void dfs(int adj[][],int source,int visited[],Stack<Integer>s){
        
        s.push(source);
        visited[source]=1;
        System.out.println(source);
        
        for(int i=0;i<adj.length;i++){
            if(adj[source][i]==1 && visited[i]==0){
                visited[i]=1;
                dfs(adj,i,visited,s);
            }
        }
        s.pop();
    }
	public static void main(String[] args) {
		int adj[][]={
		    {0,1,1,0},
		    {1,0,0,1},
		    {1,0,0,0},
		    {0,1,0,0}
		};
		int visited[]=new int[adj.length];
		Stack<Integer>s=new Stack<>();
		dfs(adj,0,visited,s);
	}
}
