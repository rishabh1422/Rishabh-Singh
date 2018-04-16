#include<stdio.h>
int main() 
{ 
 
  int a,j,n,time,remain,sum=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("------------------------Enter Total Process----------------------------------\n "); 
  scanf("%d",&n); 
  remain=n; 
  for(a=0;a<n;a++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d\n",a+1); 
    scanf("%d",&at[a]); 
    scanf("%d",&bt[a]); 
    rt[a]=bt[a]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,a=0;remain!=0;) 
  { 
    if(rt[a]<=time_quantum && rt[a]>0) 
    { //9876066345
      time+=rt[a]; 
      rt[a]=0; 
      sum=1; 
    } 
    else if(rt[a]>0) 
    { 
      rt[a]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[a]==0 && sum==1) 
    { 
      remain--; 
      printf(".......................................................
	        P[%d]\t:\t%d\t:\t%d\n",a+1,time-at[a],time-at[a]-bt[a]); 
      wait_time+=time-at[a]-bt[a]; 
      turnaround_time+=time-at[a]; 
      sum=0; 
    } 
    if(a==n-1) 
      a=0; 
    else if(at[a+1]<=time) 
      a++; 
    else 
      a=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
