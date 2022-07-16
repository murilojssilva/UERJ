#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <omp.h>
#include <math.h>
#include "mytime.h"
#include <string.h>


struct pixel {
	int i;
	int j;
	uint8_t valor;
};

struct node {
  struct pixel *value;
  struct node *next;
  int vazia;
};

void push(struct node * head, struct pixel* value) {	
    struct node * current = head;
    while (current->next != NULL) {
		//printf("k %d i %d j %d value: %d\n", current->k,current->value->i, current->value->j, current->value->valor);
        current = current->next;
    }
    /* now we can add a new variable */
    
    current->vazia = 1;
    current->value = value;
	current->next = (struct node*)malloc(sizeof(struct node));
	current->next->value = (struct pixel*)malloc(sizeof(struct pixel));
	current->next->next = NULL;		
}

void print_list(struct node * head) {
    struct node * current = head;
	int count = 0;
    while (current != NULL) {
		count++;
        current = current->next;
    }
    printf("count: %d\n", count);
}

struct pixel * pop(struct node ** head) {
    struct pixel *retval = NULL;
    struct node  *next_node = NULL;

    if (*head == NULL) {
        return NULL;
    }

    next_node = (*head)->next; 
    retval = (*head)->value;
    free(*head);
    *head = next_node;

    return retval;
}

void printm(Mat R, int L, int C)
{
	int i,j;
	for(i=0;i<L;i++)
    {
		for(j=0;j<C;j++)
		{
			printf("%d", R.at<uint8_t>(i,j));
			if (j != C-1)
				printf(" ");
			//printf("%d ", Tg[0].at<uint8_t>(i,j));
		}
		printf("\n");
	}
}

Mat initBWi(Mat BW, int L, int C)
{
	int i,j;
	Mat BWi = Mat::zeros(L,C, CV_8UC1);		
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			BWi.at<uint8_t>(i,j) = BW.at<uint8_t>(i,j);
		}
	}
	return BWi;
}

void procSeeds(int ns, Mat seeds, Mat BWi, Mat *Tg, Mat T, Mat BW, Mat BWsi, int L, int C)
{
	//printf("ns %d\n", ns);
	int i,j;
	for(i=0;i<ns;i++)
	{
		int x,y;		
		int l = seeds.at<uint32_t>(i,0);
		int c = seeds.at<uint32_t>(i,1);
		//printf("L: %d c:%d\n", l , c);
		Mat rec = BWi(Range(l-1, l+1), Range(c-1, c+1));
		Mat viz = Mat::zeros(3,3, CV_8UC1);
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				viz.at<uint8_t>(x,y) = !rec.at<uint8_t>(x,y);
			}
		}
		Mat g = (Mat_<uint8_t>(3,3) << Tg[0].at<uint8_t>(l,c), Tg[1].at<uint8_t>(l,c), Tg[2].at<uint8_t>(l,c), Tg[7].at<uint8_t>(l,c), 0, Tg[3].at<uint8_t>(l,c), Tg[6].at<uint8_t>(l,c),Tg[5].at<uint8_t>(l,c),Tg[4].at<uint8_t>(l,c));
		Mat on = Mat::zeros(3,3, CV_8UC1);
		
		for (x=0;x<3;x++)
		{
			for (y=0;y<3;y++)
			{
				on.at<uint8_t>(x,y) = g.at<uint8_t>(x,y) * viz.at<uint8_t>(x,y);
			}
		}
		
		if (sum(on)[0]>0)
		{
			//BWi(l-1:l+1,c-1:c+1) = rec + on;			
			BWi.at<uint8_t>(l-1,c-1) = rec.at<uint8_t>(0,0) + on.at<uint8_t>(0,0);
			BWi.at<uint8_t>(l-1,c) = rec.at<uint8_t>(0,1) + on.at<uint8_t>(0,1);
			BWi.at<uint8_t>(l-1,c+1) = rec.at<uint8_t>(0,2) + on.at<uint8_t>(0,2);
			
			BWi.at<uint8_t>(l,c-1) = rec.at<uint8_t>(1,0) + on.at<uint8_t>(1,0);
			BWi.at<uint8_t>(l,c) = rec.at<uint8_t>(1,1) + on.at<uint8_t>(1,1);
			BWi.at<uint8_t>(l,c+1) = rec.at<uint8_t>(1,2) + on.at<uint8_t>(1,2);
			
			BWi.at<uint8_t>(l+1,c-1) = rec.at<uint8_t>(2,0) + on.at<uint8_t>(2,0);
			BWi.at<uint8_t>(l+1,c) = rec.at<uint8_t>(2,1) + on.at<uint8_t>(2,1);
			BWi.at<uint8_t>(l+1,c+1) = rec.at<uint8_t>(2,2) + on.at<uint8_t>(2,2);			
		}
	}
	
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			BWi.at<uint8_t>(i,j) = BWi.at<uint8_t>(i,j) * T.at<uint8_t>(i,j);
			BWsi.at<uint8_t>(i,j) = BWi.at<uint8_t>(i,j) - BW.at<uint8_t>(i,j);
		}
	}	
	for(i=0;i<L;i++)
	{
		BWsi.at<uint8_t>(i,0) = 0;
		BWsi.at<uint8_t>(i,C-1) = 0;
	}	
	for(j=0;j<C;j++)
	{
		BWsi.at<uint8_t>(0,j) = 0;
		BWsi.at<uint8_t>(L-1,j) = 0;
	}
}

