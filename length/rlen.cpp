int  length(char string[])
{
    int index;      // index into the string 

    /*
     * Loop until we reach the end of string character
     */
    for (index = 0; string[index] != '\0'; ++index)
        /* do nothing */ ;
    return (index);
}
