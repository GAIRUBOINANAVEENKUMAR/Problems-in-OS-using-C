//ROUND ROBIN SCHEDULING ALGORITHM WITHOUT ARRIVAL TIME
#include <stdio.h>

char pname[5];  
int burst[5];  
int wait[5];   
int res[5];
int tat[5];
int ts;
int n;
int t = 0;
int timeslice=0;//TEMPORARY VARIABLE
int main() {
    int i;
    int k;
    printf("Enter the number of processes you have done: ");
    scanf("%d", &n);
    printf("Enter the Time slice: ");
    scanf("%d", &ts);
    
    for (i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf(" %c", &pname[i]);
    }
    for (i = 0; i < n; i++) {
        printf("Enter the burst time of process %c: ", pname[i]);
        scanf("%d", &burst[i]);
    }
    
    char bur[5];
    for(int i=0;i<n;i++){
        bur[i]=burst[i];
    }
    for(int i=0;i>-1;i++){
        for(int j=0;j<n;j++){
            if(bur[j]>ts){
                bur[j]-=ts;
                timeslice+=ts;
            }
            else if(bur[j]<=ts && bur[j]>0 ){
                timeslice+=bur[j];
                bur[j]=0;
                tat[j]=timeslice;
            }
            
        }
        int zeros=1;
        for (int k=0;k<n;k++) {
            if (bur[k] != 0) {
                zeros = 0;
                break;
            }
        }
        if (zeros==1) {
            break;
        }
    }
    for(int i=0;i<n;i++){
        wait[i]=tat[i]-burst[i];
        res[i]=i*ts;
    }
    printf("\nProcess Name\tBurst Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++){
        printf("%c\t\t%3d\t\t%3d\t\t%3d\t\t%3d\n", pname[i],burst[i], wait[i], res[i], tat[i]);
    }
    float r;
    float w;
    float turn;
    for (int i=0;i<n;i++){
        w=w+wait[i];
        turn=turn+tat[i];
        r+=res[i];
    }
    printf("the average wait time is %.2lf",w/n);
    printf("\nthe average response time is %.2lf",r/n);
    printf("\nthe average Turn Around time is %.2lf",turn/n);
    return 0;
}