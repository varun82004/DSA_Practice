void subset(int arr[],int x[],int k,int r,int m,int s){
    if(s+arr[k]==m){
     x[k]=1;
     cout<<"[";
     for(int i=0;i<=k;i++){
         if(x[i]==1)
             cout<<arr[i]<<",";
     }
     cout<<"]"<<endl;
    }
    else if(s+arr[k]<=m){
     x[k]=1;
     subset(arr,x,k+1,r-arr[k],m,s+arr[k]);
    }
    if((s+r-arr[k]>=m)){
     x[k]=0;
     subset(arr,x,k+1,r-arr[k],m,s);
    }
}
