
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DAYS 3
struct activity
{
    char *nday;
    int dday;
    char *desc;
};
typedef struct activity Plan;
Plan *create();
void read(Plan *);
void display(Plan *);

int main()
{
    Plan *cal = NULL;
    cal = create();

    read(cal);
    display(cal);
}

Plan *create()
{
    Plan *t = (Plan *)malloc(sizeof(Plan) * 7);
    if (t == NULL)
    {
        printf("Sufficient memory not allocated\n");
        return 0;
    }
    return t;
}

void read(Plan *p)
{

    int i;
    for (i = 0; i < DAYS; i++)
    {
        p[i].nday = (char *)malloc(9);
        printf("Enter name of the day ");
        scanf(" %s", p[i].nday);
        printf("Enter date of the day ");
        scanf("%d", &(p[i].dday));

        printf("Enter description of the activity ");
        p[i].desc = (char *)malloc(400);
        scanf(" %[^\n]", p[i].desc);
        p[i].desc = (char *)realloc(p[i].desc, strlen(p[i].desc) + 1);
    }
}

void display(Plan *p)
{
    int i;
    printf("**** Activity description for %d days ****\n", DAYS);
    for (i = 0; i < DAYS; i++)
    {
        printf("\nName of the day : %s", p[i].nday);
        printf("\nDate of the day : %d", p[i].dday);
        printf("\nActivity description %s: ", p[i].desc);
    }
}

// Program 2

#include <stdio.h>
#include <string.h>

int slen(char *);
void replace(char *, char *, char *, char *);

int main()
{
    char T[40] = {"bapqrababbzzba"};
    char P[20] = {"ba"}, REP[20] = {"BA"}, FIN[50];

    void replace(char *, char *, char *, char *);
    replace(T, P, REP, FIN);

    printf("Output %s\n", FIN);
}

int slen(char *s)
{
    int len = 0;
    for (; s[len] != '\0'; len++)
        ;
    return len;
}
void replace(char *T, char *P, char *REP, char *FIN)
{
    int k = 0, s = slen(T), r = slen(P), e, q = 0, z;
    for (; k < s;)
    {
        for (e = 0; e < r; e++)
            if (P[e] != T[k + e])
                break;

        if (e == r)
        {

            // printf("Substring found at %d \n",k);
            for (z = 0; z < strlen(REP); z++)
                FIN[q++] = REP[z];
            k = k + r;
        }
        else

            FIN[q++] = T[k++];
    }
    FIN[q] = '\0';
}

// Program 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELE 4

void push(int[], int *);
void pop(int[], int *);
void display(int[], int *);
void palin();
void status(int *, int);

int main()
{
    int ch, top = -1;
    int s[MAX_ELE];
    for (;;)
    {
        printf("1:push\n2:pop\n3:display\n4:Status\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(s, &top);
            break;
        case 2:
            pop(s, &top);
            break;
        case 3:
            display(s, &top);
            break;
        case 4:
            status(s, top);
            break;
        default:
            exit(0);
        }
    }
}

void status(int *s, int top)
{

    int used;
    if (top == -1)
        used = 0;
    else
        used = top + 1;

    printf("%d locations of the stack are used up\n", used);
    printf("%d locations of the stack are free\n", MAX_ELE - used);
}

void display(int s[], int *top)
{
    int i;
    if ((*top) == -1)
        printf("stack empty\n");
    else
    {
        printf("stack elements are\n");
        printf("TOS is: ");
        for (i = (*top); i >= 0; i--)
            printf("%d\n", s[i]);
    }
}

void push(int *s, int *top)
{
    int ele;
    if ((*top) == MAX_ELE - 1)
    {
        printf("stack overflow\n");
        return;
    }
    (*top)++;
    printf("enter the element\n");
    scanf("%d", &ele);
    s[*top] = ele;
}

void pop(int s[], int *top)
{
    if ((*top) == -1)
        printf("stack underflow\n");
    else
    {
        printf("element popped is\n");
        printf("%d\n", s[*top]);
        (*top)--;
    }
}

// Program 4

#include <stdio.h>
#include <string.h>
#define MAX_ELE 30
int f(char s)
{
    switch (s)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}
