#include<stdio.h>

int main()
{
      int page[100], frames[30], length[30];
      int pages, tf, page_faults = 0;
      int m, n, temp, flag, found;
      int position, max_length, prev = -1;

      printf("Enter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &tf);
      printf("\nEnter Values of Reference String\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No.[%d]:\t", m + 1);
            scanf("%d", &page[m]);
      }

      for(m = 0; m < tf; m++)
      {
            frames[m] = -1;
      }
      printf("\npages            frames\n");
      printf("...................................\n");
      for(m = 0; m < pages; m++)
      {
          printf("%d   |\t",page[m]);
            flag = 0;
            for(n = 0; n < tf; n++)
            {
                  if(frames[n] == page[m])
                  {
                        flag = 1;

                        break;
                  }
            }
            if(flag == 0)
            {
                  if (prev == tf - 1)
                  {
                        for(n = 0; n < tf; n++)
                        {
                              for(temp = m + 1; temp < pages; temp++)
                              {
                                    length[n] = 0;
                                    if (frames[n] == page[temp])
                                    {
                                          length[n] = temp - m;
                                          break;
                                    }
                              }
                        }
                        found = 0;
                        for(n = 0; n < tf; n++)
                        {
                              if(length[n] == 0)
                              {
                                    position = n;
                                    found = 1;
                                    break;
                              }
                        }
                  }
                  else
                  {
                        prev++;
                        position = prev;
                        found = 1;
                  }
                  if(found == 0)
                  {
                        max_length = length[0];
                        position = 0;
                        for(n = 1; n < tf; n++)
                        {
                              if(max_length < length[n])
                              {
                                    max_length =length[n];
                                    position = n;
                              }
                        }
                   }
                   frames[position] = page[m];

                   page_faults++;
            }

            for(n = 0; n < tf; n++)
            {
                if(flag==1)
                {

                   continue;
                }

                  if(frames[n] != -1)
                  {
                        printf("%d   |\t", frames[n]);
                  }
            }
           if(flag==1)
             printf("no page fault");
            printf("\n...............................");
            printf("\n");
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page_faults);
      return 0;
}
