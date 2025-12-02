#include <stdio.h>
#include <string.h>

#define R 5
#define C 80
#define SWAP(a,b) { unsigned long long tmp = a; a = b; b = tmp; }
int main() {
	char arr[R][C];
	char* p_arr[R];
	int count = 0; 

    while (count < R) {
        printf("String %d: ", count + 1);
        fgets(arr[count], C, stdin);

            arr[count][strcspn(arr[count], "\n")] = '\0';
            if (strcmp(arr[count], "*") == 0)
            break;

        p_arr[count] = arr[count]; 
        count++;
    }
        
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(p_arr[i], p_arr[j]) > 0) {
                //char* temp = p_arr[i];
                //p_arr[i] = p_arr[j];
                //p_arr[j] = temp;
                SWAP(p_arr[i], p_arr[j]);                
            }
        }
    }
    printf("\nSorted strings:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", p_arr[i]);
    }


}