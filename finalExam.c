/*

1. True
2. False
3. False
4. False
5. False
6. 0
7. 2
8. 1
9. 1
10. 0
11. 0
12. 1
13. 1
14. 0
15. 1
16. 56
17. 6
18. double
19. stdlib.h
20. void*
21. 15 doubles
22. None of these
23. c1 -> real
24. Higher than all of these
25. The array element look-up is faster
26. Does not work on the empty list
27. temp is a file in the local directory
28. Stroustrup
29. auto
30. precision is 6 significant figures

*/

#include<stdio.h>
int main()
{
   int a = 2, b = 5, c = 8;

   printf("  a && b  = %d \n ",  a && b);
   printf(" b %% a   = %d \n ", b % a );  
   printf(" a / b    = %d \n " , a/b); 
   printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b);  
   printf(" b <= c = %d \n "  , b<= c);
   printf(" !!c = %d \n " , !!c); 
   printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
   printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
   printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
   printf(" c = ++b = %d \n ",c = ++b);  
   return 0;
}


