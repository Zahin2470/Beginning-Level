#include <stdio.h>

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Enter two numbers: 256 56
    // GCD of 256 and 56 is: 8
    // LCM of 256 and 56 is: 1792
    
    // Calculate GCD and LCM
    int gcd_result = gcd(num1, num2);
    int lcm_result = lcm(num1, num2);
    
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd_result);
    printf("LCM of %d and %d is: %d\n", num1, num2, lcm_result);
    
    return 0;
}