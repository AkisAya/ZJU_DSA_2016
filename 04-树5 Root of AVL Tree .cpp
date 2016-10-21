#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct AVLNode* AVLTree;

struct AVLNode{
    ElementType Data; /* ������� */
    AVLTree Left;     /* ָ�������� */
    AVLTree Right;    /* ָ�������� */
    int Height;       /* ���� */
};
 
int Max ( int a, int b )
{
    return a > b ? a : b;
}

int GetHeight(AVLTree T) {
	int HL, HR, MaxH;
	
	if (T) {
		HL = GetHeight(T->Left);
		HR = GetHeight(T->Right);
		MaxH = Max(HL, HR);
		return (MaxH + 1);
	} else return 0;
}

AVLTree SingleLeftRotation ( AVLTree A ){ 
	/* ע�⣺A������һ�����ӽ��B */
	/* ��A��B������������A��B�ĸ߶ȣ������µĸ����B */     
 
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
  
    return B;
}

AVLTree SingleRightRotation (AVLTree A) {
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	
	return B;
}
 
AVLTree DoubleLeftRightRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
  /* ��A��B��C�����ε����������µĸ����C */
     
    /* ��B��C���ҵ�����C������ */
    A->Left = SingleRightRotation(A->Left);
    /* ��A��C��������C������ */
    return SingleLeftRotation(A);
}
 
AVLTree DoubleRightLeftRotation ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C */
  /* ��A��B��C�����ε����������µĸ����C */
     
    /* ��B��C��������C������ */
    A->Right = SingleLeftRotation(A->Right);
    /* ��A��C��������C������ */
    return SingleRightRotation(A);
}
 
AVLTree Insert( AVLTree T, ElementType X )
{ /* ��X����AVL��T�У����ҷ��ص������AVL�� */
    if ( !T ) { /* ��������������½�����һ�������� */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } /* if (�������) ���� */
 
    else if ( X < T->Data ) {
        /* ����T�������� */
        T->Left = Insert( T->Left, X);
        /* �����Ҫ���� */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )
            if ( X < T->Left->Data ) 
               T = SingleLeftRotation(T);      /* ���� */
            else 
               T = DoubleLeftRightRotation(T); /* ��-��˫�� */
    } /* else if (����������) ���� */
     
    else if ( X > T->Data ) {
        /* ����T�������� */
        T->Right = Insert( T->Right, X );
        /* �����Ҫ���� */
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 )
            if ( X > T->Right->Data ) 
               T = SingleRightRotation(T);     /* �ҵ��� */
            else 
               T = DoubleRightLeftRotation(T); /* ��-��˫�� */
    } /* else if (����������) ���� */
 
    /* else X == T->Data��������� */
 
    /* �����˸������� */
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
     
    return T;
}

int main() {
	int N, data;
	AVLTree A = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		A = Insert(A, data);
	} 
	printf("%d", A->Data); 
	
	return 0;
}
