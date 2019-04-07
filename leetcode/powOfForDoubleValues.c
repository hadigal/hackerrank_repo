double myPow(double x, int n)
{
    double val = 1;
    //unsigned int tempN;
    if(n == 0)
    {
        return val;
    }

    if(n < 0)
    {
        if((n == INT_MIN) && (x > 1.0 || x < -1.0))
        {
            return 0.0;
        }
        //tempN = ((unsigned int)(n))*(-1);
        //n = (int)(tempN);
        n = ((unsigned int)(n))*(-1);
        x = 1/x;
    }

    if(n%2 == 1)
    {
        val = val*x;
    }
    val = val*myPow((x*x),n/2);

    return val;
}
