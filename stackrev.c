#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct
{
    int akhir;//index terakhir
    int size;//array length
    char isi[100];//isi stack
}
Stack;//tipe data stack

//prototype fungsi
void push(Stack *x, char y);
char pop(Stack *x);

int main(void)
{
    Stack stack;//deklarasi stack
    stack.akhir = -1;//deafult condition
    stack.size = 100;//deklarasi array length
    Stack *stek = &stack;//membuat pointer sebagai argumen fungsi

    Stack ygDiPop;
    ygDiPop.akhir = -1;
    ygDiPop.size = 100;
    Stack *popPtr = &ygDiPop;
    char num[] = {'0','1','2','3','4','5','6','7','8','9'};
    
    char* str = "((7*2)+(5-3))";//input

    for(int i = 0; i < strlen(str); ++i)
    {
        printf("%c", str[i]);//menampilkan input soal
    }printf("\n");

    for(int i  = 0; i < strlen(str); ++i)
    {
        push(stek, str[i]);//push input ke dalam stack
    
        if(str[i] == ')')
        {
            ygDiPop.akhir = -1;
            printf("\n");
            char awal = pop(stek);//pop kurung tutup ')'
            push(popPtr, awal);
            int hasil;
            int b = pop(stek) - '0';
            char bChar = b + '0';
            push(popPtr, bChar);
            int bAsli = b;
            for(int j = 0; j < 10; ++j)
            {
                if(stack.isi[stack.akhir] == num[j])
                {
                    int b2  = (pop(stek) - '0') * 10;
                    char b2Char = b2/10 + '0';
                    push(popPtr, b2Char);
                    b += b2;
                }
            }
            char operasi = pop(stek);//pop lambang operasi aritmatika
            push(popPtr, operasi);
            int a = pop(stek) - '0';
            char aChar = a + '0';
            push(popPtr, aChar);
            int aAsli = a;
            for(int j = 0; j < 10; ++j)
            {
                if(stack.isi[stack.akhir] == num[j])
                {
                    int a2  = (pop(stek) - '0') * 10;
                    char a2Char = a2/10 + '0';
                    push(popPtr, a2Char);
                    a += a2;
                }
            }
            switch(operasi)
            {
                case '*' : hasil = a*b; break;
                case '/' : hasil = a/b; break;
                case '+' : hasil = a+b; break;
                case '-' : hasil = a-b; break;
            }
            char akhir = pop(stek);//pop kurung buka '('
            push(popPtr, akhir);
            if(b > 9 && a > 9)
                printf("Evaluasi nilai %d %c %d: %d\n", a,operasi,b,hasil);
            else if(a > 9)
                printf("Evaluasi nilai %d %c %d: %d\n", a,operasi,bAsli,hasil);
            else if(b > 9)
                printf("Evaluasi nilai %d %c %d: %d\n", aAsli,operasi,b,hasil);
            else
                printf("Evaluasi nilai %d %c %d: %d\n", aAsli,operasi,bAsli,hasil);
            if(hasil > 9)
            {
                int truHasil = hasil / 10;
                char ygDipush2 = truHasil + '0';//convert int ke char
                push(stek, ygDipush2);//push digit pertama hasil
                hasil %= 10;
            }
            char ygDiPush = hasil + '0';

            push(stek, ygDiPush);//push digit kedua hasil
        }
    }
}

void push(Stack *x, char y)
{
    if(x->akhir != x->size)
    {
        x->akhir++;
        x->isi[x->akhir] = y;
    }

    for(int i = 0; i < x->akhir+1; ++i)
    {
        printf("%c", x->isi[i]);
    }
    printf("\n");
}

char pop(Stack *x)
{
    if(x->akhir >= 0)
    {
        x->akhir--;
        return(x->isi[x->akhir+1]);
    }
    return 0;
}