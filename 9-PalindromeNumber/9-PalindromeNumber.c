// Last updated: 8/4/2026, 12:26:05 PM
bool isPalindrome(int x) {
    int remainder,original=x;
    long int reversed=0;
    if(x<0)
    {
        return 0;
    }
    if(x<10)
    {
        return 1; 
    }
    while (x != 0) 
    {
       remainder = x % 10;
       reversed = reversed * 10 + remainder;
       x /= 10;
    }
  return (original == reversed);
}