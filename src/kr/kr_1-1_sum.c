#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


int main(void)
{
    int sizeNumbers = 6;
    int numbers[6] = {10,20,30,49,50,60};

    int maxSum = 0;
    int maxSumInd[6] = {0};
    for (int i = 0; i < sizeNumbers; i++) {
        int sum = (numbers[i] / 10) + (numbers[i] - ((numbers[i] / 10) * 10)); 
        //printf("%d\n", sum);
        if (sum > maxSum) {
            maxSum = sum;
            for (int j = 0; j < sizeNumbers ;j++)
                maxSumInd[j] = 0;
            maxSumInd[i] = 1;
        } else if (sum == maxSum) {
            maxSumInd[i] = 1;
        }
    }
    for (int i = 0; i < sizeNumbers; i++) {
        if (maxSumInd[i] == 1) {
            printf("%d\n", numbers[i]);
            return 0;
        }
    }
    return -1;
}