int g(char s)
{
    switch (s)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int main()
{
    char c, s[MAX_ELE] = {'#'};
    char inf[MAX_ELE] = {"a/b-(c+d)"};

    char pf[MAX_ELE];
    int top = 0, i, j = 0; // top = 0 because '#' is already stored in stack
    // printf("enter the infix expression\n");
    // scanf("%s",inf);
    for (i = 0; i < strlen(inf); i++)
    {
        c = inf[i];
        while (f(s[top]) > g(c))
        {
            pf[j] = s[top];
            j++;
            top--;
        }
        if (f(s[top]) != g(c))
            s[++top] = c;
        else
            top--;
    }
    for (; s[top] != '#'; top--)
        pf[j++] = s[top];
    pf[j] = '\0';
    printf("the postfix expression:%s\n", pf);
}

// Program 5

#include <stdio.h>
#include <string.h> // for strlen function
#include <math.h>   // for pow function
#include <ctype.h>  // for isdigit function
double compute(char symbol, double op1, double op2)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '$':
    case '^':
        return pow(op1, op2);
    }
}

int main()
{
    char postfix[20] = {"56+437-*/"}, symbol;
    double st[20], op1, op2;
    int top = -1, i;

    // printf("Enter a valid postfix expression\n");
    // scanf("%s",postfix);
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
            st[++top] = postfix[i] - '0';
        else
        {
            op2 = st[top--];
            op1 = st[top--];
            st[++top] = compute(postfix[i], op1, op2);
        }
    }

    printf("Result is %lf\n", st[top--]);
}

// Program 5 b

#include <stdio.h>
void hanoi(int n, char S, char T, char D)

{
    if (n == 0)
        return;

    hanoi(n - 1, S, D, T);
    printf("Move disc %d from %c to %c\n", n, S, D);
    hanoi(n - 1, T, S, D);
}

