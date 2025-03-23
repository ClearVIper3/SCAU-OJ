long long countCompleteDayPairs(int* hours, int hoursSize)
{
    long long p=0;
    int count[24]={0};

    for(int i=0;i<hoursSize;i++)
    {
        p+=count[(24-hours[i]%24)%24];
        count[hours[i]%24]++;
    }
    return p;
}
