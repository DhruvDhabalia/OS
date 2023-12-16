#include <stdio.h>
#include <conio.h>
#define max 25

void main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    printf("\n\tMemory Management Scheme - Next Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);

    printf("Enter the number of files:");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    int start = 1; 

    for (i = 1; i <= nf; i++)
    {
        temp = 0;

        for (j = start; j <= nb; j++)
        {
            if (bf[j] != 1) 
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    bf[ff[i]] = 1;
                    start = j + 1; 
                    break;
                }
            }
        }

        frag[i] = temp;
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);

    getch();
}