int main()
{
    int n;
    printf("Enter number of discs\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}

// Program 6

#include <stdio.h>
#include <stdlib.h>
#define Max 3
void insert(char[], int *, int *);
void del(char[], int *, int *);
void display(char[], int, int);
int main()
{
    char q[Max];
    int r = -1, f = 0, cnt = 0;
    int ch;

    while (1)
    {
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(q, &r, &cnt);
            break;
        case 2:
            del(q, &f, &cnt);
            break;
        case 3:
            display(q, f, cnt);
            break;
        default:
            exit(0);
        }
    }
}

void insert(char q[], int *r, int *cnt)
{
    char ele;
    if ((*cnt) == Max)
    {
        printf("C Q overflow\n");
        return;
    }
    (*r) = ((*r) + 1) % Max;
    printf("enter the ele\n");
    scanf(" %c", &ele);
    q[*r] = ele;
    (*cnt)++;
}

void del(char q[], int *f, int *cnt)
{
    if ((*cnt) == 0)
    {
        printf("C Queue is empty\n");
        return;
    }

    printf("Element deleted from circular queue is %c\n", q[(*f)]);
    (*f) = ((*f) + 1) % Max;
    (*cnt)--;
}

void display(char q[], int f, int cnt)
{
    int i, j;
    if (cnt == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue contents are\n");

    for (i = f, j = 0; j < cnt; j++)
    {
        printf("%d : %c\n", i, q[i]);
        i = (i + 1) % Max;
    }
}

// Program 7

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char USN[10], name[20], branch[10];
    int sem;
    long int ph;
    struct node *link;
} nd;

nd *create(nd *);
void status(nd *);
nd *ins_front(nd *);
nd *ins_rear(nd *);
nd *del_front(nd *);
nd *del_rear(nd *);
void display(nd *);

int main()
{
    nd *first = NULL;
    int ch;
    for (;;)
    {
        printf("1. Create N students\n2. Status of SLL\n");
        printf("3. Insert front\n4. Insert rear\n5. Delete front\n");
        printf("6. Delete rear\n7. Display\n8. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = create(first);
            break;
        case 2:
            status(first);
            break;

        case 3:
            first = ins_front(first);
            break;
        case 4:
            first = ins_rear(first);
            break;
        case 5:
            first = del_front(first);
            break;
        case 6:
            first = del_rear(first);
            break;
        case 7:
            display(first);
            break;
        case 8:
            exit(0);
        }
    }
}

nd *del_front(nd *f)
{
    nd *t;
    if (f == NULL)
    {
        printf("SLL is empty\n");
        return NULL;
    }
    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%d\t%ld\n", (f->USN), (f->name), (f->branch), (f->sem), (f->ph));

    t = f->link;
    free(f);
    return t;
}

nd *del_rear(nd *f)
{
    nd *t, *p;
    if (f == NULL)
    {
        printf("SLL is empty\n");
        return NULL;
    }

    for (p = NULL, t = f; t->link != NULL; p = t, t = t->link)
        ;
    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%d\t%ld\n", (t->USN), (t->name), (t->branch), (t->sem), (t->ph));
    free(t);

    if (p != NULL)
    {
        p->link = NULL;
        return f;
    }
    else
        return NULL;
}

nd *ins_rear(nd *f)
{
    nd *p = f;
    nd *t = (nd *)malloc(sizeof(nd));
    t->link = NULL;
    printf("Enter USN, Name, Branch, Sem and Phone of the student:\n");
    scanf("%s%s%s%d%ld", (t->USN), (t->name), (t->branch), &(t->sem), &(t->ph));

    if (f == NULL)
        return t;

    for (; p->link != NULL; p = p->link)
        ;
    p->link = t;
    return f;
}

void status(nd *f)
{
    int cnt = 0;
    if (f == NULL)
    {
        printf("SLL is empty\n");
        return;
    }

    for (; f != NULL; f = f->link, cnt++)
        ;
    printf("Number of nodes in SLL is %d\n", cnt);
}

nd *create(nd *f)
{
    int n, i;
    printf("Enter value for n\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        f = ins_front(f);
    return f;
}
nd *ins_front(nd *f)
{
    nd *t = (nd *)malloc(sizeof(nd));
    printf("Enter USN, Name, Branch, Sem and Phone of the student:\n");
    scanf("%s%s%s%d%ld", (t->USN), (t->name), (t->branch), &(t->sem), &(t->ph));

    t->link = f;
    return t;
}

void display(nd *f)
{
    if (f == NULL)
    {
        printf("Contents of SLL are empty\n");
        return;
    }
    printf("Contents of the list\n");
    while (f != NULL)
    {
        printf("%s\t%s\t%s\t%d\t%ld\n", (f->USN), (f->name), (f->branch), (f->sem), (f->ph));
        f = f->link;
    }
}

// Program 8

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char SSN[10], name[20], dept[30], desig[30];
    float sal;
    long int ph;
    struct node *llink, *rlink;
} nd;

nd *create(nd *);
void status(nd *);
nd *ins_front(nd *);
nd *ins_rear(nd *);
nd *del_front(nd *);
nd *del_rear(nd *);
void display(nd *);

int main()
{
    nd *first = NULL;
    int ch;
    for (;;)
    {
        printf("1. Create N students\n2. Status of DLL\n");
        printf("3. Insert front\n4. Insert rear\n5. Delete front\n");
        printf("6. Delete rear\n7. Display\n8. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = create(first);
            break;
        case 2:
            status(first);
            break;
        case 3:
            first = ins_front(first);
            break;
        case 4:
            first = ins_rear(first);
            break;
        case 5:
            first = del_front(first);
            break;
        case 6:
            first = del_rear(first);
            break;
        case 7:
            display(first);
            break;
        case 8:
            exit(0);
        }
    }
}

nd *del_front(nd *f)
{
    nd *t;
    if (f == NULL)
    {
        printf("DLL is empty\n");
        return NULL;
    }

    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%s\t%f\t%ld\n", f->SSN, f->name, f->dept, f->desig, f->sal, f->ph);
    t = f->rlink;
    if (t)
        t->llink = NULL;
    free(f);
    return t;
}
nd *del_rear(nd *f)
{
    nd *t, *p;
    if (f == NULL)
    {
        printf("DLL is empty\n");
        return NULL;
    }

    for (p = NULL, t = f; t->rlink != NULL; p = t, t = t->rlink)
        ;

    printf("Information to be deleted is...\n");
    printf("%s\t%s\t%s\t%s\t%f\t%ld\n", t->SSN, t->name, t->dept, t->desig, f->sal, t->ph);
    free(t);
    if (p != NULL)
    {
        p->rlink = NULL;
        return f;
    }

    else
        return NULL;
}

nd *ins_rear(nd *f)
{
    float sal;
    nd *p = f;
    nd *t = (nd *)malloc(sizeof(nd));
    t->rlink = t->llink = NULL;

    printf("Enter SSN, Name, Dept, Desig, Salary, Phone of the Employee:\n");
    scanf("%s%s%s%s%f%ld", t->SSN, t->name, t->dept, t->desig, &(t->sal), &(t - ph));

    if (f == NULL)
        return t;

    for (; p->rlink != NULL; p = p->rlink)
        ;
    p->rlink = t;
    t->llink = p;

    return f;
}
void status(nd *f)
{
    int cnt = 0;
    if (f == NULL)
    {
        printf("DLL is empty\n");
        return;
    }

    for (; f != NULL; f = f->rlink, cnt++)
        ;
    printf("Number of nodes in SLL is %d\n", cnt);
}

nd *create(nd *f)
{
    int n, i;
    printf("Enter value for n\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        f = ins_rear(f);
    return f;
}
nd *ins_front(nd *f)
{
    float sal;
    nd *t = (nd *)malloc(sizeof(nd));
    t->rlink = t->llink = NULL;
    printf("Enter SSN, Name, Dept, Desig, Salary, Phone of the Employee:\n");
    scanf("%s%s%s%s%f%ld", t->SSN, t->name, t->dept, t->desig, &(t->sal), &(t->ph));

    t->sal = sal;

    t->rlink = f;
    if (f != NULL)
        f->llink = t;
    return t;
}

void display(nd *f)
{
    if (f == NULL)
    {
        printf("Contents of DLL are empty\n");
        return;
    }
    printf("Contents of the list from FIRST -> LAST\n");
    while (f->rlink != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%f\t%ld\n", f->SSN, f->name, f->dept, f->desig, f->sal, f->ph);
        f = f->rlink;
    }
    printf("%s\t%s\t%s\t%s\t%f\t%ld\n", f->SSN, f->name, f->dept, f->desig, f->sal, f->ph);
    printf("Contents of the list from LAST -> FIRST \n");
    while (f != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%f\t%ld\n", f->SSN, f->name, f->dept, f->desig, f->sal, f->ph);
        f = f->llink;
    }
}

// Program 9

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct term
{
    int coef, xexp, yexp, zexp;
    struct term *link;
};
typedef struct term tm;

void create(tm *);
void display(tm *);
void evaluate(tm *);
void add(tm *, tm *, tm *);
int main()
{
    tm p1 = {.link = &p1}, p2 = {.link = &p2}, p3 = {.link = &p3};
    int ch;
    while (1)
    {
        printf("1. Evaluate\n2. Polynomial addition\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (p1.link != &p1)
                p1.link = &p1;
            create(&p1);
            printf("Terms in polynomial are...\n");
            display(&p1);
            evaluate(&p1);
            break;
        case 2:
            if (p1.link != &p1)
                p1.link = &p1;
            if (p2.link != &p2)
                p2.link = &p2;
            if (p3.link != &p3)
                p3.link = &p3;
            create(&p1);
            create(&p2);
            printf("Terms in poly1 are...\n");
            display(&p1);
            printf("Terms in poly2 are...\n");
            display(&p2);
            add(&p1, &p2, &p3);
            printf("Resultant polynomial...\n");
            display(&p3);
            break;
        case 3:
            return 0;
        }
    }
}

int compare(tm *p, tm *q)
{
    if ((p->xexp == q->xexp) && (p->yexp == q->yexp) && (p->zexp == q - > zexp))
        return 1;
    return 0;
}

void attach(int s, tm *p, tm *r)
{
    tm *t = (tm *)malloc(sizeof(tm));
    t->coef = (s != 0) ? s : p->coef;
    t->xexp = p->xexp;
    t->yexp = p->yexp;
    t->zexp = p->zexp;
    t->link = r->link;
    r->link = t;
}
void delete(tm *p, tm *tp)
{
    tm *prev = p, *next = p->link;
    while (next != tp)
    {
        prev = next;
        next = next->link;
    }

    prev->link = next->link;
}

void add(tm *p, tm *q, tm *r)
{
    int val;
    tm *t = (tm *)malloc(sizeof(tm));
    tm *tp = p->link, *tq, *tr = NULL;
    while (tp != p)
    {
        tq = q->link;
        while (tq != q)
        {

            val = compare(tp, tq);

            if (val)
                break;
            tq = tq->link;
        }
        switch (val)
        {
        case 0:
            attach(0, tp, r);
            tp = tp->link;
            delete (p, tp);
            break;
        case 1:
            val = tp->coef + tq->coef;
            attach(val, tp, r);
            delete (p, tp);
            delete (q, tq);
            tp = tp->link;
            tq = tq->link;
            break;
        }
    }

    tq = q->link;
    while (tq != q)
    {
        attach(0, tq, r);
        tq = tq->link;
    }
}

void evaluate(tm *p)
{
    int x, y, z, res = 0;
    tm *t;
    printf("Enter value of x,y and z\n");
    scanf("%d%d%d", &x, &y, &z);

    for (t = p->link; t != p; t = t->link)
        res = res + t->coef * pow(x, t->xexp) * pow(y, t->yexp) * pow(z, t->zexp);
    printf("Evaluation of polynomial is %d\n", res);
}
void display(tm *p)
{
    tm *t;
    if (p->link == p)
    {
        printf("SCLL is empty\n");
        return;
    }
    for (t = p->link; t != p; t = t->link)
        printf("(%dx^%dy^%dz^%d) +", t->coef, t->xexp, t->yexp, t->zexp);
    printf("\n");
}

void create(tm *p)
{
    int n, i;
    tm *t;
    printf("Enter number of terms\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        t = (tm *)malloc(sizeof(tm));

        printf("Enter coef, xexp, yexp and zexp of the term\n");
        scanf("%d%d%d%d", &(t->coef), &(t->xexp), &(t->yexp), &(t->zexp));

        t->link = p->link;
        p->link = t;
    }
}

// Program 10

#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree *rlink, *llink;
} TNODE;
TNODE *getnode();
TNODE *insert(TNODE *root);
void inorder(TNODE *root);
void preorder(TNODE *root);
void postorder(TNODE *root);
int search(TNODE *root, int key);
void main()
{

    for (;;)
        TNODE *root = NULL;
    int choice, ele, key, flag;

    {
        printf("Enter\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
            }
            break;

            printf("The contents are:\n");
            inorder(root);

        case 3:
            if (root == NULL)
                printf("Tree is empty\n");

            else
            {
            }
            break;

            printf("The contents are:\n");
            preorder(root);

        case 4:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
            }
            break;

            printf("The contents are:\n");
            postorder(root);

        case 5:
            printf("Enter the node to be searched:\n");
            scanf("%d", &key);
            flag = search(root, key);
            if (flag == -1)
                printf("Unsuccessful search!!!\n");
            else
                break;

            printf("Successful search!!!\n");

        case 6:
            exit(0);
        }
    }
}
TNODE *getnode()
{
    TNODE *temp = (TNODE *)malloc(sizeof(TNODE));
    if (temp == NULL)
    {
        printf("Out of memory!!!\n");
        return NULL;
    }
    return temp;
}
TNODE *insert(TNODE *root)
{
    int n, ele, i, flag;
    TNODE *temp, *prev;
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element to be inserted:\n");
        scanf("%d", &ele);
        TNODE *newN = getnode();
        newN->data = ele;
        newN->rlink = newN->llink = NULL;
        if (root == NULL)
        {
            root = newN;
            continue;
        }
        prev = root;
        temp = root;
        flag = 0;
        while (temp != NULL)
        {
            prev = temp;
            if (ele == temp->data)
            {
                printf("Redundant data\n");
                flag = 1;
                break;
            }
            if (ele < temp->data)
                temp = temp->llink;
            else
                temp = temp->rlink;
        }
        if (flag == 1)
            continue;
        if (ele < prev->data)

            prev->llink = newN;
        else
            prev->rlink = newN;
    } // end of for
    return root;
}
void inorder(TNODE *root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d\n", root->data);
        inorder(root->rlink);
    }
}
void preorder(TNODE *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->data);

        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(TNODE *root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n", root->data);
    }
}
int search(TNODE *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
            return key;
        if (key < root->data)
            return search(root->llink, key);
        return search(root->rlink, key);
    }
    return -1;
}