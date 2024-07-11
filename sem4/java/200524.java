class Solution {
    public String longestCommonPrefix(String[] strs)
    {
        int nc=0;
        if(strs.length==0)
            return "";
        for(int i=0;i<strs.length;i++)
        {
            String sub=strs[0].substring(0,nc+1);
            for(int j=0;j<strs.length;j++)
            {
                if(!sub.equals(strs[i].substring(0,nc+1)))
                {
                    if(nc==1)
                        return "";
                    return(strs[0].substring(0,nc));
                }
            }
            nc++;
        }
        return(strs[0]);          
    }
}