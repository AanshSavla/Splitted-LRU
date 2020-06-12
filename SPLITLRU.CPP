#include<stdio.h>
#include<conio.h>
void main()
{
      int frames[10], temp[10], pages[25];
      int total_pages, m, n, position, k, l, frames1,frames2,hits=0;
      int a = 0, b = 0, page_fault = 0,flag=1,sig=0;
      clrscr();
      printf("\nEnter Number of Frames in Frame1:");
      scanf("%d", &frames1);
      printf("\nEnter Number of Frames in Frame2:");
      scanf("%d",&frames2);
      for(m = 0; m < frames1+frames2; m++)
      {
	    frames[m] = -1;
      }
      printf("Enter Total Number of Pages:");
      scanf("%d", &total_pages);
      printf("Enter Values for Reference String:\n");
      for(m = 0; m < total_pages; m++)
      {
	    printf("Value No.[%d]:", m + 1);
	    scanf("%d", &pages[m]);
      }

      for(n=0;n<total_pages;n++)
      {
		a=0;
		b=0;
		for(m=0;m<frames1;m++)
		{
			if(frames[m]==pages[n])
			{
				hits++;
				a=1;
				b=1;
				sig=1;
			}
		}
		for(m=frames1;m<frames1+frames2;m++)
		{
			if(frames[m]==pages[n])
			{
				hits++;
				a=1;
				b=1;
				sig=2;
			}
		}
		if(a==0)
		{
			if(flag==1)
			{
				for(m=0;m<frames1;m++)
				{
					if(frames[m]==-1)
					{
						frames[m]=pages[n];
						sig=1;
						page_fault++;
						b=1;
						break;
					}
				}

			}
			else if(flag==2)
			{
				for(m=frames1;m<frames1+frames2;m++)
				{
					if(frames[m]==-1)
					{
						frames[m]=pages[n];
						sig=2;
						page_fault++;
						b=1;
						break;
					}
				}
			}

		}
		if(b==0)
		{
			if(flag==1)
			{
				for(m = 0; m < frames1; m++)
				{
					temp[m] = 0;
				}
				for(k = n - 1, l = 1; l<=(frames1+frames2) - 1; l++, k--)
				{

					for(m = 0; m < frames1; m++)
					{
						if(frames[m] == pages[k])
						{
							temp[m] = 1;
						}
					}
				}
				for(m = 0; m < frames1; m++)
				{
					if(temp[m] == 0)
						position = m;
				}
				frames[position] = pages[n];
				page_fault++;
				sig=1;
			}
			else if(flag==2)
			{
				for(m = frames1; m < frames1+frames2; m++)
				{
					temp[m] = 0;
				}
				for(k = n - 1, l = frames1; l <= (frames2+frames1) - 1; l++, k--)
				{

					for(m = frames1; m < frames1+frames2; m++)
					{
						if(frames[m] == pages[k])
						{
							temp[m] = 1;
						}
					}
				}
				for(m = frames1; m < frames1+frames2; m++)
				{
					if(temp[m] == 0)
						position = m;
				}
				frames[position] = pages[n];
				page_fault++;
				sig=2;
			}
		}

		if(sig==1)
		{
			flag=2;
		}
		else if(sig==2)
		{
			flag=1;
		}
	 printf("%d %d : %d\n",frames[0],frames[1],frames[2]);
      }

      printf("Number of hits=%d",hits);
      getch();
}