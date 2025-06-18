import java.util.*;

public class Main
{   
    
    static int[] incoming(int adj[][]){
        int incomings[]=new int[adj.length];
        for(int i=0;i<adj.length;i++){
            for(int j=0;j<adj[0].length;j++){
                incomings[j]+=adj[i][j];
            }
        }
        return incomings;
    }
    static void topo(int adj[][],int incomings[],int visited[]){
        int i=0;
        for( i=0;i<incomings.length;i++){
            if(incomings[i]==0 && visited[i]==0){
               visited[i]=1;
               System.out.println(i);
               break;
               
            }
        }
        
        for(int j=0;j<adj.length;j++){
            if(adj[i][j]==1){
                incomings[j]--;
            }
        }
        
        for(int j=0;j<visited.length;j++){
            if(visited[j]==0){
                topo(adj,incomings,visited);
            }
        }
        
    }
	public static void main(String[] args) {
		int adj[][]={
		    {0,0,0,0,0,0},
		    {0,0,0,0,0,0},
		    {0,0,0,1,0,0},
		    {0,1,0,0,0,0},
		    {1,1,0,0,0,0},
		    {1,0,1,0,0,0}
		};
		int visited[]=new int[adj.length];
		int incomings[]=new int[adj.length];
		incomings=incoming(adj);
		topo(adj,incomings,visited);
	}
}
