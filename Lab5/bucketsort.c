#include <stdio.h>

int max_element(int array[], int size) 
{	
	int max = array[0];  
	int i;
    for (i = 0; i < size; i++)
    {	
		if (array[i] > max)  
        max = array[i];  
    }
    return max;  
}
void Bucket_Sort(int array[], int size) 
{  
    int max = max_element(array, size);
    int bucket[max+1],i;  
    for (i = 0; i <= max; i++)  

    bucket[i] = 0;  

    for (i = 0; i < size; i++)  
    	bucket[array[i]]++;
    	
    int j=0;
    for (i = 0; i <= max; i++)  
    {
        while (bucket[i] > 0)  
        {  
			array[j++] = i;
            bucket[i]--;   
        }  
    }  
} 
int main()
{
    int array[100], i, num; 
    printf("Enter size of array: ");   
    scanf("%d", &num);   

    printf("Enter elements: "); 
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]); 

    printf("\nAfter sorting: "); 
    Bucket_Sort(array, num); 
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);   

    return 0;
}
