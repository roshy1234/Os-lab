#include<stdio.h>
void main() {
    int i,j,k,min,rs[25],m[10],count[10],flag[25],n,f,pf=0,next=0;
    printf("Enter the length of the reference string --");
    scanf("%d",&n);
    printf("Enter the reference string -- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        count[i]=0;
        m[i]=-1;
    }
    printf("\nThe Page Replacement process is -- \n");
    for(i=0;i<n;i++) {
        int found = 0;
        for(j=0;j<f;j++) {
            if(m[j]==rs[i])   {
                count[j]++;
                found = 1;
                break;
            }
        }
        if(!found)
        {
            if(i<f) {
                m[i] = rs[i];
                count[i]++;
            }
            else{
                min = 0;
                for(j=1;j<f;j++) {
                    if(count[j]<count[min])
                        min = j;
                }
                m[min] = rs[i];
                count[min] = 0; // Set the count to 0 for the new page
            }
            pf++;
        }
        for(j=0;j<f;j++)
            printf("%d\t",m[j]);
        if(!found)
            printf("PF no. -- %d",pf);
        printf("\n");
    }
    printf("\nTotal Page Faults -- %d", pf);
}