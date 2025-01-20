#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lptr;
    int data;
    struct node *rptr;

} *first = NULL;

void create();
void display();
void insatbeg(int val);
void insatend(int val);
void delnode(int val);

int main()
{
    int ch, val;

    do
    {

        printf("\n|--------MENU--------|");
        printf("\n 1. Create");
        printf("\n 2. display");
        printf("\n 3. insert at beginig");
        printf("\n 4. insert at end");
        printf("\n 5. delete");
        printf("\n 6. Exsit");
        printf("\n|--------------------|");
        printf("\nEnter the your chioce : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            create();
        }

        else if (ch == 2)
        {
            display();
        }

        else if (ch == 3)
        {
            printf("\n Enter the value : ");
            scanf("%d", &val);
            insatbeg(val);
        }
        

        else if (ch == 4)
        {
            printf("\n Enter the value : ");
            scanf("%d", &val);
            insatend(val);
        }

        else if (ch == 5)
        {
            printf("\n Enter the value : ");
            scanf("%d", &val);
            delnode(val);
        }
        

        else if (ch == 6)
        {
            printf("\n Good Bye ");
            break;;
        }

        else
        {
            printf("\n Enter valid choice");
        }
    } while (ch != 6);
}

void create()
{
    struct node *curr;
    int num;

    printf("\nEnter node size : ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        if (first == NULL)
        {
            first = (struct node *)malloc(sizeof(struct node));
            curr = first;
        }
        else
        {
            curr->rptr = (struct node *)malloc(sizeof(struct node));
            curr = curr->rptr;
        }

        printf("Enter the value : ");
        scanf("%d", &curr->data);
        curr->rptr = NULL;
    }
}

void display()
{
    struct node *curr;

    if (first == NULL)
    {
        printf("\n WLink-List is empty");
        return;
    }

    curr = first;

    while (curr != NULL)
    {
        printf("%d-->", curr->data);
        curr = curr->rptr;
    }
}

void insatbeg(int val)
{
    struct node *curr, *new;

    new = (struct node *)malloc(sizeof(struct node));

    new->data = val;
    new->lptr = NULL;

    first -> lptr = new;

    new -> rptr = first;

    first = new;
    
}
        

void insatend(int val)
{
    struct node *curr, *new;

    new = (struct node *)malloc(sizeof(struct node));

    new->data = val;
    new->rptr = NULL;

    if (first == NULL)
    {
        first = new;
        return;
    }

    curr = first;

    while (curr->rptr != NULL)
    {
        curr = curr->rptr;
    }

    curr->rptr = new;
    new->lptr = curr;
}

void delnode(int val)
{
    struct node *curr;

    if (first == NULL)
    {
        printf("\n List is empty");
        return;
    }

    curr = first;


    if (first -> data == val)
    {
       first = first -> rptr;
       free(curr);
       first -> lptr = NULL;
       return;
    }
    
    
    while (curr != NULL && curr -> data != val)
    {
        curr = curr -> rptr;
    }

    if (curr == NULL)
    {
        printf("\n Value does't exsit"); 
        return;
    }
    
    curr -> lptr -> rptr = curr -> rptr;

    if (curr -> rptr != NULL)
    {
        curr -> rptr -> lptr = curr -> lptr;
    }
    
    free(curr);
}

