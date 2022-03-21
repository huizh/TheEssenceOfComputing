#include <stdio.h>

// 给定一个实数序列，设计一个最有效的算法，找到一个总和最大的区间。
float a[] = {1.5, -12.3, 3.2, -5.5, 23.2, 3.2, -1.4, -12.2, 34.2, 5.4, -7.8, 1.1, -4.9};

int main()
{
    // 临时cursor ts，te及区间值的总和st；区间内总和的最大值sum
    // 当前找到的最大区间起始点ps，pe和总和max
    int ts, te;
    float st, sum;
    int ps, pe;
    float max;
    ts = -1;
    te = st = ps = pe = 0;
    st = sum = max = 0;
    for (int i = 0; i < 13; i++)
    {
        st += a[i];
        if (a[i] > 0)
        {
            if (ts < 0)
            {
                ts = i;
            }

            if (st > sum)
            {
                sum = st;
                te = i;
            }
        }
        else
        {
            if (st <= 0)
            {
                if (ts >= 0)
                {
                    if (max < sum)
                    {
                        ps = ts;
                        pe = te;
                        max = sum;
                    }

                    st = sum = 0;
                }

                ts = -1;
            }
        }
    }
    if (max < sum)
    {
        ps = ts;
        pe = te;
        max = sum;
    }

    printf("start %d, end %d, max %f \n", ps, pe, max);
    return 0;
}
