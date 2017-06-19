class Solution {
public:
	void replaceSpace(char *str,int length) {
        int i = 0;
        int count = 0;
        while (*(str + i) != '\0')
        {
            if (*(str + i) == ' ')
            {
                count++;
            }
            i++;
        }
        for (;i>=0;i--)
        {
            if( *(str+i) != ' ')
            {
                *(str+i+2*count) = *(str+i);
            }
            else
            {
                *(str+i+2*count) = '0';
                *(str+i+2*count-1) = '2';
                *(str+i+2*count-2) = '%';
                count--;
            }
        }
        

	}
};
