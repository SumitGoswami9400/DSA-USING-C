// tower of hanoi


#include <stdio.h>
// Tower of Hanoi program in C using Recursion
void tower_of_hanoi(int n, char A, char C, char B)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c",A ,C );
		return;
	}
	tower_of_hanoi(n-1, A, B, C);
	printf("\n Move disk %d from rod %c to rod %c", n, A, C);
	tower_of_hanoi(n-1, B, C,A);
}

int main()
{
	int n ;
	printf("Enter number of disks: ");
	scanf("%d", &n);
	tower_of_hanoi(n, 'A','C','B'); 
	return 0;
}



