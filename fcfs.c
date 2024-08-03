#include <stdio.h>

char pname[5];  
int burst[5];  
int wait[5];   
int res[5];
int tat[5];
int n;
int t = 0;
 
 
int main() {
    int i;
    printf("Enter the number of processes you have done: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf(" %c", &pname[i]);
        printf("Enter the burst time of process %c: ", pname[i]);
        scanf("%d", &burst[i]);
    }
     for (int i = 0; i < n; i++){
        wait[i] = t;
        res[i] = t;
        t += burst[i];
        tat[i] = t;
    }
    printf("\nProcess Name\tBurst Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++){
        printf("%c\t\t%3d\t\t%3d\t\t%3d\t\t%3d\n", pname[i], burst[i], wait[i], res[i], tat[i]);
    }
    float r;
    float w;
    float turn;
    for (int i=0;i<n;i++){
        w=(float)w+wait[i];
        turn=(float)turn+tat[i];
        r=(float)r+res[i];
    }
    printf("the average wait time is %.2lf",w/n);
    printf("\nthe average response time is %.2lf",r/n);
    printf("\nthe average Turn Around time is %.2lf",turn/n);
 
    return 0;
}