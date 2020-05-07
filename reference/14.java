// 순열 조합
// https://118k.tistory.com/267
public void permutation(String[]arr,int pivot){
        int len=arr.length;
        if(pivot==len){
            String temp="";
            for(int i=0;i<len; i++)
                temp+=arr[i];
            al.add(temp);
        }
        for(int i=pivot;i<len; i++){
            swap(arr,i,pivot);
            permutation(arr,pivot+1);
            swap(arr,i,pivot);
        }
}

public void swap(String[]arr,int i,int j){
        String temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
}