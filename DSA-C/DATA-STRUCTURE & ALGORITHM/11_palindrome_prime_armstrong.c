/*Write a c program to store N multi digit elements in 1 D array then count and print 
    a) total palindrome 
   b) total prime no.
  c) total Armstrong no.
  d) total elements having sum of digits less than 10  
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// Function to check if a number is prime
int isPrime(int n) {
    int i;
    for(i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int n) {
    int temp = n, digit, sum = 0;
    while(temp > 0){
        digit = temp % 10;
        sum += pow(digit, 3);
        temp /= 10;
    }
    if(n == sum){
        return 1;
    }
    return 0;
}

// Function to calculate the sum of digits in a number
int sumOfDigits(int n) {
    int temp = n, sum = 0;
    while(temp > 0){
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

int main() {
    int n, i, j, count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // Counting the number of palindromes, primes, Armstrong numbers, and elements with the sum of digits less than 10
    int palindromeCount = 0, primeCount = 0, armstrongCount = 0, sumOfDigitsCount = 0;
    for(i=0; i<n; i++){
        // Check for palindrome
        int temp = arr[i], reverse = 0;
        while(temp > 0){
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }
        if(arr[i] == reverse){
            palindromeCount++;
        }

        // Check for prime
        if(isPrime(arr[i])){
            primeCount++;
        }

        // Check for Armstrong
        if(isArmstrong(arr[i])){
            armstrongCount++;
        }

        // Check for sum of digits less than 10
        if(sumOfDigits(arr[i]) < 10){
            sumOfDigitsCount++;
        }
    }

    printf("\nTotal number of palindromes: %d", palindromeCount);
    printf("\nTotal number of prime numbers: %d", primeCount);
    printf("\nTotal number of Armstrong numbers: %d", armstrongCount);
    printf("\nTotal number of elements with sum of digits less than 10: %d", sumOfDigitsCount);

    return 0;
}