//BWi = BWi.*T;
//BWsi = BWi - BW;
void procBWsi(Mat BWi, Mat T, Mat BW, Mat BWsi, int L, int C)
{
	int i,j;
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			BWi.at<uint8_t>(i,j) = BWi.at<uint8_t>(i,j) * T.at<uint8_t>(i,j);
			BWsi.at<uint8_t>(i,j) = BWi.at<uint8_t>(i,j) - BW.at<uint8_t>(i,j);
		}
	}
	for(i=0;i<L;i++)
	{
		BWsi.at<uint8_t>(i,0) = 0;
		BWsi.at<uint8_t>(i,C-1) = 0;
	}		
	for(j=0;j<C;j++)
	{
		BWsi.at<uint8_t>(0,j) = 0;
		BWsi.at<uint8_t>(L-1,j) = 0;
	}
}

void procBorda(Mat BWsi, int L, int C)
{
	int i,j;
	for(i=0;i<L;i++)
	{
		BWsi.at<uint8_t>(i,0) = 0;
		BWsi.at<uint8_t>(i,C-1) = 0;
	}		
	for(j=0;j<C;j++)
	{
		BWsi.at<uint8_t>(0,j) = 0;
		BWsi.at<uint8_t>(L-1,j) = 0;
	}
}

Mat procRenewSeeds(Mat BWsi, int L, int C)
{
	int test;
	int count = 0;
	int ns = 0;
	int i,j;
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			if (BWsi.at<uint8_t>(i,j) > 0)
				count++;
		}
	}
	Mat seeds = Mat::zeros(count, 2, CV_32S);
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			if (BWsi.at<uint8_t>(i,j) > 0)
			{ 
				seeds.at<uint32_t>(ns,0) = i;
				seeds.at<uint32_t>(ns,1) = j;
				ns++;
			}
		}
	}
	return seeds;
}

int calcNS(Mat seeds)
{
	return seeds.rows;
}

