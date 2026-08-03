int romanToInt(char* s) {
    int nums[256] = {0};
    nums['I'] = 1;
    nums['V'] = 5;
    nums['X'] = 10;
    nums['L'] = 50;
    nums['C'] = 100;
    nums['D'] = 500;
    nums['M'] = 1000;
    int result = 0;
    for(int i=0;s[i] != '\0';i++)
    {
        if(nums[s[i]] < nums[s[i+1]])
        {
            result -= nums[s[i]];
        }
        else{
            result += nums[s[i]];
        }
    }
    return result;
}