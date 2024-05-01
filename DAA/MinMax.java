import java.util.*;

int max, min;

public class MinMax {

    public Maxmin(int low,int high,int [] arr){
        int min1,int max1;
        if(low==high){
            min=max=arr[high];
        }
        else if(low==high-1){
            if(arr[low]<arr[high]){
                min=arr[low];
                max=arr[high];
            }
            else{
                min=arr[high];
                max=arr[low];
            }
        }
        else{
           int mid=(low+high)/2;
            Maxmin(low,mid,arr);
            max1=max;
            min1=min;
            Maxmin(mid+1,high,arr);
            if(max<max1){
                max=max1;

            }
            if(min>min1){
                min=min1;
            }
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of elements:");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        max = a[0];
        min = a[0];

        Maxmin(1, n, arr);
        System.out.println(min);
        System.out.println(max);

    }
}
