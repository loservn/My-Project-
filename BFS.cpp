#include "fstream"
#include <cstring>
#include <queue>

using namespace std;
#define Max 100

struct Street
{
    int num1;
    int num2;
    char name[255];
};

struct MyGraph
{
	int n, m;
	int Start;
	int Goal;
	Street Arr[Max];
	int A[Max][Max];
	int pre[Max];
};

bool inputGraph(MyGraph &g)
{
	FILE* f;
	f = fopen("input.txt", "rt");
    if(f==NULL)
    {
        printf("Khong mo duoc File!\n");
        return false;
    }
	fscanf(f,"%d %d %d %d", &g.Start, &g.Goal, &g.n, &g.m);
	for(int i = 0;i < g.m ;i++)
	{
	    fscanf(f,"%d %d %[^\n\r]s", &g.Arr[i].num1, &g.Arr[i].num2, &g.Arr[i].name);
	}
	fclose(f);
	
	for(int i = 0;i < g.m ;i++)
	{
		
		g.Arr[i].name[0]=toupper(g.Arr[i].name[0]);
		for(int j = 1; g.Arr[i].name[j] ;j++)
			{
				g.Arr[i].name[j]=tolower(g.Arr[i].name[j]);	
	
				while (g.Arr[i].name[j] == g.Arr[i].name[j+1] && g.Arr[i].name[j]==' ')
					for(int k=j;g.Arr[i].name[k];k++)	  
						g.Arr[i].name[k] = g.Arr[i].name[k+1]; 				 }
		for(int j = 1; g.Arr[i].name[j] ;j++)
		if (g.Arr[i].name[j] == ' ')
			g.Arr[i].name[j+1] = toupper(g.Arr[i].name[j+1]);
				
		printf("%d %d %s\n",g.Arr[i].num1,g.Arr[i].num2,g.Arr[i].name);   	
			}
	
	return true;
}

bool outputGraph(MyGraph g)
{
	
    printf("So dinh: %d\n", g.n );
    printf("So canh: %d\n", g.m );
    printf("diem dau: %d\n",g.Start);
    printf("diem cuoi: %d\n",g.Goal);
    for(int i=0;i<g.n;i++)
    {
        for(int j=0;j<g.n;j++)
        {
            printf("%d ",g.A[i][j]);
        }
        printf("\n");
    }
    return true;
}

void BFS(MyGraph &g)
{

    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            g.A[i][j] = 0;
        }
    }
    for (int k = 0; k < g.m; k++)
    {
        int h = g.Arr[k].num1;
        int t = g.Arr[k].num2;
        g.A[h][t] = 1;
        g.A[t][h] = 1;
    }
    queue <int> q;
    q.push(g.Start);
    for(int a = 0; a < g.n; a++)
    {
        g.pre[a] = -1;
    }
    
    do
    {
        int v = q.front();
        q.pop();
        for(int b = 0; b < g.n; b++)
        {
            if(g.A[v][b] && g.pre[b] == -1 && b != g.Start)
            {
                q.push(b);
                g.pre[b] = v;
                
            }
        }
    } while(!q.empty());

}

void PrintPath(MyGraph g)
{
    int temp[23];
    int i = g.Goal,count=0,m=0,j;
    
    for (int k = g.Goal;k>-1;k=g.pre[k])
    for(  j = 0; j<g.m;j++){
    	
    	if ((g.Arr[j].num1 == k && g.Arr[j].num2 == g.pre[k]) || (g.Arr[j].num2 == k && g.Arr[j].num1 == g.pre[k]) )
    	{
    		temp[m]=j;
    		m++;
    		}	
    }
    printf ("\n%d\n",m);
    for ( int t=m-1; t>-1; t--)
    	printf("%s, ",g.Arr[temp[t]].name,t);
    	
}

int main()
{
    MyGraph g;
    inputGraph(g);
    BFS(g);
    outputGraph(g);
    PrintPath(g);
}