//J - marker, I - mask
Mat imreconstruct(Mat J, Mat I, int n)
{
	int i,j,k;
	int L = J.rows;
	int C = J.cols;
	
	int test;
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			//pi = i, pj = j
			
			//J(p)
			uint8_t JP = J.at<uint8_t>(i,j);
			//I(p)
			uint8_t IP = I.at<uint8_t>(i,j);
			
			//q's
			uint8_t N0;
			uint8_t N1;
			uint8_t N2;
			uint8_t N3;
			if (i != 0 && j != 0)
				N0 = J.at<uint8_t>(i-1,j-1); //NO if i ou j 0
			if (i != 0)
				N1 = J.at<uint8_t>(i-1,j); //NO if i 0			
			if (i != 0 && j != C-1)
				N2 = J.at<uint8_t>(i-1,j+1); //NO if i 0
			if (j != 0)
				N3 = J.at<uint8_t>(i,j-1); //NO if j 0			
			
			uint8_t max = 0;
			if (JP > max)
				max = JP;
			if ((i != 0 && j != 0) && N0 > max)
				max = N0;
			if ((i != 0) && N1 > max)			
				max = N1;
			if ((i != 0 && j != C-1) && N2 > max)
				max = N2;
			if ((j != 0) && N3 > max)
				max = N3;				
			
		//	if (i == 0 && j == 0)
			//	printf ("max: %d\n", JP);
			//int N4 = J.at<uint8_t>(i,j) * FH[k].at<int>(1,1);
			//int N5 = J.at<uint8_t>(i,j+1) *FH[k].at<int>(1,2);
			//int N6 = J.at<uint8_t>(i+1,j-1) * FH[k].at<int>(2,0);
			//int N7 = J.at<uint8_t>(i+1,j) * FH[k].at<int>(2,1);
			//int N8 = J.at<uint8_t>(i+1,j+1) * FH[k].at<int>(2,2);
			J.at<uint8_t>(i,j) = max < IP ? max : IP;
		}
	}
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->value = (struct pixel*)malloc(sizeof(struct pixel));
	root->next = NULL;
	root->vazia = 0;
	
	for(i=L-1;i>=0;i--)
	{
		for(j=C-1;j>=0;j--)
		{
			struct pixel *jp = (struct pixel*)malloc(sizeof(struct pixel));
			struct pixel *ip = (struct pixel*)malloc(sizeof(struct pixel));
			struct pixel *n4 = (struct pixel*)malloc(sizeof(struct pixel));
			struct pixel *n5 = (struct pixel*)malloc(sizeof(struct pixel));
			struct pixel *n6 = (struct pixel*)malloc(sizeof(struct pixel));
			struct pixel *n7 = (struct pixel*)malloc(sizeof(struct pixel));
			
			int okn4 = j != C-1;
			int okn5 = i != L-1 && j != 0;
			int okn6 = i != L-1;
			int okn7 = i != L-1 && j != C-1;
			
			jp->i = i;
			jp->j = j;
			jp->valor = J.at<uint8_t>(i,j);
			
			ip->i = i;
			ip->j = j;
			ip->valor = I.at<uint8_t>(i,j);
			
			
			if (okn4)
			{
				n4->i = i;
				n4->j = j+1;
				n4->valor = J.at<uint8_t>(i,j+1);
			}
			
			
			if (okn5)
			{
				n5->i = i+1;
				n5->j = j-1;
				n5->valor = J.at<uint8_t>(i+1,j-1);
			}
			
			if (okn6)
			{
				n6->i = i+1;
				n6->j = j;
				n6->valor = J.at<uint8_t>(i+1,j);
			}
			
			if (okn7)
			{
				n7->i = i+1;
				n7->j = j+1;
				n7->valor = J.at<uint8_t>(i+1,j+1);
			}
			
			uint8_t max = 0;
			if (jp->valor > max)
				max = jp->valor;
			if (okn4 && n4->valor > max)
				max = n4->valor;
			if (okn5 && n5->valor > max)
				max = n5->valor;
			if (okn6 && n6->valor > max)
				max = n6->valor;
			if (okn7 && n7->valor > max)
				max = n7->valor;
			
			int test;
			J.at<uint8_t>(i,j) = max < ip->valor ? max : ip->valor;
			
			if (okn4 && J.at<uint8_t>(n4->i,n4->j) < J.at<uint8_t>(i,j) && J.at<uint8_t>(n4->i,n4->j) < I.at<uint8_t>(n4->i,n4->j))
			{
				push(root, jp);
			}else if (okn5 && J.at<uint8_t>(n5->i,n5->j) < J.at<uint8_t>(i,j) && J.at<uint8_t>(n5->i,n5->j) < I.at<uint8_t>(n5->i,n5->j))
			{
				push(root, jp);
			}else if (okn6 && J.at<uint8_t>(n6->i,n6->j) < J.at<uint8_t>(i,j) && J.at<uint8_t>(n6->i,n6->j) < I.at<uint8_t>(n6->i,n6->j))
			{
				push(root, jp);
			}else if (okn7 && J.at<uint8_t>(n7->i,n7->j) < J.at<uint8_t>(i,j) && J.at<uint8_t>(n7->i,n7->j) < I.at<uint8_t>(n7->i,n7->j))
			{
				push(root, jp);
			}
			free(ip);
			free(n4);
			free(n5);
			free(n6);
			free(n7);
		}
	}
	//print_list(root);
	struct pixel *p;
	if (root->vazia == 0)
	{
		printf("vazia\n");
		p = pop(&root);
		p = NULL;
	}
	else	
	{
		p = pop(&root);
	}
	//print_list(root);
	while(p != NULL)
	{
		
	//print_list(root);
	//printf("%d %d %d\n", p->i, p->j, p->valor);
		struct pixel *jp = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *jq;
		struct pixel *ip = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n0 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n1 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n2 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n3 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n4 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n5 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n6 = (struct pixel*)malloc(sizeof(struct pixel));
		struct pixel *n7 = (struct pixel*)malloc(sizeof(struct pixel));
		int i = p->i;
		int j = p->j;
		
		int okn0 = j != 0 && j != 0;
		int okn1 = i != 0;
		int okn2 = i != 0 && j != C-1;
		int okn3 = j != 0;
		int okn4 = j != 0 && i != L-1;
		int okn5 = i != L-1;
		int okn6 = i != L-1 && j != C-1;
		int okn7 = j != C-1;
		
		//J(p)
		jp->i = i;
		jp->j = j;
		jp->valor = J.at<uint8_t>(i,j);
		
		ip->i = i;
		ip->j = j;
		ip->valor = I.at<uint8_t>(i,j);
		
		//q 0
		if (okn0)
		{
			n0->i = i-1;
			n0->j = j-1;
			n0->valor = J.at<uint8_t>(i-1,j-1);	
			if (n0->valor < jp->valor && I.at<uint8_t>(n0->i,n0->j) != n0->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n0->i;
				jq->j = n0->j;
				jq->valor = jp->valor < I.at<uint8_t>(n0->i,n0->j) ? jp->valor : I.at<uint8_t>(n0->i,n0->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}	
		
		//q 1
		if (okn1)
		{
			n1->i = i-1;
			n1->j = j;
			n1->valor = J.at<uint8_t>(i-1,j);	
			if (n1->valor < jp->valor && I.at<uint8_t>(n1->i,n1->j) != n1->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n1->i;
				jq->j = n1->j;
				jq->valor = jp->valor < I.at<uint8_t>(n1->i,n1->j) ? jp->valor : I.at<uint8_t>(n1->i,n1->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		//q 2
		if (okn2)
		{
			n2->i = i-1;
			n2->j = j+1;
			n2->valor = J.at<uint8_t>(i-1,j+1);	
			if (n2->valor < jp->valor && I.at<uint8_t>(n2->i,n2->j) != n2->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n2->i;
				jq->j = n2->j;
				jq->valor = jp->valor < I.at<uint8_t>(n2->i,n2->j) ? jp->valor : I.at<uint8_t>(n2->i,n2->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		if (okn3)
		{
			//q 3
			n3->i = i;
			n3->j = j-1;
			n3->valor = J.at<uint8_t>(i,j-1);	
			if (n3->valor < jp->valor && I.at<uint8_t>(n3->i,n3->j) != n3->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n3->i;
				jq->j = n3->j;
				jq->valor = jp->valor < I.at<uint8_t>(n3->i,n3->j) ? jp->valor : I.at<uint8_t>(n3->i,n3->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		if (okn4)
		{
			//q 4
			n4->i = i+1;
			n4->j = j-1;
			n4->valor = J.at<uint8_t>(i+1,j-1);	
			if (n4->valor < jp->valor && I.at<uint8_t>(n4->i,n4->j) != n4->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n4->i;
				jq->j = n4->j;
				jq->valor = jp->valor < I.at<uint8_t>(n4->i,n4->j) ? jp->valor : I.at<uint8_t>(n4->i,n4->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		if (okn5)
		{
			//q 5
			n5->i = i+1;
			n5->j = j;
			n5->valor = J.at<uint8_t>(i+1,j);	
			if (n5->valor < jp->valor && I.at<uint8_t>(n5->i,n5->j) != n5->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n5->i;
				jq->j = n5->j;
				jq->valor = jp->valor < I.at<uint8_t>(n5->i,n5->j) ? jp->valor : I.at<uint8_t>(n5->i,n5->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		if (okn6)
		{
			//q 6
			n6->i = i+1;
			n6->j = j+1;
			n6->valor = J.at<uint8_t>(i+1,j+1);	
			if (n6->valor < jp->valor && I.at<uint8_t>(n6->i,n6->j) != n6->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n6->i;
				jq->j = n6->j;
				jq->valor = jp->valor < I.at<uint8_t>(n6->i,n6->j) ? jp->valor : I.at<uint8_t>(n6->i,n6->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		if (okn7)
		{
			//q 7
			n7->i = i;
			n7->j = j+1;
			n7->valor = J.at<uint8_t>(i,j+1);	
			if (n7->valor < jp->valor && I.at<uint8_t>(n7->i,n7->j) != n7->valor)
			{
				jq = (struct pixel*)malloc(sizeof(struct pixel));
				jq->i = n7->i;
				jq->j = n7->j;
				jq->valor = jp->valor < I.at<uint8_t>(n7->i,n7->j) ? jp->valor : I.at<uint8_t>(n7->i,n7->j);
				J.at<uint8_t>(jq->i,jq->j) = jq->valor; 
				push(root, jq);
			}
		}
		
		p = pop(&root);
		//print_list(root);
		//printf("i: %d\nj:%d\nval:%d\n", val->i, val->j, val->valor);	
		//print_list(root);
	}
	return J;
}


void reggrow(Mat I, char * dest, int imid, int ti, int td, int tg, int pm, int open)
{
	int i,j,k;
	int L = I.rows;
	int C = I.cols;
	L = L + 4;
	C = C + 4;
	Mat J = Mat::zeros(L,C, CV_8UC1);
	int test;
	
	
	#ifdef PROFILE
		double time;
		tic(&time, TIME_ms);
	#endif
	
	for(i=2;i<L-2;i++)
	{
		for(j=2;j<C-2;j++)
		{
			J.at<uint8_t>(i,j) = I.at<uint8_t>(i-2,j-2);
		}
	}
	//printm(J,L,C);
	
	//I.copyTo(J(Rect(2,2,I.cols,I.rows)));
	
	
	Mat M;
	Mat D;
	Mat DTi;
	
	//Testado.
	Mat Ti = Mat::zeros(L,C, CV_8UC1);	
	for(i=0;i<L;i++)
    {
		for(j=0;j<C;j++)
		{
			Ti.at<uint8_t>(i,j) = (J.at<uint8_t>(i,j) <= ti) * 255;
		}
	}
	
	//Mat Ti = J <= ti;//Mat::zeros(L,C, CV_8UC1);
	//Ti.convertTo(Ti, CV_8UC1, 255);
	
	//Testado
	medianBlur(J, M, pm);	
	
	//Testado
	subtract(M,J,D); 
	
	//Testado
	add(D,Ti,DTi);
	
	//Testado
	Mat T = Mat::zeros(L,C, CV_8UC1);// = DTi >= td;	
	for(i=0;i<L;i++)
    {
		for(j=0;j<C;j++)
		{
			T.at<uint8_t>(i,j) = DTi.at<uint8_t>(i,j) >= td;
		}
	}
	
	Mat FH[8];
	Mat G[8];
	Mat Tg[8];
	
	FH[0] = (Mat_<int>(3,3) << 1,0,0,0,-1,0,0,0,0);	
	FH[1] = (Mat_<int>(3,3) << 0,1,0,0,-1,0,0,0,0);
	FH[2] = (Mat_<int>(3,3) << 0,0,1,0,-1,0,0,0,0);
	FH[3] = (Mat_<int>(3,3) << 0,0,0,0,-1,1,0,0,0);
	FH[4] = (Mat_<int>(3,3) << 0,0,0,0,-1,0,0,0,1);
	FH[5] = (Mat_<int>(3,3) << 0,0,0,0,-1,0,0,1,0);
	FH[6] = (Mat_<int>(3,3) << 0,0,0,0,-1,0,1,0,0);
	FH[7] = (Mat_<int>(3,3) << 0,0,0,1,-1,0,0,0,0);

	for(k=0;k<8;k++)
	{
		G[k] = Mat::zeros(L, C, CV_8UC1);
		for(i=1;i<L-1;i++)
		{
			for(j=1;j<C-1;j++)
			{
				int N0 = J.at<uint8_t>(i-1,j-1) * FH[k].at<int>(0,0);
				int N1 = J.at<uint8_t>(i-1,j) * FH[k].at<int>(0,1);
				int N2 = J.at<uint8_t>(i-1,j+1) * FH[k].at<int>(0,2);
				int N3 = J.at<uint8_t>(i,j-1) * FH[k].at<int>(1,0);
				int N4 = J.at<uint8_t>(i,j) * FH[k].at<int>(1,1);
				int N5 = J.at<uint8_t>(i,j+1) *FH[k].at<int>(1,2);
				int N6 = J.at<uint8_t>(i+1,j-1) * FH[k].at<int>(2,0);
				int N7 = J.at<uint8_t>(i+1,j) * FH[k].at<int>(2,1);
				int N8 = J.at<uint8_t>(i+1,j+1) * FH[k].at<int>(2,2);
				
				//printf("%d,%d - %d, %d, %d, %d, %d, %d, %d, %d, %d\n", i,j,N0,N1,N2,N3,N4,N5,N6,N7,N8);
				int soma = N0 + N1 + N2 + N3 + N4 + N5 + N6 + N7 + N8;
				//printf("i:%d j:%dsoma:%d\n",i,j,soma);
				G[k].at<uint8_t>(i,j) = (soma < 0) ? 0 : ((soma > 255) ? 255 : soma);
			}
		}
	}
	
	//Testado
	for(k=0;k<8;k++)
	{
		Tg[k] = Mat::zeros(L, C, CV_8UC1);
		for(i=0;i<L;i++)
		{
			for(j=0;j<C;j++)
			{
				Tg[k].at<uint8_t>(i,j) = G[k].at<uint8_t>(i,j) <= tg;
			}
		}
	}
	
	
	Mat Start = Mat::zeros(L,C, CV_8UC1);
	if (open == 1)
	{
		Mat Z = Mat::zeros(L,C, CV_8UC1);
		for(i=0;i<L;i++)
		{
			for(j=0;j<C;j++)
			{
				Z.at<uint8_t>(i,j) = J.at<uint8_t>(i,j) == 0;
			}
		}
		Mat X = Mat::zeros(L,C, CV_8UC1);
		X.at<uint8_t>(1,1) = 1;
		for(i=0;i<L;i++)
		{
			for(j=0;j<C;j++)
			{
				X.at<uint8_t>(i,j) = X.at<uint8_t>(i,j) > 0;
			}
		}
		Start = imreconstruct(X,Z,8);
		/*
		for(i=0;i<L;i++)
		{
			for(j=0;j<C;j++)
			{
				printf("%d", Z.at<uint8_t>(i,j));
				if (j != C-1)
					printf(" ");
				//printf("%d ", Tg[0].at<uint8_t>(i,j));
			}
			printf("\n");
		}*/
	}
	else
	{
		//Testado.
		//%Start = J <= ti;
		for(i=0;i<L;i++)
		{
			for(j=0;j<C;j++)
			{
				Start.at<uint8_t>(i,j) = J.at<uint8_t>(i,j) == 0;//<= ti;
			}
		}
	}
	Mat BW0;
	Mat element = getStructuringElement( MORPH_RECT,Size(3,3));
	//printf("r %d l %d", element.rows, element.cols);
	for(i = 0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			element.at<uint8_t>(i,j) = 1;
		}
	}
	//X = strel([1 1 1; 1 1 1; 1 1 1]);
	
	//Testado
	erode(Start, BW0, element);	
	//Marreta
	for(i=0;i<L;i++)
	{
		BW0.at<uint8_t>(i,0) = 0;
		BW0.at<uint8_t>(i,C-1) = 0;
	}
	for(j=0;j<C;j++)
	{
		BW0.at<uint8_t>(0,j) = 0;
		BW0.at<uint8_t>(L-1,j) = 0;
	}
	
	Mat BWsi = Start - BW0;
	//Marreta
	for(i=0;i<L;i++)
	{
		BWsi.at<uint8_t>(i,0) = 0;
		BWsi.at<uint8_t>(i,C-1) = 0;
	}
	for(j=0;j<C;j++)
	{
		BWsi.at<uint8_t>(0,j) = 0;
		BWsi.at<uint8_t>(L-1,j) = 0;
	}
	
	//printm(BWsi,L,C);
	
	
	//SPLIT SEEDS AROUNDS THREADS.
	
	int count = 0;	
	for(j=0;j<C;j++)
	{
		for(i=0;i<L;i++)
		{
			if (BWsi.at<uint8_t>(i,j) > 0)
				count++;
		}
	}
	Mat seeds = Mat::zeros(count, 2, CV_32S);
	int ns = 0;	
	for(j=0;j<C;j++)
	{
		for(i=0;i<L;i++)
		{
			if (BWsi.at<uint8_t>(i,j) > 0)
			{
				seeds.at<uint32_t>(ns,0) = i;
				seeds.at<uint32_t>(ns,1) = j;
				ns++;
			}
		}
	}
	
	for(i = 0;i<count;i++)
	{
		//printf("%d %d\n", seeds.at<uint8_t>(i,0), seeds.at<uint8_t>(i,1));
	}
	Mat BW = BW0;
	/*
	for(i=0;i<L;i++)
    {
		for(j=0;j<C;j++)
		{
			printf("%d", BW0.at<uint8_t>(i,j));
			if (j != C-1)
				printf(" ");
			//printf("%d ", Tg[0].at<uint8_t>(i,j));
		}
		printf("\n");
	}*/	
	//printf("teste - ns %d", ns);
		//	scanf("%d",&test);	
		/*
	printf("%d\n", ns);
	#pragma omp parallel
	{
		int qdT = omp_get_num_threads();
		int rank = omp_get_thread_num();
		int chunk = (ns / qdT) + (rank == qdT-1) * (ns % qdT);		
		int nsThread = chunk;
		printf("RANK %d chunk %d\n", rank, chunk);
	}*/
	
	#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Preproc seeds: %lf\n",time);		
		tic(&time, TIME_ms);
	#endif
	
	while (ns > 0)
	{
		/*
		#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Proc %d seeds\n",ns);		
		tic(&time, TIME_ms);
		#endif */
		
		Mat BWi = initBWi(BW, L, C);
		
		/*	
		#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Proc %d seeds - BWi cpy: %lf\n",ns ,time);		
		tic(&time, TIME_ms);
		#endif
		* */
		
		procSeeds(ns, seeds, BWi, Tg, T, BW, BWsi, L, C);
		
		/*
		#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Proc %d seeds - for ns: %lf\n",ns ,time);		
		tic(&time, TIME_ms);
		#endif
		* */

		//procBWsi(BWi, T, BW, BWsi, L, C);
		
		/*
		#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Proc %d seeds for bwi*t /bwsi = bwi - bw: %lf\n",ns ,time);		
		tic(&time, TIME_ms);
		#endif
		* */

		//procBorda(BWsi, L, C);
		
		/*
		#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Proc %d seeds - borda: %lf\n",ns ,time);		
		tic(&time, TIME_ms);
		#endif
		* */
		
		seeds = procRenewSeeds(BWsi, L, C);
		ns = seeds.rows;
		BW = BWi;
		
		/*
		#ifdef PROFILE
		tac(&time,TIME_ms);
		printf("[PROFILE]Proc - create seeds seed: %lf\n", time);		
		tic(&time, TIME_ms);
		#endif
		* */
	}
	

	#ifdef PROFILE
	tac(&time,TIME_ms);
	printf("[PROFILE]Proc - while: %lf\n", time);		
	tic(&time, TIME_ms);
	#endif

	
	
	Mat R = BW(Range(2, L-2), Range(2, C-2));
	R = R > 0;
    //compression_params.push_back(CV_IMWRITE_PXM_BINARY);
    
	for(i=0;i<L-4;i++)
	{
		for(j=0;j<C-4;j++)
		{
			R.at<uint8_t>(i,j) = R.at<uint8_t>(i,j) == 255 ? 0 : 255;
		}
	}
	
	//printm(R, L-4, C-4);

  char fname[500];
  sprintf(fname, "%s_%04d.tif",dest,i);
	imwrite(fname, R);
	
}

int main(int argc, char** argv)
{
    if( argc != 2)
    {
		printf("Argumentos inválidos\n");
		exit(1);
    }
    
    char fname[500];
    int qtd = atoi(argv[1]);
    
    for (i=1; i<=qtd; i++)
    {
        sprintf(fname, "%s_%04d.tif",argv[2],i);
        Mat I = imread(dir->d_name, 0);
        reggrow(I, argv[2], i, 20, 4, 50, 9, 0);
     
    }
    
    return 0;
}