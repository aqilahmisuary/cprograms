/* Exam

1. Dennis Ritchie
2. True
3. 4
4. Prints Hello World followed by a new line
5. A circles area
6. %d
7. Its an infinite loop
8. It should return 0;
9. 3
10.1
11.1
12.0
13.0
14.3
15.-5
16. 6
17. 2
18. 3
19. 0 
20. 0
21. 0
22.1
23. The function has no arguments
24. False
25. There is a conversion from double to int
26. foobar(k) = 7, k = 7 
27. False
28. It was intended to compile optimized code
29. There would be problems with accuracy
30. False
31. 2
32. 7
33. True
34. True
35. None of these
36. 10
37. 7
38. False
39. True
40. False
41. p= &5.15 
 
*/

#include <stdio.h>

int mystery(int p, int q)
{
	int r;
	if ((r = p % q) == 0)
		return q;
	else return mystery(q, r); 

}

int main()
{
	int ans;
	ans = mystery(7, 91);
	printf("%d\n", ans);
}
